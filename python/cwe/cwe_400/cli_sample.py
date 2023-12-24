import sys
import time
from math import pi


def process(item):
    # On simule un temps de traitement de 10 ms par valeur
    time.sleep(0.01)
    return item * pi


def unsafe(data):
    for item in data:
        print(process(int(item)))


def safe(data):
    '''Fonction qui effectue un traitement sur les données avec une gestion appropriée des ressources'''

    MAX_ELEMENTS = 10000  # Limite arbitraire pour illustrer la gestion des ressources

    # Assurer que la taille de la liste est raisonnable
    if len(data) > MAX_ELEMENTS:
        raise ValueError("La taille de la liste dépasse la limite autorisée.")

    for item in data:
        print(process(int(item)))


if __name__ == '__main__':
    param = sys.argv[1]
    data = param.split(',')

    unsafe(data)
    safe(data)

# Usage nominal : python cli_sample.py '1,2,3'
# Faille : Si on utilise un nombre de valeurs excessifs (ici, supérieur 10000 valeurs), on risque de dépasser les ressources entrainant :
#    - une sur exploitation du CPU
#    - une sur exploitation de la RAM
#    - des délais de traitements trop long => timeout
#    - une indisponibilité de la machine pour d'autres traitements
#    - etc
