var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
    res.sendFile(__dirname + "/public/index.html");
  ///res.render('index', { title: 'Express xx' });
});

module.exports = router;
