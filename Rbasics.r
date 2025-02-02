product <- function(A,B) {
  print(A * B)
}
A <- readline(prompt = "Enter first value : ")
B <- readline(prompt = "Enter second value : ")
A <- as.integer(A)
B <- as.integer(B)
product(A, B)

fruits <- c("Apple","Banana", "Orange");
fruits[4] <- c("WaterMelon")
fruits

thismatrix <- matrix(c(1,2,3,4,5,6), nrow = 3, ncol = 2)
thismatrix

thisarray <- c(1:18)
thisarray

multi <- array(thisarray, dim = c(3,3,2))
multi

data1 <- data.frame(
  training <- c("Strenght","Stamina","Other"),
  pulse <- c(100,150,120),
  duration <- c(60,30,45)
)
data1
