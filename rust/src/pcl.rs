use std::env;
use std::io::{self, Write, stderr, stdin};
use std::process;

use pol::{pcl, pescr, plleg};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 3 {
        writeln!(stderr(), "./pcl alf bet").unwrap();
        process::exit(-1);
    }

    let alf: f64 = match args[1].parse() {
        Ok(val) => val,
        Err(_) => {
            writeln!(stderr(), "./pcl alf bet").unwrap();
            process::exit(-1);
        }
    };

    let bet: f64 = match args[2].parse() {
        Ok(val) => val,
        Err(_) => {
            writeln!(stderr(), "./pcl alf bet").unwrap();
            process::exit(-1);
        }
    };

    let (n1, p1) = match plleg() {
        Ok(result) => result,
        Err(_) => {
            writeln!(stderr(), "pcl: error llegint el primer polinomi!").unwrap();
            process::exit(-2);
        }
    };

    let (n2, p2) = match plleg(&mut stdin()) {
        Ok(result) => result,
        Err(_) => {
            writeln!(stderr(), "pcl: error llegint el segon polinomi!").unwrap();
            process::exit(-2);
        }
    };

    let n3 = if n2 >= n1 { n2 } else { n1 };
    let mut p3 = vec![0.0; n3 + 1];

    pcl(n1, &p1, n2, &p2, alf, bet, &mut p3);
    pescr(n3, &p3, &mut io::stdout());

    process::exit(0);
}
