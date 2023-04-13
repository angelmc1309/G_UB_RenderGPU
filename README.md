# RenderGPU

This repository contains the code developed as part of the subject of Computer Graphics in Universitat de Barcelona.

Segona pràctica de GiVD 2020-21

    Ángel Morales Carrasco NIUB 20150546
    Eric Duque Martín NIUB 20150443
    Oriol Saguillo González NIUB 20150502
    María Isabel González Sánchez NIUB 20221913
    
## **Abstract**

Per aquesta pràctica, hem pogut adaptar la Pràctica 1 i desenvolupar tota la part obligatòria de la Pràctica 2 (Fase 1). A més, hem implementat alguns opcionals de la Fase 1 i de la Fase 2. Ens hem repartit la feina de manera equitativa i proporcional a les aptituds de cada membre del grup: les parts més teòriques han sigut per l'Oriol, les parts més pràctiques per l'Àngel i l'Eric i la part més "artística" ha sigut per la Maribel.

Encara que cadascun ha treballat de forma més individual, tots hem avançat al nostre ritme fins a la setmana anterior a l'entrega. Arribat aquest punt, ens hem posat tot d'acord per repartir-nos la feina que encara quedava i decidir quins opcionals eren més interessants i útils per l'escena. Tot i això, estem molt contents del resultat de la pràctica en general, dels posts que hem fet als issues del projecte per explicar certes fases de la pràctica i dels testeos que hem fet per triar una escena pel padlet.

## **Features**

- Fase 1
    - Adaptació a la lectura de fitxers de dades
        - [x] Objectes: Eric, Angel
        - [x] Escenes virtuals: Eric
        - [x] Escenes de dades Reals: Eric, Angel
    - Material: Oriol
    - Light
        - [x] Puntual: Oriol
        - [x] Direccional: Oriol
        - [x] Spotlight: Oriol, María Isabel
        - [x] Ambient Global: Oriol
    - Shading
        - [X] Phong: María Isabel
        - [X] Gouraud: Maria Isabel
    - Textures
        - [x] Textura com material en un objecte: Eric, Angel
        - [x] Textura al pla base: Eric, Angel
        

- Fase 2 (OPT)
    - [x] Toon-shading i èmfasi de siluetes: María Isabel
    - [ ] Mapping indirecte de textures
    - [x] Animacions amb dades temporals: Oriol 
    - [x] Normal mapping: Angel
    - [ ] Entorn amb textures
    - [ ] Reflexions
    - [ ] Transparencias via objectes.
    - [ ] Transparencias via environmental mapping.


## **Extensions**

Hem afegit un nou botó a la window: "Carregar Animated Scene". Parlarem més endavant d'ell, però, en poques paraules, serveix per carregar el contingut de l'escena de la classe DataAnimation.

<p align="center">
  <img width="300" height="250" src=https://user-images.githubusercontent.com/57969201/119395286-93e03d80-bcd3-11eb-8b89-893fe9c59ef8.png>
</p>


## **Memòria**

*(NOTA: Explicació només dels diferents punts que heu desenvolupat i funcionen, detallant les estratègies que heu fet servir)*
### **_FASE 1_**


#### *PAS 1*
Per fer el pas 1, hem hagut d'importar classes de la pràctica anterior, ja que ja estava implementat el mapping de les dades reals. Hem netejat el codi innecessari, com el suport de diferents objectes, ja que en aquesta pràctica només hi existeix un tipus: brObject (ara Object). També hem hagut d'implementar la translació i l'escalament dels objectes (no els teníem dels brObjects), així com la implementació del terra i el posicionament dels objectes sobre aquest terra utilitzant la capsa contenidora.

Per carregar les escenes, hem reutilitzat la idea de l'anterior pràctica: mitjançant un fitxer amb la configuració de l'escena (configMapping) i un fitxer on cada línia representa el path del objecte i/o la seva textura, afegim aquests objectes a l'escena.

Com a guia:

