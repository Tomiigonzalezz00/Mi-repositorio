%-------------------------------------COMIENZA BASE DE DATOS ------------------------------------------------------------------
%ciudad(ciudad, AnioFundacion, provincia).
provincia(rionegro).
provincia(bsas).
provincia(stacruz).
provincia(cordoba).




ciudad(mdq, 1876, bsas).
ciudad(bariloche, 1880, rionegro).
ciudad(viedma, 1776, rionegro).
ciudad(calafate, 1930, stacruz).
ciudad(lanus, 1888, bsas).

%alojamiento(ciudad, alojamiento, cantidad).
alojamento(bariloche, camping, 2).
alojamento(bariloche, hotel, 12).
alojamento(bariloche, hosteria, 5).
alojamento(mdq, hotel, 100).
alojamento(mdq, camping, 10).
alojamento(mdq, residencial, 5).
alojamento(mdq, hosteria, 5).
alojamento(viedma, camping, 3).
alojamento(calafate, camping, 2).
alojamento(calafate, hosteria, 3).

%Capacidad promedio de cada categoria de alojamiento
capacidad(hotel, 50).
capacidad(camping, 100).
capacidad(hosteria, 30).
capacidad(residencial, 10).

%informacion Adicional 
provinciaGrande(bsas,0.9).
provinciaPatagonica(rionegro,2010).
provinciaPatagonica(stacruz,2003).

provinciaComun(cordoba).

montoPorLugar(10).

coeficiente(comun, 1.1).
coeficiente(2010, 1.2).
coeficiente(2009, 1.4).
coeficiente(2008, 1.5).


%--------------------------------TERMINA BASE DE DATOS----------------------------------------------------------------------

%1)Realizar predicados que resuelvan lo siguiente y justificar si son inversibles o no. Mostrar ejemplos de consulta.
%A)

mismoSiglo(Anio1,Anio2) :- Anio1//100 =:= Anio2//100

tieneMasDeUnaCiudad(Provincia):- 
        provincia(Provincia).
        %ciudad(X,Anio1,Provincia),
        %ciudad(Y,Anio2,Provincia),
        %X \= Y,
        %mismoSiglo(Anio1,Anio2).

