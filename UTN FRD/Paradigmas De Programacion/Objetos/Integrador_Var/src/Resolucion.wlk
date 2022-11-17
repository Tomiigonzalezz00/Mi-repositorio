class Jugadas{
	var E
	var property tipo
	var property minutoDePartido
	var property ultimoJugador 
	var property circunstanciasEspeciales = []
	
	method sacarTarjeta(unJugador){
		unJugador.recibirTarjeta()
	}
}

object var_{
	var property modoDeFuncionamiento
	
	method terminaEnGol(jugada){
		return (jugada.circunstanciasEspeciales().size() == 0) || self.modoDeFuncionamiento().golValido(jugada)
	}
	
}

object justiciaCiego{
	var circunstancias = ["la pelota no paso completamente la linea","jugador adelantado","fue con la mano"] 
	method golValido(unaJugada) = return unaJugada.circunstanciasEspeciales().any({unaCircunstancia => circunstacias.contains(unaCircunstancia})  
}

object fifa{
	var equiposMundialistas = [] 
	method golValido(unaJugada) = return equiposMundialistas.contains(unaJugada.equipoGol())  
}

object masGoles(){
	method golValido(unaJugada) = return true 
}



class Faltas inherits Jugadas {
	var property jugadorLastimado 
	var jugadorGolpeador
	var intensidad
	
override method sacarTarjeta(){
		if (intensidad > 75)
			super(jugadorGolpeador) 
	}
	
}

class Pelea inherits Jugadas {
	var jugadoresQueIntervienen = [] 
]
	
override method sacarTarjeta(){
	if (jugadoresQueIntervienen.size() > 5 && jugadoresQueIntervienen.any({unJugador,otroJugador => unJugador.equipo() != otroJugador.equipo()}))
		jugadoresQueIntervienen.forEach({jugador => jugador.recibirTarjeta})
 } 
}


