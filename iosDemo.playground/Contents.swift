//: Playground - noun: a place where people can play

import UIKit

// Finding mean, median, and mode of a set of numbers
func meanMedianMode(numbers: Int...) -> (mean: Double, median: Int, mode: Int) {
    // find mean
    var sum = 0.0
    for number in numbers {
        sum += Double(number)
    }
    let mean = sum / Double(numbers.count)
    
    // find median
    let median = numbers.sorted(<) [numbers.count  / 2]
    
    // find mode
    var occurrences: [Int : Int] = [:]
    for number in numbers {
        if var value = occurrences[number] {
            occurrences[number] = ++value
        } else {
            occurrences[number] = 1
        }
    }
    var highestPair: (key: Int, value: Int) = (0, 0)
    for (key, value) in occurrences {
        highestPair = (value > highestPair.value) ? (key, value) : highestPair
    }
    let mode = highestPair.key
    
    // return tuple of results
    return (mean, median, mode)
}

let mmm = meanMedianMode(11, 2, 13, 15, 0, 15, 15, 12,26)
print("Mean is: \(mmm.mean)")
print("Median is: \(mmm.median)")
print("Mode is: \(mmm.mode)")
//mmm.mean
//mmm.median
//mmm.mode