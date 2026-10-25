const TESTER = document.createElement("div");
TESTER.style.width = "600px";
TESTER.style.height = "350px";
document.body.appendChild(TESTER);

Plotly.newPlot(TESTER, [{
  x: [1, 2, 3, 4, 5],
  y: [1, 2, 4, 8, 16],
  type: "scatter"
}], { margin: { t: 0 } });