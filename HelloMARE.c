#include	<stdio.h>	
#include	<mare/mare.h>	
	
int	main()	{		
		mare::runtime::init();															//	Initialize	MARE	runtime.	
	
		auto	hello	=	mare::create_task([]	{printf("Hello	”);});				//	Create	task	that	prints	“Hello	”	
		auto	world	=	mare::create_task([]	{printf(“World!”);});				//	Create	task	that	prints	“World!”	
	
		hello	>>	world;																//	Ensure	that	“World!”	Prints	after	“Hello	”		
	
		mare::launch(hello);															//	Launch	hello	task	
		mare::launch(world);															//	Launch	world	task	
	
		mare::wait_for(world);															//	Wait	for	world	to	complete	
	
		runtime::shutdown();															//	Shutdown	the	MARE	runtime	and	exit	
		return	0;	
}