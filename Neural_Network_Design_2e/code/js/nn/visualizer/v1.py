
import numpy as np
from graphviz import Digraph
from IPython.display import SVG, display


def visualize(p, w, b, n, a, filename="neuron_visualization"):

    # Normalize arrays for display
    p = np.asarray(p).ravel()
    w = np.asarray(w).ravel()

    n = float(np.asarray(n).item())
    a = float(np.asarray(a).item())
    b = float(np.asarray(b).item())

    if p.size != w.size:
        raise ValueError(
            f"p and w must have equal sizes: {p.size} != {w.size}"
        )

    dot = Digraph("Neuron", format="svg")

    dot.attr(
        rankdir="LR",
        splines="true",
        nodesep="0.25",
        ranksep="0.8",
        label=f"Multiple Input Neuron - Abbreviated Notation ({p.size} inputs)",
        labelloc="t",
        fontsize="18",
        pad="0.2"
    )

    dot.attr("node", fontname="Arial", fontsize="10")
    dot.attr("edge", fontname="Arial", fontsize="8")

    # Input nodes
    with dot.subgraph(name="cluster_inputs") as inputs:
        inputs.attr(label="Inputs", style="rounded", color="lightblue")

        for i, p_i in enumerate(p, start=1):
            inputs.node(
                f"p{i}",
                f"p{i}\n{p_i:.3f}",
                shape="box",
                style="rounded,filled",
                fillcolor="lightblue"
            )

    # Summation node
    dot.node(
        "sum",
        "Σ\nWeighted Sum",
        shape="circle",
        style="filled",
        fillcolor="lightcyan"
    )

    # Weighted connections
    for i, w_i in enumerate(w, start=1):
        dot.edge(
            f"p{i}", "sum",
            label=f"w{i} = {w_i:.3f}",
            fontcolor="blue"
        )

    # Bias node
    dot.node(
        "bias",
        f"b = {b:.3f}",
        shape="ellipse",
        style="filled",
        fillcolor="wheat"
    )

    # Place bias above the summation node.
    # With rankdir=LR, rank=same puts nodes in the same column.
    with dot.subgraph(name="bias_alignment") as s:
        s.attr(rank="same")
        s.node("bias")
        s.node("sum")

    # Invisible edge encourages bias to be above summation
    dot.edge("bias", "sum", style="invis", weight="10")

    # Visible bias connection
    dot.edge(
        "bias", "sum",
        label="bias",
        color="darkorange",
        constraint="false"
    )

    # Net input
    dot.node(
        "net",
        f"n = Wp + b\n{n:.4f}",
        shape="box",
        style="rounded,filled",
        fillcolor="lightyellow"
    )
    dot.edge("sum", "net")

    # Activation
    dot.node(
        "activation",
        f"tansig(n)\na = {a:.4f}",
        shape="ellipse",
        style="filled",
        fillcolor="palegreen"
    )
    dot.edge("net", "activation")

    # Display scalable SVG in Jupyter
    output = dot.render(filename=filename, cleanup=True)
    #display(SVG(filename=output))

    return dot
