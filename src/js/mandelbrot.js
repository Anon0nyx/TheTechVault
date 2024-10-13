const canvas = document.getElementById('mandelbrotCanvas');
const ctx = canvas.getContext('2d');

const maxIterations = 500;
let zoomLevel = 200;
let offsetX = canvas.width / 2;
let offsetY = canvas.height / 2;

let startX, startY, endX, endY, isDragging = false;

function drawMandelbrot() {
  const imageData = ctx.createImageData(canvas.width, canvas.height);
  const data = imageData.data;

  for (let x = 0; x < canvas.width; x++) {
    for (let y = 0; y < canvas.height; y++) {
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

      const color = iteration === maxIterations ? 0 : iteration * 16;
      const pixelIndex = (y * canvas.width + x) * 4;
      data[pixelIndex] = color % 256;          
      data[pixelIndex + 1] = (color * 3) % 256; 
      data[pixelIndex + 2] = (color * 7) % 256; 
      data[pixelIndex + 3] = 255;               
    }
  }

  ctx.putImageData(imageData, 0, 0);
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

    ctx.putImageData(ctx.createImageData(canvas.width, canvas.height), 0, 0);  // clear the canvas
    drawMandelbrot();
    ctx.strokeStyle = 'red';
    ctx.lineWidth = 2;
    ctx.strokeRect(startX, startY, endX - startX, endY - startY); // Draw selection rectangle
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
    drawMandelbrot();
  }
});

drawMandelbrot();