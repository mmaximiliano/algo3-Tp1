import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

#grafico complejidad de exp
df = pd.read_csv("exp_dp_n_w_25.csv")

# Nano -> Milli
df['time']  /= 1000000.0
df['teorica'] = 0.000032*df['n'] * 25

df.plot('n', ['time', 'teorica'])

r = np.corrcoef(df['time'], df['teorica'])[0,1]
print(r)
#out: r = 0.9804304907022177

ax1 = sns.lmplot(x='time', y='teorica', data=df);
plt.xlabel("T(n)");
plt.ylabel("cota(n)");

plt.show()