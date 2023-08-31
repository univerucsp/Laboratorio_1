import pandas as pd
import matplotlib.pyplot as plt

# El txt cambia segun el archivo con la dimension deseada
df2 = pd.read_csv("2.txt", sep=",", header=None)

dim10 = df2.T.squeeze()

# Graficar un histograma
plt.hist(dim10, bins=10, color="#607c8e", rwidth=0.9)
plt.title("Distancia entre puntos con dimensión 2")
plt.xlabel("Distancia")
plt.ylabel("Frecuencia")
plt.grid(True)
plt.show()
