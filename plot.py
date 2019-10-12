import networkx as nx
import matplotlib.pyplot as plt

def open_dict(file):
    f = open(file)
    d_out = {}

    for line in f:
        try:
            label, code = map(int, line.split())
        except:
            continue
        d_out[label] = code
    
    return d_out

def open_weights(file, d):
    f = open(file)
    w_out = {}

    for line in f:
        org, dst, w = map(int, line.split())
        w_out[(d[org], d[dst])] = w
    
    return w_out

d = open_dict("g.txt")
w = open_weights("w.txt", d)

g = nx.DiGraph()

for ed in w.items():
    g.add_edge(*ed[0], weight = ed[1])

nx.draw_networkx(g, pos = nx.drawing.spring_layout(g), node_size = 800, font_size = 6)
plt.show()