- Per poder carregar una escena virtual: File -> Obre escena -> configMapping.txt -> virtualScene1.txt
- Per poder carregar dades: File -> Obre dades -> configMappingData.txt -> data10.txt

#### *PASOS 2 I 3*
En el desenvolupament dels passos 2 i 3, l'estratègia va ser molt semblant entre ells. Primer de tot, llegim el pas a pas del guió. En ambdós casos, vam tenir problemes amb l'enviament de les dades als shaders i, per tant, vam haver de tornar a fer els passos de mica en mica.

Un dels problemes més grans va ser que, per defecte, el codi venia amb un "include vec.h" a la classe de la llum que feia que no funcionés res, ja que se superposaven els imports vec.h de la classe i el vec.h de la llibreria importada. Vam arreglar aquest error amb el Ricardo a Laboratori.

A l'hora de testejar que l'enviament era correcte, vam posar el color de sortida com el vector que estàvem enviant. Per exemple, si el vector era vec4(1.0, 0.0, 0.0, 1.0), en carregar l'esfera s'hauria de veure vermella. Aquesta forma de testejar va ser tant pel pas 2 com 3.

#### *PAS 4*
Per aquest penúltim pas de la Fase 1, ens hem centrat a entendre el funcionament dels shaders i com es passa la informació del GLWidget als vèrtex shaders i fragment shaders. Primer de tot, vam calcular les normals normalitzades i l'observador, passant un uniform vec4 observer. Un cop fet això, hem definit tots els arxius glsl a la carpeta "resources" pels shaders: Gouraud fshader i vshader, Phong fshader i vshader i Toon fshader i vshader. Després ens hem focalitzat en el Gouraud Shading que, igual que els altres 3, haurà de calcular Blinn Phong segons els tipus de llums que té l'escena (Puntual, Direccional, Spot). Vam començar per la llum puntual, ja que és la més senzilla de les 3 i vam fer els càlculs, un a un, de la difusa, a l'especular, l'ambiental i la global. A més, vam testejar diferents materials i ens vam quedar amb el material de testeo que hi ha al campus.

Un cop aconseguit el Gouraud Shading amb la llum puntual, vam fer la llum direccional i per última la llum de tipus Spot seguint el mateix procediment. Després, vam implementar el Phong Shading, on els càlculs principals del shader tenen lloc al fragment shader, a diferència del Gouraud Shading que els fa al vertex shader.

#### *PAS 5*
Per realitzar el pas de les textures primerament, amb molt de compte hem anat modificant els mètodes de object per poder enviar les textures a gpu (drawtexture(),toGPUTexture()). Una vegada creiem que hem realitzat bé aquesta part hem programat uns shaders molt simples, que simplement posaven a cada punt la textura sense Phong ni cap il·luminació (vshaderText i fshaderText). Una vegada hem aconseguit veure la textura plana, amb molt de compte hem copiat els shaders de Phong i canviat la component difusa del material per la de la textura. D'aquesta manera ja podíem visualitzar les textures amb Phong.

### **_FASE 2_**

En aquesta part, parlarem dels opcionals desenvolupats al llarg de la pràctica.

