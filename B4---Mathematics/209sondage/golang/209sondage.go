package main

import (
  "fmt"
  "math"
  "os"
  "strconv"
)

func usage() {
  fmt.Println("Usage : ./209sondage population echantillon sondage")
  os.Exit(0)
}

func check_arg(P, E, S float64) {
  if (P < E) {
    fmt.Println("Error : population inferior to echantillon !")
    usage()
  } else if (P <= 1 || E <= 1) {
    fmt.Println("Error : population and echantillon must be > 1 !")
    usage()
  } else if (S < 0) {
    fmt.Println("Error : sondage must be > 0 !")
    usage()
  }
}

func calc_var(P, E, S float64) float64 {
  return (((S / 100.0) * (1 - S / 100.0)) / E * (P - E) / (P - 1.0))
}

func print_result(P, E, S, variance, amp_95, amp_99 float64 ) {
  fmt.Printf("taille de la population :\t %0.0f\n", P)
  fmt.Printf("taille de l'echantillon :\t %0.0f\n", E)
  fmt.Printf("resultat du sondage :\t \t %.2f\n", S)
  fmt.Printf("variance estimee :\t \t %0.6f\n", variance)
  fmt.Printf("intervalle de confiance a 95%% : [%.2f%% ; %.2f%%]\n", S - amp_95, S + amp_95)
  fmt.Printf("intervalle de confiance a 99%% : [%.2f%% ; %.2f%%]\n", S - amp_99, S + amp_99)
}

func run_calc(P, E, S float64) {
  variance := calc_var(P, E, S)
  print_result(P, E, S, variance, 1.96 * math.Sqrt(variance) * 100, 2.58 * math.Sqrt(variance) * 100)
}

func main() {
  if (len(os.Args) != 4) {
    usage()
  }
  tmp1, err1 := strconv.ParseFloat(os.Args[1], 64)
  if err1 != nil {
    fmt.Println("Error:", os.Args[1], "isn't a valid number")
    usage()
  }
  P := tmp1
  tmp2, err2 := strconv.ParseFloat(os.Args[2], 64)
  if err2 != nil {
    fmt.Println("Error:", os.Args[2], "isn't a valid number")
    usage()
  }
  E := tmp2
  tmp3, err3 := strconv.ParseFloat(os.Args[3], 64)
  if err3 != nil {
    fmt.Println("Error:", os.Args[3], "isn't a valid number")
    usage()
  }
  S := tmp3
  check_arg(P, E, S)
  run_calc(P, E, S)
}
