const canvas = document.getElementById('mandelbrotCanvas');
const ctx = canvas.getContext('2d');

let maxIterations = 5000;
let zoomLevel = 300;
let offsetX = canvas.width / 2;
let offsetY = canvas.height / 2;

let startX, startY, endX, endY, isDragging = false;
let imageData; // Store the Mandelbrot set image

function drawMandelbrot() {
  imageData = ctx.createImageData(canvas.width, canvas.height);
  const data = imageData.data;

  let chunkX = 0;
  let chunkY = 0;
  const chunkSize = 50;

  function renderChunk() {
    for (let x = chunkX; x < chunkX + chunkSize && x < canvas.width; x++) {
      for (let y = chunkY; y < chunkY + chunkSize && y < canvas.height; y++) {
        const cx = (x - offsetX) / zoomLevel;
        const cy = (y - offsetY) / zoomLevel;
        let zx = 0, zy = 0;
        let iteration = 0;

        while (zx * zx + zy * zy < 4 && iteration < maxIterations) {
          const xtemp = zx * zx - zy * zy + cx;
          zy = 2 * zx * zy + cy;
          zx = xtemp;
          iteration++;
        }

        //const color = iteration === maxIterations ? 0 : 255;
        //const color = iteration === maxIterations ? 0 : 255 - Math.floor((iteration / maxIterations) * 255);
        const color = iteration === maxIterations ? 0 : (iteration / maxIterations) * 255; // best visual

        const pixelIndex = (y * canvas.width + x) * 4; // Universal line for getting the index of any pixel (x,y)'s RBGA array
        data[pixelIndex] = color;
        /*
        data[pixelIndex + 1] = color; // This version gets rid of any extra colors, keeps it black/white
        data[pixelIndex + 2] = color;
        data[pixelIndex + 3] = 255;
        */
        data[pixelIndex] = color % 256;            // Red
        data[pixelIndex + 1] = (color * 3) % 256;  // Green
        data[pixelIndex + 2] = (color * 7) % 256;  // Blue
        data[pixelIndex + 3] = 255;                // Alpha
      }
    }

    chunkX += chunkSize;
    if (chunkX >= canvas.width) {
      chunkX = 0;
      chunkY += chunkSize;
    }

    if (chunkY < canvas.height) {
      ctx.putImageData(imageData, 0, 0);
      requestAnimationFrame(renderChunk);
    } else {
      ctx.putImageData(imageData, 0, 0);
    }
  }

  renderChunk();
}

function drawSelectionBox() {
  ctx.putImageData(imageData, 0, 0); // Draw the stored Mandelbrot set image
  if (isDragging) {
    ctx.strokeStyle = 'white';
    ctx.lineWidth = 2;
    ctx.strokeRect(startX, startY, endX - startX, endY - startY);
  }
}

canvas.addEventListener('mousedown', (event) => {
  startX = event.offsetX;
  startY = event.offsetY;
  isDragging = true;
});

canvas.addEventListener('mousemove', (event) => {
  if (isDragging) {
    endX = event.offsetX;
    endY = event.offsetY;
    drawSelectionBox();
  }
});

canvas.addEventListener('mouseup', (event) => {
  if (isDragging) {
    endX = event.offsetX;
    endY = event.offsetY;
    isDragging = false;

    const selectedWidth = Math.abs(endX - startX);
    const selectedHeight = Math.abs(endY - startY);

    const zoomFactorX = canvas.width / selectedWidth;
    const zoomFactorY = canvas.height / selectedHeight;
    const newZoomLevel = zoomLevel * Math.min(zoomFactorX, zoomFactorY);

    const centerX = (startX + endX) / 2;
    const centerY = (startY + endY) / 2;

    offsetX = centerX - ((centerX - offsetX) * newZoomLevel / zoomLevel);
    offsetY = centerY - ((centerY - offsetY) * newZoomLevel / zoomLevel);

    zoomLevel = newZoomLevel;
    maxIterations = Math.min(1000, zoomLevel / 10);
    drawMandelbrot();
  }
});

function resetMandelbrot() {
  zoomLevel = 200;
  offsetX = canvas.width / 2;
  offsetY = canvas.height / 2;
  maxIterations = 1000;
  drawMandelbrot();
}

drawMandelbrot();