#### *TOON SHADING I ENFASIS DE SILUETES*
Seguint el procediment explicat al Pas 4 de la Fase 1, per fer el Toon Shading (Part 1 de l'opcional), ens vam inspirar en el Phong Shading. Igual que aquest tipus de Shading, els càlculs principals de la llum de l'escena es fan al fragment shader en comptes del vertex shader. Per tant, vam inicialitzar el fshader de la mateixa forma que al Phong Shading. La diferència és que els colors difusos dels càlculs, ja sigui per la llum de tipus Puntual, Direccional o Spot, tindran 4 colors possibles. És a dir, segons un paràmetre anomenat "intensitat" imposarem que el color difús de l'escena en els píxels sigui un dels 4. Aquest paràmetre és el cosinus de l'angle entre la direcció de la llum i la seva normal. 
Per tant, com més gran sigui el resultat del cosinus (entre 0 i 1), més fosc serà el to del color i com més petit, més clar el color. Això ens dóna com a resultat, una imatge amb 4 tons del mateix color i canvis entre ells molt bruscos.Per això, tenim la segona part de l'opcional. Aquesta fa èmfasis en les siluetes i els colors difusos del material de l'objecte a projectar. Per això, només cal substituir el vector difús de la part anterior per la multiplicació del component difús del material i la intensitat prèviament calculada. Amb aquest càlcul, la transició de colors millora considerablement.

#### *ANIMACIONS*
En el desenvolupament de les animacions se'ns donava bastant codi ja implementat. En aquest cas, a l'hora de fer el desenvolupament, primer hem creat la classe DataAnimation per crear les escenes d'animació amb les transformacions geomètriques corresponents. Seguidament, vam crear un botó extra en el menú per poder carregar aquesta escena i evitar conflictes de codi amb els altres botons, com per exemple "Save and Start Animation". El mètode associat a aquest botó el trobarem a la classe Builder amb el nom saveAnimationScene. Aquí apliquem l'escena que vulguem dins de DataAnimation per carregar l'escena. Per últim en el mètode setFrame haurem de posar el mètode toGpu per tal que s'actualitzi l'escena a la GPU.

#### *NORMAL MAPPING*
Per programar el normal mapping, primerament hem canviat els shaders que teníem abans que aplicaven una textura canviant la component difosa, per uns que deixaven la component difosa sempre en blanc i multiplicaven les components de les normals pels valors de les textures. Fent això, una vegada executem, veiem com tenim carregat un objecte, en el nostre cas hem utilitzat un model de Júpiter i observem que el color de l'objecte és blanc, però veiem un "relleu" quan s'il·lumina la figura que ens indica que estem fent normal mapping correctament. Ara toca modificar els mètodes addTexture() de GLwidget, perquè quan afegim un fitxer de textura puguem afegir un fitxer de textura associat que conté les normals. Ara modifiquem el mètode toGPU(), per poder passar dues textures al shaderPhongTextNormal. Per últim modifiquem els shaders creats anteriorment per poder modificar la component difusa amb la primera textura i la normal amb la segona.

## **Screenshots**

*(NOTA: Per a cada pas de l'enunciat (del 1 al 6), incloure captures de pantalla de les proves que heu fet per a demostrar la funcionalitat de la vostra pràctica amb explicacions de la seva configuració i com les heu aconseguides)*

#### PAS 1:

- Per poder carregar una escena virtual: File -> Obre escena -> configMapping.txt -> virtualScene1.txt

<p align="center">
  <img width="600" height="500" src=https://user-images.githubusercontent.com/55766197/119390220-07328100-bccd-11eb-964c-ec091f55d624.png>
</p>

- Per poder carregar dades: File -> Obre dades -> configMappingData.txt -> data10.tx

<p align="center">
  <img width="600" height="500" src=https://user-images.githubusercontent.com/55766197/119390346-32b56b80-bccd-11eb-8b94-38b06777f320.png>
</p>

#### PAS 2:
- Per comprobar que el material arriba correctament asignem a la component ambiental (1.0, 0.0, 0.0, 1.0) i asignem aquesta component al colorOut del shader:

<p align="center">
  <img width="500" height="500" src=https://user-images.githubusercontent.com/47833532/119391178-5331f580-bcce-11eb-85d6-2230745b0754.png>
</p>

#### PAS 3:
- Aquest es fa de forma analoga com el pas 2, la captura es una comprovació de la llum ambient global:

<p align="center">
  <img width="800" height="500" src=https://user-images.githubusercontent.com/47833532/119391337-82e0fd80-bcce-11eb-88b8-e9750d94b539.png>
</p>

#### PAS 4:
Aquest Pas está molt més explicat al segünt apartat, però aquí hi ha unes imatges per veure el funcionament dels shaders:
La llum per les següents proves estarà amb els parámetres:
```
    this->lightPosition = vec4(1.0, 1.0, 2.0, 1.0);
    this->ambiental = vec3(0.2, 0.2, 0.2);
    this->diffuse = vec3(0.8, 0.8, 0.8);
    this->specular = vec3(1.0, 1.0, 1.0);
    this->coeficients = vec3(0.0, 0.2, 0.8);
    this->typo = t;
    this->direction = vec3(1.0, 0.0, 0.5);
    this->angle = 10.40;
```
El material per les següents proves estarà amb els paràmetres:
```
    this->ambiental = vec4(0.2, 0.2, 0.2, 1.0);
    this->diffuse = vec4(0.8, 0.5, 0.5, 1.0);
    this->specular = vec4(0.5, 0.5, 0.5, 1.0);
    this->shiness = 20.0;
```
- Gouraud Shader, amb llum Direcccional, l'obj Bunny.
<p align="center">
  <img width="600" height="500" src=https://user-images.githubusercontent.com/57969201/119397028-e9b5e500-bcd5-11eb-86ce-27fed68cf308.png>
</p>

- Phong Shader, amb la llum Puntual, l'obj Armadillo
<p align="center">
  <img width="600" height="500" src=https://user-images.githubusercontent.com/57969201/119398356-bbd1a000-bcd7-11eb-8082-69367289dda0.png>
</p>

- Toon Shader, amb la llum Spot, l'obj capsule
<p align="center">
  <img width="600" height="500" src=https://user-images.githubusercontent.com/57969201/119398823-677af000-bcd8-11eb-9afb-fb55e820ff01.png>
</p>

#### PAS 5:
- Cruiser amb la seva textura: File -> Obrir fitxer.obj -> cruiser.obj -> Texture (abaix entre transformation i point light) -> Browse -> cruiser.bmp -> Textures(adalt) -> PhonText
<p align="center">
    <img width="600" height="500" src=https://user-images.githubusercontent.com/55766197/119399580-5c748f80-bcd9-11eb-97fa-1dac07d8c290.png>
</p>
-Boca d'incendis(agafada d'internet amb blender) amb la seva textura: File -> Obrir fitxer.obj -> fire.obj -> Texture (abaix entre transformation i point light) -> Browse -> fire.png -> Textures(adalt) -> PhonText
<p align="center">
    <img width="600" height="500" src=https://user-images.githubusercontent.com/52278195/119401821-5af89680-bcdc-11eb-8ee5-f4c42c049a66.png>
</p>

#### FASE 2 (OPCIONALS):
- Exemple de normal mapping. Per veure-ho hem d'activar els shaders amb textura i normal a GLWidget i treure els que nomes tenen textura. File -> Obrir fitxer.obj -> JUPITER.obj -> Texture (abaix entre transformation i point light) -> Browse -> jupiter.png -> Textures(adalt) -> PhonText:
<p align="center">
    <img width="600" height="400" src=https://user-images.githubusercontent.com/52278195/119401692-208ef980-bcdc-11eb-9e33-67b67ec36e7d.png>
</p>    

- Animació amb jupiter.obj(agafat d'internet), que té textura i normal mapping. Per fer l'animació hem jugat amb una TG que mou l'objecte a una velocitat constant, hem situat la camera propera al planeta i fet un zoom out:
<p align="center">
    <img width="600" height="400" src=https://user-images.githubusercontent.com/52278195/119401170-6dbe9b80-bcdb-11eb-8ff9-87b3faec965f.gif>
</p> 




## **Additional Information**

Para información más detallada, hay varios issues abiertos sobre el desarrollo de las partes del proyecto:
- Parte 4: Shaders i opcional Toon en "Progreso del Paso 4" issue https://github.com/GiVD2020/rendergpu-c02/issues/8
- Parte 5: Textures i proves con Blender en "Paso 5 texturas" issue https://github.com/GiVD2020/rendergpu-c02/issues/11
