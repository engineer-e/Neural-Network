import numpy as np
import matplotlib.pyplot as plt
# Network Visualizer Class with Enhanced, Highly Visible Weight Labels
class NetworkVisualizer:
    def __init__(self, layer_outputs, layer_weights=None, layer_labels=None):
        self.layer_outputs = layer_outputs
        self.layer_weights = layer_weights or []
        self.layer_sizes = [arr.shape[0] for arr in layer_outputs]
        self.layer_labels = layer_labels or [f"Layer {i}" for i in range(len(layer_outputs))]

    def render(self, title="Neural Network Architecture & Weighted Connections"):
        max_neurons = max(self.layer_sizes)
        fig_height = max(11, max_neurons * 0.75)
        
        # Expanded width to give maximum horizontal breathing room between dense layers
        fig, ax = plt.subplots(figsize=(20, fig_height))
        ax.axis('off')
        
        ax.set_xlim(0, 1)
        ax.set_ylim(0, 1)
        
        n_layers = len(self.layer_sizes)
        x_coords = np.linspace(0.12, 0.88, n_layers)
        node_coords = []
        
        node_radius = max(0.012, min(0.035, 0.28 / max_neurons))
        font_size = max(6, min(10, int(35 / max_neurons)))

        # Position neurons strictly between y = 0.15 and y = 0.72
        for l, (size, x) in enumerate(zip(self.layer_sizes, x_coords)):
            y_coords = np.linspace(0.72, 0.15, size) if size > 1 else [0.435]
            node_coords.append([(x, y) for y in y_coords])
            
        # Draw connections and enhanced weight labels
        for l in range(n_layers - 1):
            W = self.layer_weights[l] if l < len(self.layer_weights) else None
            current_layer = node_coords[l]
            next_layer = node_coords[l+1]
            
            for j, start_node in enumerate(current_layer):
                for i, end_node in enumerate(next_layer):
                    if W is not None:
                        weight_val = W[i, j]
                        line_width = 0.3 + abs(weight_val) * 2.5
                        alpha = min(0.8, max(0.25, abs(weight_val)))
                        line_color = 'navy' if weight_val >= 0 else 'firebrick'
                    else:
                        line_width = 0.5
                        alpha = 0.3
                        line_color = 'gray'
                    
                    # Plot connection line
                    ax.plot([start_node[0], end_node[0]], [start_node[1], end_node[1]], 
                            color=line_color, alpha=alpha, linewidth=line_width, zorder=1)
                    
                    # Render prominent, highly legible weight labels with solid padding & border
                    if W is not None:
                        mid_x = 0.5 * (start_node[0] + end_node[0])
                        mid_y = 0.5 * (start_node[1] + end_node[1])
                        
                        # Scaled font size for high readability
                        lbl_size = max(7, min(9, int(50 / max_neurons)))
                        
                        ax.text(mid_x, mid_y, f"{weight_val:.2f}", fontsize=lbl_size, 
                                ha='center', va='center', color='black', fontweight='bold', zorder=3,
                                bbox=dict(boxstyle='round,pad=0.2', facecolor='white', edgecolor='silver', alpha=0.95))

        colors = ['skyblue', 'salmon', 'lightgreen', 'plum', 'khaki']
        
        # Draw layer header boxes safely above nodes at y = 0.82
        for l, nodes in enumerate(node_coords):
            x = x_coords[l]
            ax.text(x, 0.82, self.layer_labels[l], fontsize=11, fontweight='bold', 
                    ha='center', va='center', color='black', zorder=5,
                    bbox=dict(boxstyle='round,pad=0.4', facecolor='white', edgecolor='gray', alpha=0.95))
            
            current_vals = self.layer_outputs[l].flatten()
            
            for i, (nx, ny) in enumerate(nodes):
                circle = plt.Circle((nx, ny), node_radius, color=colors[l % len(colors)], ec='black', zorder=4)
                ax.add_patch(circle)
                
                val_str = f"{current_vals[i]:.2f}" if abs(current_vals[i]) < 10 else f"{current_vals[i]:.1f}"
                ax.text(nx, ny, val_str, fontsize=font_size, ha='center', va='center', fontweight='bold', zorder=5)

        plt.suptitle(title, fontsize=14, fontweight='bold', y=0.95)
        plt.tight_layout()
        plt.show()
