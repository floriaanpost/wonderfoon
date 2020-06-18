# V3 is klaar!
Omdat ik zelf ook weer plezier kreeg in het project heb ik v3 gemaakt. Helaas (nog) geen DTMF, maar wel betere stabiliteit (minder vaak/nooit fouten met pulsen tellen) en makkelijker om de firmware te updaten (ISCP port). Ook zit er een LED op het board voor debugging (of om te laten zien dat hij aan staat). Er zijn ook weer printplaten, dus bij interesse, stuur even een mailtje naar: floriaan@tutamail.com.

Heb je nog een oude versie, dan kun je wel de firmware gebruiken van v3 (alleen in wonderfoon.ino moet je OLD_PIN_CONFIG uncommenten), of anders kun je alles van v2 nog terugvinden in de v2 branch.

# Inleiding
De Wonderfoon is een ouderwetse draaischijftelefoon waar je muziek te horen krijgt door de hoorn als je een nummer draait. Het is oorspronkelijk bedacht als "speelgoed" voor (demente) ouderen door Leo Willems. De ouderwetse telefoon uit hun jonge jaren, gecombineerd met muziek uit dezelfde tijd is vaak en leuke ervaring voor ouderen. Het oorspronkelijke idee is gemaakt met een Raspberry Pi (een soort kleine computer). Voor het oorspronkelijke plan moet de telefoon (onherstelbaar) gesloopt worden. Met inspiratie van [een project van Jan Derogee (TeleJukebox)](https://github.com/JanDerogee/TeleJukebox) heb ik een nieuw type Wonderfoon ontworpen. Hierbij hoeft de telefoon niet gesloopt te worden en kun je de stekker van de telefoon gemakkelijk in een doosje stoppen dat zich gedraagt als de telefooncentrale. Ook is de Raspberry Pi vervangen door een kleine mp3 speler (DFPlayer Mini) en een microcontroller (ATTiny85).

# Foto's
De complete wonderfoon is in een klein doosje gestopt wat een standaard doosje is dat gemaakt wordt door Kopp en Q-link. Het printpaatje is zo ontworpen dat het precies past.

<img src="img/dicht.jpeg" width="40%" />

Als je het doosje openschroeft zie je het volgende:

<img src="img/open.jpeg" width="40%" />

Er is een speciaal printplaatje ontworpen die precies in het doosje past.

<img src="img/printplaat.png" width="40%" />

# Ik wil er een bouwen
In het bestand Bouwhandleiding Wonderfoon staat een handleiding van hoe je er een kunt solderen en programmeren. Met de gerberfiles kun je een printplaat bestellen. Let er goed op bij het bestellen dat je controleerd of het midden ook echt een gat wordt voor je de bestelling plaatst.
