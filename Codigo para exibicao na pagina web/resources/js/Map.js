iniciarMap = function(lati, longi, data_atualizacao) { //Parâmetros recebidos pela função para exibir na página: Latitude, Longitude e Data
    var local = { lat: lati, lng: longi } //Objeto recebe latidue e longitude para exibição
    var opcoes = {
        center: local,
        zoom: 14 //Adiciona zoom na exibição
    }

    map = new google.maps.Map(document.getElementById('map'), opcoes) //Exibe na página
    var marker = new google.maps.Marker({ //Adiciona um marcador no local exato da localização e informa a data
        position: local, //Posição do marcador
        map: map,
        title: data_atualizacao //Título
    })
}

const googleMapsScript = document.createElement('script'); //configuração de key de acesso
googleMapsScript.src = "INSERIR AQUI A KEY"; //Inserir key de acesso da API do Google Maps
document.head.appendChild(googleMapsScript);