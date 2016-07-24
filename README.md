# Proyecto-SO-2016
Proyecto de Sistemas Operativos de Sincronizacion entre Procesos

![Alt text](http://g.gravizo.com/g?
  digraph G {
    size ="4,4";
    "servicio tecnico";
    "servicio tecnico" -> supervisor [weight=8];
    cajeras -> "servicio tecnico";
    supervisor -> proveedor;
    proveedor -> supervisor;
    supervisor -> guardia;
    guardia -> "servicio tecnico";
    supervisor -> reponedores;
    "servicio tecnico" -> mercadeo;
    mercadeo -> supervisor;
    guardia -> cliente;
    supervisor -> reponedor;
    limpieza;
    cliente -> cajeras;
  }
)
