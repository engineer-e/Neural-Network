import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle, Circle, FancyArrowPatch
from matplotlib.widgets import Slider, TextBox

# ============================================================
# SINGLE-INPUT NEURON WITH HARD-LIMIT TRANSFER FUNCTION
# ============================================================

# Initial values
p0 = 1.0
w0 = 1.0
b0 = 0.0

# ------------------------------------------------------------
# Hard-limit transfer function
# ------------------------------------------------------------
def hard_limit(n):
    return 0 if n < 0 else 1


def neuron_output(p, w, b):
    n = w * p + b
    a = hard_limit(n)
    return n, a


# Initial calculation
n0, a0 = neuron_output(p0, w0, b0)

# ------------------------------------------------------------
# Figure
# ------------------------------------------------------------
fig = plt.figure(figsize=(13, 8))
fig.patch.set_facecolor("#F5F7FA")

# Main diagram area
ax = fig.add_axes([0.05, 0.34, 0.90, 0.58])
ax.set_xlim(0, 12)
ax.set_ylim(0, 7)
ax.axis("off")
ax.set_facecolor("#F5F7FA")

# ============================================================
# TITLE
# ============================================================

ax.text(
    6, 6.65,
    "Single-Input Neuron",
    ha="center",
    fontsize=25,
    fontweight="bold",
    color="#17202A"
)

ax.text(
    6, 6.25,
    r"$a = f(wp+b)$",
    ha="center",
    fontsize=20,
    color="#34495E"
)

# ============================================================
# INPUT
# ============================================================

ax.text(
    1.0, 4.3,
    "Input",
    fontsize=17,
    fontweight="bold",
    color="#2874A6"
)

# Input circle
input_dot = Circle(
    (1.5, 3.5),
    0.12,
    color="#2874A6"
)
ax.add_patch(input_dot)

ax.text(
    1.25, 3.05,
    r"$p$",
    fontsize=23,
    color="#2874A6"
)

# Arrow p -> summation
ax.add_patch(
    FancyArrowPatch(
        (1.65, 3.5),
        (3.25, 3.5),
        arrowstyle="->",
        mutation_scale=20,
        linewidth=2.5,
        color="#2874A6"
    )
)

# Weight
ax.text(
    2.25, 3.82,
    r"$w$",
    fontsize=20,
    color="#8E44AD"
)

# ============================================================
# SUMMATION BLOCK
# ============================================================

sum_box = Rectangle(
    (3.25, 2.9),
    1.0,
    1.2,
    linewidth=3,
    edgecolor="#2C3E50",
    facecolor="white"
)
ax.add_patch(sum_box)

ax.text(
    3.75, 3.5,
    r"$\Sigma$",
    ha="center",
    va="center",
    fontsize=32,
    color="#2C3E50"
)

# ============================================================
# BIAS
# ============================================================

bias_dot = Circle(
    (3.75, 1.65),
    0.12,
    color="#E67E22"
)
ax.add_patch(bias_dot)

ax.add_patch(
    FancyArrowPatch(
        (3.75, 1.78),
        (3.75, 2.9),
        arrowstyle="->",
        mutation_scale=18,
        linewidth=2.5,
        color="#E67E22"
    )
)

ax.text(
    4.05, 2.15,
    r"$b$",
    fontsize=21,
    color="#E67E22"
)

# ============================================================
# n = wp+b
# ============================================================

ax.add_patch(
    FancyArrowPatch(
        (4.25, 3.5),
        (5.55, 3.5),
        arrowstyle="->",
        mutation_scale=20,
        linewidth=2.5,
        color="#34495E"
    )
)

n_text = ax.text(
    4.9, 3.85,
    rf"$n={n0:.2f}$",
    ha="center",
    fontsize=18,
    color="#34495E"
)

# ============================================================
# TRANSFER FUNCTION
# ============================================================

f_box = Rectangle(
    (5.55, 2.9),
    1.15,
    1.2,
    linewidth=3,
    edgecolor="#27AE60",
    facecolor="#EAF8F0"
)
ax.add_patch(f_box)

ax.text(
    6.125, 3.5,
    r"$f$",
    ha="center",
    va="center",
    fontsize=30,
    color="#27AE60"
)

ax.text(
    6.125, 2.55,
    "Hard Limit",
    ha="center",
    fontsize=13,
    fontweight="bold",
    color="#27AE60"
)

# ============================================================
# OUTPUT
# ============================================================

ax.add_patch(
    FancyArrowPatch(
        (6.7, 3.5),
        (8.3, 3.5),
        arrowstyle="->",
        mutation_scale=20,
        linewidth=2.5,
        color="#C0392B"
    )
)

a_text = ax.text(
    8.7, 3.5,
    rf"$a={a0}$",
    ha="center",
    va="center",
    fontsize=25,
    fontweight="bold",
    color="#C0392B"
)

# ============================================================
# STATUS BOX
# ============================================================

status_box = Rectangle(
    (8.0, 1.6),
    3.0,
    1.2,
    linewidth=2,
    edgecolor="#BDC3C7",
    facecolor="white"
)
ax.add_patch(status_box)

status_text = ax.text(
    9.5, 2.2,
    "Neuron OFF" if a0 == 0 else "Neuron ON",
    ha="center",
    va="center",
    fontsize=20,
    fontweight="bold",
    color="#C0392B" if a0 == 0 else "#27AE60"
)

# ============================================================
# HARD LIMIT GRAPH
# ============================================================

