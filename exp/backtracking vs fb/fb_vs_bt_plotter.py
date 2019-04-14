import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

#grafico complejidad de exp
df = pd.read_csv("bt_vs_fb.csv")
# Nano -> Milli
df['fuerzaBruta']  /= 1000000.0
df['backtracking']  /= 1000000.0

df.plot('n', ['fuerzaBruta', 'backtracking'])

ax1 = sns.lmplot(x='fuerzaBruta', y='backtracking', data=df);
plt.xlabel("fuerzaBruta");
plt.ylabel("backtracking");

plt.show()
