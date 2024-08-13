document.addEventListener('DOMContentLoaded', function() {
  crearGraficos();
});

async function crearGraficos() {
  const precioChart = document.getElementById('precio-chart');
  const ctx = precioChart.getContext('2d');

  try {
    const response = await fetch('{{ json_url }}');
    const jsonData = await response.json();

    // Extract game names and prices from JSON data
    const gameData = jsonData.map(game => ({
      nombre: game["Nombre del juego"],
      precio: parseFloat(game["Precio"].replace(/[^0-9,-]/g, ''))
    }));

    // Create the scatterplot
    new Chart(ctx, {
      type: 'scatter',
      data: {
        datasets: [{
          label: 'Precios de Juegos',
          data: gameData,
          backgroundColor: 'rgba(54, 20, 139, 0.2)',
          borderColor: 'rgba(54, 20, 139, 1)',
          pointRadius: 5
        }]
      },
      options: {
        responsive: true,
        plugins: {
          legend: {
            display: true,
            position: 'top',
          },
          tooltip: {
            callbacks: {
              label: function(context) {
                return `${context.dataset.label}: ${context.raw.precio}`;
              }
            }
          }
        },
        scales: {
          x: {
            title: {
              display: true,
              text: 'Nombre del Juego'
            }
          },
          y: {
            title: {
              display: true,
              text: 'Precio'
            }
          }
        }
      }
    });
  } catch (error) {
    console.error('Error loading JSON data:', error);
    // Handle the error appropriately (e.g., display an error message to the user)
  }
}
