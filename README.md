## EvolucionArtificial

# Evolución artificial

### Introducción
---
Se debe realizar la simulación de la evolución de una especie de organismos que llamaremos “MO” (Micro Organismo). 
<br>
La simulación debe representar a varios MO que se mueven según unas características internas que están establecidas por un “cromosoma” en cada uno de ellos. Si detecta comida en un lugar a su alrededor, su cromosoma interno determinará al lugar que debe moverse. 
Si no detecta comida, seguirá moviéndose en la misma dirección que se estaba moviendo. Debido a que los movimientos consumen su energía, prevalecerán en el tiempo los que más coman y evolutivamente estén mejor adaptados para conseguirla.
<br>
Los MO que mueran porque su energía llegó a cero, serán reemplazados por hijos a partir de dos padres que le entregarán parte de su código genéticos (cromosoma) para que el hijo tenga un nuevo cromosoma. De esta manera, las nuevas generaciones de MO tendrán nuevas habilidades para conseguir comida y el ciclo de la evolución se dará una y otra vez. En esta simulación, los primeros MOs nacerán en un lugar al azar y con los genes de su cromosoma también al azar. 
<br>
Habrá unos “sembradores” que agregan comida en la superficie que inicialmente estará vacía. De ésta comida se alimentarán los MO. Cuando un MO quiere comer un cierta cantidad en el lugar que se encuentra, podrá hacerlo si existe esa cantidad de comida, caso contrario, deberá conformarse con una cantidad menor. Además, los MO no podrán tener una energía (comida) superior a un máximo permitido. Se deberá realizar el diseño y la codificación de un mundo finito con varios MO, sembradores y el resto de las características descriptas.
<br>

### Tecnologias utilizadas 
---
El proyecto se desarrollo en C++ y se utilizó OpenGL para realizar la parte de graficación del sistema creado.
