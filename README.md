# Proyecto-SO-2016
Proyecto de Sistemas Operativos de Sincronizacion entre Procesos

<div style="text-align:center;">
![Alt text](http://g.gravizo.com/g?
  digraph G {
    size ="4,4";
    "servicio tecnico" [shape=box];
    "servicio tecnico" -> supervisor [weight=8];
    cajeras -> "servicio tecnico";
    supervisor -> proveedor;
    proveedor -> supervisor;
    supervisor -> guardia;
    guardia -> "servicio tecnico";
    supervisor -> reponedores;
  }
)
</div>
