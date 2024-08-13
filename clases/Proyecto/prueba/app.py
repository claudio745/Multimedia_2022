import os
import json
from flask import Flask, render_template, request, url_for


app = Flask(__name__)

# Ruta para la página principal
@app.route('/')
def index():
    return render_template('index.html')

# Ruta para la página de Top Juegos
@app.route('/top_juegos/')
def top_juegos():
    json_path = os.path.join(app.root_path, 'static', 'data', 'juegos.json')
    with open(json_path, 'r', encoding='utf-8') as json_file:
        data = json.load(json_file)
    
    # Filtrar juegos que tienen todas las propiedades definidas
    juegos = [juego for juego in data if all(key in juego for key in ['Nombre del juego', 'Desarrollador', 'Editor', 'Cantidad de reseñas', 'Fecha de lanzamiento', 'Precio'])]

    return render_template('top_juegos.html', juegos=juegos)

# Ruta para manejar la búsqueda y filtrado de juegos
@app.route('/buscar_juegos/')
def buscar_juegos():
    query = request.args.get('query', '')
    orden = request.args.get('orden', 'asc')  # Por defecto, ordenar de menor a mayor
    
    json_path = os.path.join(app.root_path, 'static', 'data', 'juegos.json')
    with open(json_path, 'r', encoding='utf-8') as json_file:
        data = json.load(json_file)
    
    # Filtrar juegos que coincidan con la consulta
    juegos_filtrados = [juego for juego in data if query.lower() in juego['Nombre del juego'].lower()]
    
    # Ordenar juegos por precio
    if orden == 'asc':
        juegos_filtrados.sort(key=lambda x: get_precio(x))
    elif orden == 'desc':
        juegos_filtrados.sort(key=lambda x: get_precio(x), reverse=True)
    
    return render_template('top_juegos.html', juegos=juegos_filtrados)

# Función auxiliar para obtener el precio numérico (manejando 'Free to Play')
def get_precio(juego):
    precio = juego['Precio']
    if precio.lower() == 'free to play':
        return 0  # Considerar 'Free to Play' como precio 0
    else:
        try:
            return float(precio.split('$ ')[-1].replace(',', ''))
        except ValueError:
            return float('inf')  # Manejar otros casos de precio no numérico

@app.route('/acerca_de/')
def acerca_de():
    return render_template('acerca_de.html')

@app.route('/contacto/')
def contacto():
    return render_template('contacto.html')

if __name__ == '__main__':
    app.run(debug=True)
