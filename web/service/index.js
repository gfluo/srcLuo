var http = require('http');
var express = require('express');
http.createServer(function(req, res){
    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('hello world');
}).listen(9999);
///输出
console.log('Server runnning at 9999');
