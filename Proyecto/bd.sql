SELECT COUNT(`Alumno`.`matricula`) as alumnos, `Alumno`.`deporte`
FROM `proyectoSoftware`.`Alumno`
group by `Alumno`.`deporte`;

