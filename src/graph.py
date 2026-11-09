import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# --- 1. Чтение CSV файла ---
df = pd.read_csv('data.csv', sep=';', names=['t', 'x'])

# --- 2. Аналитическое решение ---
k = 0.01
x0 = 10
omega = np.sqrt(k)
x_analytic = x0 * np.cos(omega * df['t'])

# --- 3. Построение графика ---
plt.scatter(df['t'], df['x'], color='blue', s=2, label='Численное решение (явный Эйлер)')
plt.plot(df['t'], x_analytic, color='red', linewidth=1, label='Аналитическое: 10·cos(0.1·t)')

# --- 4. Оформление ---
plt.title('Пружинный маятник: численное и аналитическое решения')
plt.xlabel('t, с')
plt.ylabel('x')
plt.legend()
plt.grid(alpha=0.3)

plt.figure()
plt.plot(df['t'], df['x'] - x_analytic)
plt.xlabel('t, с')
plt.ylabel('Ошибка x_числ − x_аналит')
plt.grid(alpha=0.3)
plt.show()