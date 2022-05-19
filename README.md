#Maze

## Einleitung


- [Milestone 1 - Grundstruktur und Ausgabe](description/Milestone_1.md)
- [Milestone 2 - Spiellogik](description/Milestone_2.md)

## Spezifikation

- nur geforderte Ausgaben
- Die zur Verfügung gestellten Klassen (`RoomInfoString` und `Random`) dürfen nicht verändert werden.
- Es muss eine Ableitungshierarchie (Klassen mit Vererbung) implementiert werden.
- Alle Bibliotheken der C++ Standard Library sind erlaubt.

## Spielaufbau

*Maze* ist ein Single-Player-Spiel im Stil eines [Dungeon Crawlers](https://de.wikipedia.org/wiki/Dungeon_(Rollenspiele)). Die\*der Spieler\*in steuert dabei drei Charaktere durch ein Labyrinth, wobei der Spielplan durch die Bewegungen der Charaktere erst nach und nach sichtbar wird.

Im Labyrinth verteilt befinden sich Hindernisse und Bonusfelder, die bewältigt werden müssen bzw. spezielle Effekte auslösen.

Es gibt die folgenden Charaktere:
- Krieger\*in ('Fighter')
- Dieb\*in ('Thief')
- Wahrsager\*in ('Seer')

## Spielbeginn

Zu Beginn des Spiels ist nur ein Raum (der Startraum 'S') sichtbar, in dem sich alle Charaktere befinden. Der Rest des Spielplans ist unbekannt. Die Anordnung und Darstellung der Räume (sowie der einzelnen Felder, aus denen Räume bestehen können) wird in [Milestone 1](description/Milestone_1.md) beschrieben.

Die\*der Spieler\*in hat vier Kärtchen, auf denen jeweils eine Bewegungsrichtung (hinunter, hinauf, rechts, links) abgebildet ist. Diese werden gemischt und das oberste Kärtchen aufgedeckt.

## Spielablauf

Die\*der Spieler\*in führt nacheinander Spielzüge durch, um das Spielziel zu erreichen. Hier gibt es verschiedene Möglichkeiten.
Die\*der Spieler\*in kann:

1. einen Charakter bewegen
2. die Spezialfähigkeit eines Charakters einsetzen

### 1. Charakter bewegen

Ein Zug kann dafür verwendet werden, einen Charakter um ein beliebige Anzahl an Feldern in eine bestimmte Richtung zu bewegen. 
Es ist jedoch nicht immer möglich, die Charaktere in jede beliebige Richtung zu bewegen. Die\*der Spieler\*in darf nur Bewegungen in jene Richtung durchführen, deren Bewegungskärtchen gerade aufgedeckt ist. Dies kann sie\*er jedoch *beliebig oft* für *alle* Charaktere tun.  

Hierbei sind Hindernisse (z. B. Wände und Monster) zu beachten. Es gibt bestimmte Bonusfelder (z. B. Sanduhr, Monster, Kristallkugel, Schalter), die entweder automatisch eingesetzt werden, wenn ein Charakter seine Bewegung auf diesem Feld beendet, oder es dem Charakter ermöglichen, seine Spezialfähigkeit einzusetzen, wenn sie\*er sich auf einem benachbarten Feld befindet.

Kommt ein Charakter auf einem Durchgang zu einem noch unbekannten Nachbarraum zu stehen, wird dieser Raum automatisch aufgedeckt.

Wenn die\*der Spieler\*in keine Bewegungen in die derzeit erlaubte Richtung mehr durchführen will oder kann, fügt sie\*er das derzeitige Bewegungskärtchen an letzter Stelle in der Reihenfolge hinzu und deckt das nächste auf.

### 2. Spezialfähigkeit einsetzen

Jeder der Charaktere hat eine Spezialfähigkeit, die sie\*er unter bestimmten Umständen einsetzen kann.
- Krieger\*in ('Fighter') -> Monster bekämpfen ('fight')
- Dieb\*in ('Thief')      -> verschlossene Türe aufsperren ('unlock')
- Wahrsager\*in ('Seer')  -> unbekannten Raum aus Entfernung aufdecken ('scry')

Spezialfähigkeiten können jederzeit und beliebig oft eingesetzt werden, solange ihre Voraussetzungen erfüllt sind (siehe [Milestone 2](description/Milestone_2.md)).

## Spielende

Jeder der Charaktere muss einen ihm zugewiesenen Schalter erreichen. Wenn sich alle Charaktere gleichzeitig auf ihrem Schalter befinden, öffnen sich die geheimen Türen zur Schatzkammer. Alle Charaktere müssen sich nun zur Schatzkammer bewegen, um das Spiel zu gewinnen.


## Spielziel

Ziel des Spiels ist es, möglichst wenige neue Bewegungskärtchen aufzudecken, also die Schatzkammer möglichst effizient zu erreichen.
