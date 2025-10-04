# Maze Solver with A* and Depth-First Search

## Description du projet :

Ce projet implémente un **solveur de labyrinthe** en C++. Il utilise deux algorithmes principaux :  
- **DFS (Depth-First Search / profondeur d’abord)**  
- **Approche optimisée inspirée de A\*** (heuristique combinant distance à l’objectif et nombre de visites des cases)

Le labyrinthe est lu depuis un fichier `maze.txt` et visualisé dans la console à l’aide de symboles ASCII et emoji.  
Ce programme  est renforcé par le fait qu'il calcule également des statistiques sur le nombre de déplacements nécessaires pour atteindre la sortie.

** Le projet est  toujours en cours de développement** : certaines fonctionnalités (interface graphique, optimisation de la visualisation, ajout d’autres algorithmes) sont encore en construction.

## Fonctionnalités actuelles

- Lecture automatique d’un labyrinthe depuis `maze.txt`
- Résolution automatique avec plusieurs stratégies de déplacement :
  - Déplacement aléatoire
  - Déplacement optimisé (heuristique type A*)
  - DFS (profondeur d’abord)
- Visualisation du labyrinthe dans la console avec des symboles clairs
- Statistiques sur le nombre de déplacements pour atteindre la sortie : minimum, maximum et moyenne

---

## Installation et compilation

1. Cloner le dépôt :
```bash
git clone https://github.com/fuuuushina/Maze_Solver_AStar_DFS.git
cd Maze_Solver_AStar_DFS
