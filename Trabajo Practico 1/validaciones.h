/** \brief Estetica del menu, se encarga de mostrar el numero cargado en pantalla
 *          o una X o una Y segun corresponda
 * \param La bandera que indica si el numero fue cargado o no
 * \param El numero a mostrar en pantalla
 * \param El texto a mostrar en pantalla
 *
 */
void validarCarga (int,float,char[]);

/** \brief Verifica si el numero es igual a cero
 *
 * \param El numero a verificar en tipo flotante
 * \return Devuelve 0 si el numero es cero y 1 si el numero es distinto de cero
 *
 */
int validarDistintoCero (float );

/** \brief Verifica si el numero es menor a 1 y si no es entero
 *
 * \param  El numero a verificar en tipo flotante
 * \return Devuelve 0 si el numero es menor o igual a 0 o si el numero tiene peso decimal
 *         Devuelve 1 si el numero es entero mayor a 0
 */
int validarFactorial (float );

/** \brief Verifica que se hayan cargado numeros
 *
 * \param La bandera correspondiente al numero a verificar
 * \param Texto a mostrar por pantalla en cada caso en particular
 * \return Valor de tipo entero que representa a la bandera
 *         Devuelve 0 en caso de que no se haya cargado un numero y 1 en caso de que el numero este cargado
 */
int validarExistencia(int,char[]);
