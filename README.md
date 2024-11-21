# Projet C++ - SDL2 et Raylib

Ce projet utilise **SDL2** et **Raylib** pour créer une fenêtre graphique et gérer des entités. Vous devez avoir installé **SDL2** et **Raylib** globalement via **vcpkg** pour faire fonctionner le projet.

## Prérequis

- **vcpkg** doit être installé sur votre machine pour gérer les bibliothèques.
- Vous devez avoir **SDL2** et **Raylib** installés globalement via **vcpkg**.

## Installation des dépendances

### 1. Installer vcpkg

Si vous n'avez pas déjà installé **vcpkg**, vous pouvez suivre les instructions officielles d'installation ici :  
[https://github.com/microsoft/vcpkg](https://github.com/microsoft/vcpkg)

1. Clonez le repository `vcpkg` :

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
````

2. Exécutez le script d'installation pour votre plateforme (Windows, Linux, ou macOS).

- Sur Windows :

```bash
.\bootstrap-vcpkg.bat
````

- Sur Linux/macOS :

```bash
./bootstrap-vcpkg.sh
````

3. Ajoutez vcpkg à votre chemin (suivez les instructions données à la fin du script d'installation).

### 2. Installer SDL2 et Raylib avec vcpkg

Une fois `vcpkg` installé et configuré, vous pouvez installer SDL2, Raylib et ses dépendances en exécutant les commandes suivantes dans votre terminal :

```bash
vcpkg install sdl2 sdl2-image sdl2-ttf raylib
````

Cela installera les bibliothèques nécessaires globalement via **vcpkg**.

### 3. Intégration avec Visual Studio

Après avoir installé les bibliothèques via vcpkg, vous pouvez les intégrer avec votre IDE (par exemple, Visual Studio) en utilisant la commande suivante :

```bash
vcpkg integrate install
````

Cela configure automatiquement vcpkg pour Visual Studio et l'ajoute à vos projets.

***Si vous utilisez un autre IDE, vous devrez peut-être configurer manuellement les chemins d'inclusion et les bibliothèques dans votre projet.***

## Utilisation du projet

1. Clonez ce projet :

```bash
git clone https://github.com/Firzus/project-encapsulation.git
````

2. Ouvrez le projet dans votre IDE (par exemple, Visual Studio ou un éditeur de texte avec CMake).

3. Compilez et exécutez le projet.
