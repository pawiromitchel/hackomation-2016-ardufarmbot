# Hackomation 2016

## Stap 1

### Opzetten van een python server op de Rasberry Pi

De packages die nodig zijn voor python zijn: 
- python
- flask (renderen van de html pagina's)
- pyserial (communiceren met de USB module)
- ino (uploaden van arduino scripts)

```
sudo apt-get -y install python
sudo pip install flask pyserial ino
```
In de webapp/ folder bestaat er een __init__.py. Om de python server te runnen is deze command nodig:

`python __init__.py `

