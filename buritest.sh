map=('map00' 'map01' 'map02')
joueur=('abanlin.filler' 'carli.filler' 'champely.filler' 'grati.filler' 'hcao.filler' 'superjeannot.filler')
let "n_partie = 1"
let "n_map = 0"
let "n_joueur = 0"
let "joueur_max = 6"
while [ $n_joueur -lt 6 ]
do
	while [ $n_map -lt 3 ]
	do
		echo "vburidar.filler vs ${joueur[$n_joueur]} || map = ${map[$n_map]}"
		while [ $n_partie -lt 6 ]
		do 
			echo "partie $n_partie"
			./filler_vm -f maps/${map[$n_map]} -p2 players/${joueur[$n_joueur]} -p1 players/vburidar.filler | grep "fin" | sed 's/O/vburidar/g' | sed 's/X/ennemy/g' | sed 's/fin/score/g'
			let "n_partie = n_partie + 1"
		done
		let "n_partie = 1"
		let "n_map = n_map + 1"
	done
	let "n_map = 0"
	let "n_joueur = n_joueur + 1"
done
