import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import scipy.optimize as optimization
from scipy.stats.stats import pearsonr
import csv


sns.set()

def costo_PD(x,c):
	return x*c


PD_data = np.array(list(csv.reader(open("res_heat.csv", 'r')))).astype("float")
tamEntrada= PD_data[0,1:].astype(int)
tamMochila = PD_data[1:,0].astype(int)

tiemposPD = PD_data[1:,1:]

df = pd.DataFrame(tiemposPD, index=tamMochila, columns=tamEntrada)

fig, ax =plt.subplots()

# Heatmap
sns.heatmap(df,ax=ax, square=False)
ax.set_xlabel("Cantidad de elementos")
ax.set_ylabel("Capacidad de la mochila")
plt.savefig("heatmap.png", bbox_inches='tight')
plt.clf()
