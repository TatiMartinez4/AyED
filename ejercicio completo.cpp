/*En una clínica se tienen los siguientes archivos:
“Medicos.dat”, SIN ORDEN, con un máximo de 100 registros. Cada registro tiene:   //no son mas de 100 medicos
- número de matrícula del médico (entero) ¡por aca se unen los dos archivos!
- nombre (30 caracteres)
- código de especialidad (1001 a 1010)  //ordeno por especialidad?

“Consultas.dat”, con un registro por cada consulta realizada en consultorios externos
el año pasado, ORDENADO POR NUMERO DE HISTORIA CLINICA DEL PACIENTE. Cada registro tiene:
- fecha (día y mes)
- número de historia clínica del paciente (entero)
- número de matrícula del médico que realizó la consulta (entero)  ¡por aca se unen los dos archivos!

Realizar un programa que:
1) Informe cantidad de consultas realizadas por cada paciente. //contador de historias clinicas iguales. Esta ordenado asi que es facil. Con un corte de control, mientras sea el mismo cuenta.
2) Informar por cada especialidad: código y cantidad de consultas de esa 
especialidad en cada mes //hay 10 especialidades nomas, pero en el segundo archivo solo tengo la matricula del medico. Hay 12 meses. Matriz contadora? 10x12  //tengo los meses en el archivo //tengo que buscar el medico para tener la especialidad //puedo hacer un vector con todo lo para no vivir recorriendo un archivo
3) Generar el archivo ”ConsultasMedico.dat” con registro por cada médico, con el siguiente diseño:
- número de matrícula del médico (entero)        //facil
- cantidad total de consultas realizadas en el año anterior.*/    //array de 100 de struc que tenga matricula y contador. Recorro el array y genero el archivo