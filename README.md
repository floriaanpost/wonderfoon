# V3 is klaar!
Omdat ik zelf ook weer plezier kreeg in het project heb ik v3 gemaakt. Helaas (nog) geen DTMF, maar wel betere stabiliteit (minder vaak/nooit fouten met pulsen tellen) en makkelijker om de firmware te updaten (ISCP port). Ook zit er een LED op het board voor debugging (of om te laten zien dat hij aan staat). Er zijn ook weer printplaten, dus bij interesse, stuur even een mailtje naar: floriaan@tutamail.com.

Ik hoop dat het met deze versie gemakkelijker en leuker wordt voor mensen om te experimenteren met de code en het precies zo te maken als je zelf wil.

Heb je nog een oude versie, dan kun je wel de firmware gebruiken van v3 (alleen in wonderfoon.ino moet je OLD_PIN_CONFIG uncommenten), of anders kun je alles van v2 nog terugvinden in de v2 branch.

Verder valt het mij op dat mensen het lastig vinden om de Attiny te programmeren. Mocht dit je tegenhouden dan kan ik eventueel ook voorgeprogrammeerde chips opsturen, en vaak heb ik ook nog wel andere onderdelen liggen, en als je heel graag een wonderfoon wil, maar je kunt niet solderen, dan wil ik er misschien zelfs wel een voor je in elkaar solderen. Vraag even naar de mogelijkheden op de mail :)

# Wonderfoon mini
De Wonderfoon is een ouderwetse draaischijftelefoon waar je muziek te horen krijgt door de hoorn als je een nummer draait. Het is oorspronkelijk bedacht als "speelgoed" voor (demente) ouderen door Leo Willems. De ouderwetse telefoon uit hun jonge jaren, gecombineerd met muziek uit dezelfde tijd is vaak en leuke ervaring voor ouderen. Het oorspronkelijke idee is gemaakt met een Raspberry Pi (een soort kleine computer). Voor het oorspronkelijke plan moet de telefoon (onherstelbaar) gesloopt worden. Met inspiratie van [een project van Jan Derogee (TeleJukebox)](https://github.com/JanDerogee/TeleJukebox) heb ik een nieuw type Wonderfoon ontworpen. Hierbij hoeft de telefoon niet gesloopt te worden en kun je de stekker van de telefoon gemakkelijk in een doosje stoppen dat zich gedraagt als de telefooncentrale. Ook is de Raspberry Pi vervangen door een kleine mp3 speler (DFPlayer Mini) en een microcontroller (ATTiny85).

# Foto's
De complete wonderfoon is in een klein doosje gestopt wat een standaard doosje is dat gemaakt wordt door Kopp en Q-link. Het printpaatje is zo ontworpen dat het precies past.

<img src="img/dicht.jpeg" width="40%" />

Als je het doosje openschroeft zie je het volgende:

<img src="img/open.jpeg" width="40%" />

Er is een speciaal printplaatje ontworpen die precies in het doosje past.

<img src="img/printplaat.png" width="40%" />

# Ik wil er een bouwen
In het bestand Bouwhandleiding Wonderfoon staat een handleiding van hoe je er een kunt solderen en programmeren. Met de gerberfiles kun je een printplaat bestellen. Let er goed op bij het bestellen dat je controleert of het midden ook echt een gat wordt voor je de bestelling plaatst. Ik heb ook nog behoorlijk wat printplaatjes liggen, dus je kunt ze ook bij mij bestellen.

# Componentenlijst
Ik kreeg de vraag waar je de componenten kunt kopen. Hieronder een voorbeeld. Dit is zonder enige twijfel niet de goedkoopste optie, maar het kan je in ieder geval helpen met de juiste componenten vinden:

- Attiny85: https://opencircuit.nl/Product/ATtiny85-DIP8
- DFPlayer mini: https://opencircuit.nl/Product/DFPlayer-Een-mini-mp3-speler-voor-Arduino
- Header pins (ICSP): https://opencircuit.nl/Product/Male-header-2x40-2.54mm-zwart
- USB type B connector: https://www.conrad.nl/p/econ-connect-usbbu1bn-usb-connector-bus-inbouw-horizontaal-wit-1-stuks-1883654
- 10 uF elco: https://opencircuit.nl/Product/10uF-35V-Condensator-elektrolytisch
- 1 uF elco: https://opencircuit.nl/Product/1uF-450V-Condensator-elektrolytisch
- LED (optioneel): https://opencircuit.nl/Product/Rood-5mm-diffuse-LED-10-stuks
- 10 kOhm weerstand: https://opencircuit.nl/Product/10K%CE%A9-Metaalfilm-weerstand-1-4W-10-stuks
- 220 Ohm weerstand: https://opencircuit.nl/Product/220%CE%A9-Metaalfilm-weerstand-1-4W-10-stuks
- 2.7 kOhm (dit is 2kOhm, maar dat is ook wel prima): https://opencircuit.nl/Product/2K%CE%A9-Metaalfilm-weerstand-1-4W-10-stuks
