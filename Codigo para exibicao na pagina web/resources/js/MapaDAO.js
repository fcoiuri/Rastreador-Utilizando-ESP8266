// Inicialização Firebase
firebase.initializeApp({
    //Inserir dados de acesso do Firebase (apiKey, authDomain, databaseURL, projectId, storageBucket, messagingSenderId, appId e measurementId)
});
const analytics = firebase.analytics();

var referencia = firebase.database().ref("Usuario1") //Tabela a qual será utilizada
referencia.on('value', function(dataSnapshot) {
    var lati = dataSnapshot.val().latitude //Carregando valor da latitude
    var longi = dataSnapshot.val().longitude //Carregando valor da longitude
    var pegar_data = dataSnapshot.val().ultima_atualizacao //Carregando valor da data
    iniciarMap(parseFloat(lati), parseFloat(longi), pegar_data) //Enviando parâmetros a função responsável por mostrar o mapa

})