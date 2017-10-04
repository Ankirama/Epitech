#test

.name "test"
.comment "just a basic"

add:	and 	r1, %:live,r1

live:	live 	%-1
	zjmp	%:live
