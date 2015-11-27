#TimerLABSud

english version below

TimerLABSud est une librairie permettant l'implémentation de 2 timers pour l'environnement [Energia ](http://energia.nu) L'avantage de cette librairie 
est d'utiliser les interruptions et d'appeler une fonction utilisateur lors du traitement de cette interruption.
Cette librairie a été testée avec une carte Launchpad 1294XL. 
Les timers sont référencés Timer0 et Timer1. 

##Utilisation
###set
`Timer0/1.set(uint32_t periode, void(*f)(void));`  

* periode : Intervalle de temps en millisecondes entre 2 interruption. Attention, la période maximum est de 35790 ms, soit un peu plus de 35 secondes.
* uint32_t periode, void(*f)(void)) : Nom de la fonction utilisateur. 

**exemple** 
   
`Timer0.set(1000,TraiteTimer0);`  
`...`   
`void TraiteTimer(void)`  
`{`  
`...`  
`}`  

###start
`Timer0/1.start(void)`  

Cette fonction permet de démarrer le timer et de valider les interruptions du timer sélectionné

###stop
`Timer0/1.stop(void)`  

Cette fonction permet d'arrêter le timer et de masquer les interruptions du timer sélectionné

TimerLABSud is a library allowing the implementation of two timers for the environment [Energia] (http://energia.nu) The advantage of this library
is to use interrupts and call callback (user function) when processing the interruption.
This library has been tested with Launchpad 1294XL card.
The timers are referenced Timer0 and Timer1.

##Use
###set
`Timer0/1.set (uint32_t period, void (* f) (void));`

* Period: Time interval in milliseconds between 2 interruption. Please note that the maximum period is 35 790 ms, or a little over 35 seconds.
* Uint32_t period, void (* f) (void)): Name of the user function.

**example**
   
`Timer0.set (1000 TraiteTimer0); '
`...`
`TraiteTimer void (void)`
`` {
`...`
``}

### start
`Timer0/1.start (void)`

This function allows you to start the timer and validate the selected timer interrupts

###stop
`Timer0/1.stop (void)`

This function will stop the timer and hide the timer interrupts selected