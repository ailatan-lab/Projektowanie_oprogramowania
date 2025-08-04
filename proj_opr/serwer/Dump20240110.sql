CREATE DATABASE  IF NOT EXISTS `mydb` /*!40100 DEFAULT CHARACTER SET utf8mb3 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `mydb`;
-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: localhost    Database: mydb
-- ------------------------------------------------------
-- Server version	8.0.35

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `doktorzy`
--

DROP TABLE IF EXISTS `doktorzy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `doktorzy` (
  `iddoktorzy` int NOT NULL AUTO_INCREMENT,
  `imie` varchar(45) NOT NULL,
  `nazwisko` varchar(45) NOT NULL,
  `specjalizacja` varchar(45) NOT NULL,
  `login` varchar(45) NOT NULL,
  PRIMARY KEY (`iddoktorzy`),
  UNIQUE KEY `login_UNIQUE` (`login`),
  KEY `login_dok_idx` (`login`),
  CONSTRAINT `login_dok` FOREIGN KEY (`login`) REFERENCES `uzytkownicy` (`login`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doktorzy`
--

LOCK TABLES `doktorzy` WRITE;
/*!40000 ALTER TABLE `doktorzy` DISABLE KEYS */;
INSERT INTO `doktorzy` VALUES (1,'doktor44','doktor44','doktor44','doktor44'),(2,'niebylo','niebylo','niebycie','niebylo'),(3,'nowekonto','nowekonto','nowekonto','nowekonto');
/*!40000 ALTER TABLE `doktorzy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pacjenci`
--

DROP TABLE IF EXISTS `pacjenci`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pacjenci` (
  `numer_pesel` varchar(11) NOT NULL,
  `imie` varchar(45) NOT NULL,
  `nazwisko` varchar(45) NOT NULL,
  `adres` varchar(45) NOT NULL,
  `login` varchar(45) NOT NULL,
  PRIMARY KEY (`numer_pesel`),
  UNIQUE KEY `numer pesel_UNIQUE` (`numer_pesel`),
  UNIQUE KEY `login_UNIQUE` (`login`),
  KEY `login_pac_idx` (`login`),
  CONSTRAINT `login_pac` FOREIGN KEY (`login`) REFERENCES `uzytkownicy` (`login`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pacjenci`
--

LOCK TABLES `pacjenci` WRITE;
/*!40000 ALTER TABLE `pacjenci` DISABLE KEYS */;
INSERT INTO `pacjenci` VALUES ('11111111111','pesel','peselowski','peselowa 2 peselów','rer'),('11111111116','pacjent44','pacjent44','pacjent44','pacjent44'),('12312312311','pliki','pliki','pliki','pliki'),('22222222222','podwojne','podwojne','podwojne','podwojne');
/*!40000 ALTER TABLE `pacjenci` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `przypisania_doktorow`
--

DROP TABLE IF EXISTS `przypisania_doktorow`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `przypisania_doktorow` (
  `idprzypisania_doktorow` int NOT NULL AUTO_INCREMENT,
  `id_doktora` int NOT NULL,
  `pesel_pacjenta` varchar(11) NOT NULL,
  PRIMARY KEY (`idprzypisania_doktorow`),
  KEY `doktor_idx` (`id_doktora`),
  KEY `pesel_dok_idx` (`pesel_pacjenta`),
  CONSTRAINT `doktor` FOREIGN KEY (`id_doktora`) REFERENCES `doktorzy` (`iddoktorzy`),
  CONSTRAINT `pesel_dok` FOREIGN KEY (`pesel_pacjenta`) REFERENCES `pacjenci` (`numer_pesel`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `przypisania_doktorow`
--

LOCK TABLES `przypisania_doktorow` WRITE;
/*!40000 ALTER TABLE `przypisania_doktorow` DISABLE KEYS */;
INSERT INTO `przypisania_doktorow` VALUES (1,1,'11111111111'),(2,2,'12312312311'),(3,2,'22222222222');
/*!40000 ALTER TABLE `przypisania_doktorow` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `upowaznieni`
--

DROP TABLE IF EXISTS `upowaznieni`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `upowaznieni` (
  `idupowaznieni_pesel` varchar(11) NOT NULL,
  `imie` varchar(45) NOT NULL,
  `nazwisko` varchar(45) NOT NULL,
  `adres` varchar(45) NOT NULL,
  `login` varchar(45) NOT NULL,
  PRIMARY KEY (`idupowaznieni_pesel`),
  UNIQUE KEY `idupowaznieni_pesel_UNIQUE` (`idupowaznieni_pesel`),
  UNIQUE KEY `login_UNIQUE` (`login`),
  KEY `login_upo_idx` (`login`),
  CONSTRAINT `login_upo` FOREIGN KEY (`login`) REFERENCES `uzytkownicy` (`login`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `upowaznieni`
--

LOCK TABLES `upowaznieni` WRITE;
/*!40000 ALTER TABLE `upowaznieni` DISABLE KEYS */;
INSERT INTO `upowaznieni` VALUES ('11111111114','test','test','testowy','zamykanie'),('11444111114','zamykanie22','zamykanie22','zamykanie22','zamykanie22'),('11444111334','previous2','previous2','previous2','previous2');
/*!40000 ALTER TABLE `upowaznieni` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `upowaznienia`
--

DROP TABLE IF EXISTS `upowaznienia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `upowaznienia` (
  `idupowaznienia` int NOT NULL AUTO_INCREMENT,
  `pesel_upowazniony` varchar(11) NOT NULL,
  `pesel_pacjent` varchar(11) NOT NULL,
  `czy_upowaznione` tinyint NOT NULL,
  PRIMARY KEY (`idupowaznienia`),
  KEY `pesel_upo_idx` (`pesel_upowazniony`),
  KEY `pesel_pac_idx` (`pesel_pacjent`),
  CONSTRAINT `pesel_pac` FOREIGN KEY (`pesel_pacjent`) REFERENCES `pacjenci` (`numer_pesel`),
  CONSTRAINT `pesel_upo` FOREIGN KEY (`pesel_upowazniony`) REFERENCES `upowaznieni` (`idupowaznieni_pesel`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `upowaznienia`
--

LOCK TABLES `upowaznienia` WRITE;
/*!40000 ALTER TABLE `upowaznienia` DISABLE KEYS */;
INSERT INTO `upowaznienia` VALUES (3,'11111111114','11111111116',0),(4,'11444111114','22222222222',1),(5,'11111111114','22222222222',1),(6,'11444111334','22222222222',1);
/*!40000 ALTER TABLE `upowaznienia` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `uzytkownicy`
--

DROP TABLE IF EXISTS `uzytkownicy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `uzytkownicy` (
  `id_uzytkownika` int NOT NULL AUTO_INCREMENT,
  `login` varchar(45) NOT NULL,
  `haslo` varchar(45) NOT NULL,
  `zarejestrowany` tinyint NOT NULL,
  `typ_konta` int NOT NULL,
  PRIMARY KEY (`id_uzytkownika`),
  UNIQUE KEY `login_UNIQUE` (`login`),
  UNIQUE KEY `id_uzytkownika_UNIQUE` (`id_uzytkownika`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `uzytkownicy`
--

LOCK TABLES `uzytkownicy` WRITE;
/*!40000 ALTER TABLE `uzytkownicy` DISABLE KEYS */;
INSERT INTO `uzytkownicy` VALUES (1,'test','testowe',1,0),(2,'test2','testowe2',0,0),(3,'test3','testowe3',0,0),(4,'testowanie','testowanie',0,0),(5,'gkj','ghkj',0,0),(6,'doktor','doktorowski',0,0),(7,'upo','upo',0,0),(8,'kjkjl','jhlhj',0,0),(9,'ggfhj','gfhjjkl',0,0),(10,'appa','appa',0,0),(11,'rer','rer',0,0),(12,'proste','proste',0,0),(13,'previous','previous',0,0),(14,'previous2','previous2',0,0),(15,'funcja','funcja',0,0),(16,'login_zwykly','login_zwykly',0,0),(17,'pacjent','pacjent',0,0),(18,'pacjent2','pacjent2',0,0),(19,'pacjent33','pacjent33',0,0),(20,'doktor44','doktor44',0,0),(21,'pacjent44','pacjent44',0,0),(22,'zamykanie','zamykanie',0,1),(23,'zamykanie2','zamykanie2',0,0),(24,'Pesel22','Pesel22',0,0),(25,'fgfgh33','fgfgh33',0,2),(26,'zamykanie22','zamykanie22',0,1),(28,'niebylo','niebylo',0,2),(29,'folder','folder',0,0),(30,'pliki','pliki',0,0),(31,'podwojne','podwojne',0,0),(32,'nowekonto','nowekonto',0,2);
/*!40000 ALTER TABLE `uzytkownicy` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'mydb'
--

--
-- Dumping routines for database 'mydb'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-01-10 21:43:57
