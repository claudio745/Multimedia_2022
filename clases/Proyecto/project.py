from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route("/<string:slug>/")
def juegos(slug):
    if slug == "top_juegos":
        return render_template('top_juegos.html')
    elif slug == "peores_juegos":
        return render_template('peores_juegos.html')

if __name__ == '__main__':
    app.run(debug=True)

