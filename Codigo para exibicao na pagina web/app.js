const express = require("express") //Importa o módulo Express
const app = express() //Inicia o Express
const firebase = require("firebase") //Importa o Firebase

app.set("view engine", "ejs") //Informa que o tipo de view será no formato EJS
app.set("views", "./resources/views") //Informa o local de onde estará as views

app.use(express.static(__dirname + '/resources')) //Informa que os arquivos nesta pasta serão estáticos 
app.listen(process.env.PORT || 3000); //Porta a ser usada 

app.get("/", function(req, res) { //Renderiza no Index(/) o arquivo informado 
    res.render("index.ejs")
})