graph_ax = fig.add_axes([0.67, 0.08, 0.27, 0.19])
graph_ax.set_facecolor("white")

x = np.linspace(-3, 3, 1000)
y = np.where(x < 0, 0, 1)

graph_ax.plot(
    x[x < 0],
    y[x < 0],
    color="#3498DB",
    linewidth=3
)

graph_ax.plot(
    x[x >= 0],
    y[x >= 0],
    color="#3498DB",
    linewidth=3
)

# Vertical jump
graph_ax.plot(
    [0, 0],
    [0, 1],
    color="#3498DB",
    linewidth=3
)

# Open circle at (0,0)
graph_ax.plot(
    0, 0,
    marker="o",
    markersize=9,
    markerfacecolor="white",
    markeredgecolor="#3498DB",
    markeredgewidth=2
)

# Filled circle at (0,1)
graph_ax.plot(
    0, 1,
    marker="o",
    markersize=9,
    color="#3498DB"
)

# Current n marker
current_point, = graph_ax.plot(
    n0,
    a0,
    marker="o",
    markersize=11,
    color="#E74C3C",
    zorder=5
)

graph_ax.axvline(
    0,
    color="#95A5A6",
    linestyle="--",
    linewidth=1
)

graph_ax.set_xlim(-3, 3)
graph_ax.set_ylim(-0.2, 1.2)

graph_ax.set_xlabel("n", fontsize=12)
graph_ax.set_ylabel("a", fontsize=12)

graph_ax.set_title(
    "Hard Limit Transfer Function",
    fontsize=13,
    fontweight="bold"
)

graph_ax.grid(alpha=0.2)

# ============================================================
# CONTROL PANEL
# ============================================================

# Slider positions
ax_p = fig.add_axes([0.08, 0.25, 0.40, 0.025])
ax_w = fig.add_axes([0.08, 0.20, 0.40, 0.025])
ax_b = fig.add_axes([0.08, 0.15, 0.40, 0.025])

slider_p = Slider(
    ax_p, "Input p",
    -5, 5,
    valinit=p0,
    valstep=0.1,
    color="#3498DB"
)

slider_w = Slider(
    ax_w, "Weight w",
    -5, 5,
    valinit=w0,
    valstep=0.1,
    color="#8E44AD"
)

slider_b = Slider(
    ax_b, "Bias b",
    -5, 5,
    valinit=b0,
    valstep=0.1,
    color="#E67E22"
)

# ============================================================
# TEXT INPUT BOXES
# ============================================================

box_p_ax = fig.add_axes([0.52, 0.235, 0.10, 0.04])
box_w_ax = fig.add_axes([0.52, 0.185, 0.10, 0.04])
box_b_ax = fig.add_axes([0.52, 0.135, 0.10, 0.04])

box_p = TextBox(
    box_p_ax,
    "p = ",
    initial=str(p0)
)

box_w = TextBox(
    box_w_ax,
    "w = ",
    initial=str(w0)
)

box_b = TextBox(
    box_b_ax,
    "b = ",
    initial=str(b0)
)

# ============================================================
# LIVE UPDATE FUNCTION
# ============================================================

def update(value=None):

    p = slider_p.val
    w = slider_w.val
    b = slider_b.val

    n, a = neuron_output(p, w, b)

    # Update equation
    n_text.set_text(
        rf"$n=wp+b={n:.2f}$"
    )

    # Update output
    a_text.set_text(
        rf"$a={a}$"
    )

    # Update status
    if a == 1:
        status_text.set_text("Neuron ON")
        status_text.set_color("#27AE60")
    else:
        status_text.set_text("Neuron OFF")
        status_text.set_color("#C0392B")

    # Move point on graph
    current_point.set_data([n], [a])

    fig.canvas.draw_idle()


# ============================================================
# SLIDER -> TEXT BOX
# ============================================================

def slider_changed(value):

    box_p.set_val(f"{slider_p.val:.2f}")
    box_w.set_val(f"{slider_w.val:.2f}")
    box_b.set_val(f"{slider_b.val:.2f}")

    update()


slider_p.on_changed(slider_changed)
slider_w.on_changed(slider_changed)
slider_b.on_changed(slider_changed)


# ============================================================
# TEXT BOX -> SLIDER
# ============================================================

def text_p_changed(text):
    try:
        value = float(text)
        if -5 <= value <= 5:
            slider_p.set_val(value)
    except ValueError:
        pass


def text_w_changed(text):
    try:
        value = float(text)
        if -5 <= value <= 5:
            slider_w.set_val(value)
    except ValueError:
        pass


def text_b_changed(text):
    try:
        value = float(text)
        if -5 <= value <= 5:
            slider_b.set_val(value)
    except ValueError:
        pass


box_p.on_submit(text_p_changed)
box_w.on_submit(text_w_changed)
box_b.on_submit(text_b_changed)


# ============================================================
# FORMULA / EXPLANATION
# ============================================================

fig.text(
    0.08, 0.08,
    r"$n=wp+b$",
    fontsize=20,
    fontweight="bold",
    color="#2C3E50"
)

fig.text(
    0.08, 0.045,
    r"$a=0\;\mathrm{if}\;n<0,\qquad a=1\;\mathrm{if}\;n\geq0$",
    fontsize=16,
    color="#34495E"
)

fig.text(
    0.08, 0.01,
    "Move the sliders or enter values in the boxes. The neuron updates instantly.",
    fontsize=11,
    color="#7F8C8D"
)

plt.show()