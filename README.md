# RASTREADOR ECONÔMICO UTILIZANDO O MICROCONTROLADOR ESP8266
## Caso queira uma explicação mais detalhada basta acesssar o arquivo [RELATÓRIO](https://github.com/fcoiuri/Rastreador-Utilizando-ESP8266/blob/master/RELATÓRIO.pdf)
   O projeto teve como objetivo implementar um rastreador de dispositivos eletrônicos de baixo custo. Para isso, foi utilizando um microcontrolador ESP8266, o que torna econômico por não necessitar de um módulo GPS. Além disso, permite exibir a localização do dispositivo em tempo real através do Google Maps ao programar o microcontrolador com a linguagem C.
   Também foram utilizadas as linguagens JavaScript, HTML e CSS para desenvolver uma website para visualizar a localização do dispositivo em qualquer aparelho com acesso a Internet. O armazenamento das informações sobre a localização do dispositivo foi realizada com o uso do software Firebase, um banco de dados que permite a exibição das informações em tempo real. 
   A hospedagem da website foi realizada no provedor Heroku. Esta é uma plataforma em nuvem que possibilita armazenar projetos de forma gratuita. Para a obtenção das coordenadas sem a utilização de um GPS, foi utilizada a biblioteca WiFiLocation que permite a comunicação entre duas API’s do Google Maps para obtenção da localização. As API´s são: Geolocation API e Maps JavaScript API. A Geolocation é necessária para a biblioteca WiFi Location do Arduino conseguir saber as coordenadas exatas de onde está o dispositivo, assim como a Maps JavaScript, mas ela também é necessária para a exibição na página Web. 
   Com um custo benefício muito baixo, pois em tese só é preciso comprar um microcontrolador baseado em ESP8266, o projeto trata-se de uma excelente maneira de obter a localização de algo sem se preocupar em ter despesas orçamentárias, visto que para armazenar a localização em um banco de dados e exibir em uma página web, tudo isso foi feito de forma gratuita.
## Tabela no Firebase
<font>
    <img src = "https://github.com/fcoiuri/Rastreador-Utilizando-ESP8266/blob/master/Firebase.PNG" width = "500" height =  "480" >
  </font>
 
 ## Terminal do Arduino 
 <font>
    <img src = "https://github.com/fcoiuri/Rastreador-Utilizando-ESP8266/blob/master/Codigo%20no%20Arduino/Console%20do%20Arduino.PNG" width = "500" height =  "480" >
  </font>
