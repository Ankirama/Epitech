//usr/local/go/bin/go run $0 $@ ; exit

package main

import (
  "fmt"
  "math"
  "os"
  "strconv"
)

func usage() {
  fmt.Println("Usage: [nombre mesures relevees] [moyenne arithmetique] [moyenne harmonique] [ecart-type]")
  os.Exit(0)
}

func ecarttype(x, y float64) float64 {
  return math.Sqrt(math.Pow(y, 2) - math.Pow(x, 2))
}

func moyenarith(x, y, value float64) float64 {
  return (y * x + value) / (x + 1)
}

func quadra(x, y, value float64) float64 {
  return math.Sqrt((math.Pow(y, 2) * x + math.Pow(value, 2)) / (x + 1))
}

func harmo(x, y, value float64) float64 {
  return ((x + 1) * value * y) / (x * value + y)
}

func print(argv [5]float64) {
  fmt.Printf("\tantal malinder [nombre mesure]: %0.0f\n", argv[0])
  fmt.Printf("\tstandardafvilgelse [ecart-type]: %0.2f\n", argv[3])
  fmt.Printf("\taritmetisk gennemsnit [moyenne arithmetique]: %0.2f\n", argv[1])
  fmt.Printf("\tkvadratik gennemsnit [moyenne quadratique]: %0.2f\n", argv[4])
  fmt.Printf("\tharmonisk gennemsnit [moyenne harmonique]: %0.2f\n", argv[2])

}

func calcul(argv [5]float64, value float64) [5]float64 {
  argv[1] = moyenarith(argv[0], argv[1], value)
  argv[4] = quadra(argv[0], argv[4], value)
  argv[2] = harmo(argv[0], argv[2], value)
  argv[3] = ecarttype(argv[1], argv[4])
  argv[0] = argv[0] + 1
  print(argv)
  return argv
}

func getIn (argv [5]float64) {
  var info string

  fmt.Printf("indtast din vaerdi : ")
  fmt.Scanf("%s", &info)
  argv[4] = math.Sqrt(math.Pow(argv[3], 2) + math.Pow(argv[1], 2))
  for info != "ende" {
    tmp, err := strconv.ParseFloat(info, 64)
    if err != nil || tmp < 0 {
      fmt.Println(info, ": not a valid number (must be positif)")
    } else {
      argv = calcul(argv, tmp)
    }
    fmt.Printf("\nindtast din vaerdi : ")
    fmt.Scanf("%s", &info)
  }
  fmt.Printf(info)
}

func main() {
  var argv [5]float64

  if len(os.Args) != 5 {
    usage()
  }
  i := 0
  for i < 4 {
    tmp, err := strconv.ParseFloat(os.Args[i + 1], 64)
    if err != nil {
      fmt.Println("Error:", os.Args[i + 1], "isn't a valid number")
      usage()
    } else if tmp < 0 {
      fmt.Println("Error:", os.Args[i + 1], "must be positif")
      usage()
    }
    argv[i] = tmp
    i += 1
  }
  getIn(argv)
}
