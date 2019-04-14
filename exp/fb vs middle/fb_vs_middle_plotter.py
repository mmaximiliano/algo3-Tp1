import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

#grafico complejidad de exp
df = pd.read_csv("middle_fuerzaBruta.csv")
# Nano -> Milli
df['fuerzaBruta']  /= 1000000.0
df['middle']  /= 1000000.0

df.plot('n', ['fuerzaBruta', 'middle'])

ax1 = sns.lmplot(x='fuerzaBruta', y='middle', data=df);
plt.xlabel("fuerzaBruta");
plt.ylabel("middle");

plt.show()
