import numpy as np
from graphviz import Digraph
from IPython.display import Image, display


     
def visualize(p,w,b,n,a, filename="neuron_visualization"):
     dot = Digraph("Neuron", format="png")

     dot.attr(
        rankdir="LR",
        splines="true",
        nodesep="0.6",
        ranksep="0.8",
        label="Multiple Input Neuron",
        labelloc="t",
        fontsize="18"
     )

     dot.attr("node", fontname="Arial", fontsize="11")

     # Input nodes
     for i, p_i in enumerate(p, start=1):
        dot.node(
            f"p{i}", f"p{i}\n{p_i:.3f}",
            shape="circle", style="filled",
            fillcolor="lightblue"
        )

     # Summation neuron
     dot.node(
            "sum",
            "Σ\nWeighted Sum",
            shape="circle",
            style="filled",
            fillcolor="lightcyan"
     )

     


     # Weighted input connections: left to right
     for i, w_i in enumerate(w, start=1):
        dot.edge(
            f"p{i}", "sum",
            label=f"w{i} = {w_i:.3f}",
            fontcolor="blue"
        )

     # Bias placed above the summation neuron
     dot.node(
        "bias", f"b = {b}",
        shape="circle", style="filled",
        fillcolor="wheat"
     )

     # Force bias above sum and connect vertically
     dot.edge(
        "bias", "sum",
        label="bias",
        constraint="false",
        minlen="1"
    )

     with dot.subgraph() as s:
        s.attr(rank="same")
        s.node("bias")
        s.node("sum")

     # Net input and activation
     dot.node(
        "net",
        f"n = Wp + b\n{n:.4f}",
        shape="box", style="rounded,filled",
        fillcolor="lightyellow"
     )

     dot.edge("sum", "net")

     dot.node(
        "activation",
        f"tansig(n)\na = {a:.4f}",
        shape="ellipse", style="filled",
        fillcolor="palegreen"
     )

     dot.edge("net", "activation")

     # Render in Jupyter without an external viewer
     output = dot.render(
        filename=filename,
        view=False,
        cleanup=True
     )

     from IPython.display import Image, display
     #display(Image(filename=output))

     return dot


