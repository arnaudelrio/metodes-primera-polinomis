use std::io::{Write, stdin};

/*
 * Llegir polinomi de fitxer
 */
pub fn plleg() -> (i32, Option<Vec<f64>>) {
    let mut line = String::new();
    if stdin().read_line(&mut line).is_err() {
        eprintln!("plleg(): error llegint grau !!");
        return (-1, None);
    }

    let n = match line.trim().parse::<i32>() {
        Ok(val) => val,
        Err(_) => {
            eprintln!("plleg(): error llegint grau !!");
            return (-1, None);
        }
    };

    let mut vec = vec![0.0; (n + 1) as usize];

    for i in 0..=n {
        line.clear();
        if stdin().read_line(&mut line).is_err() {
            eprintln!("plleg(): error llegint coeficient !!");
            return (-3, None);
        }

        vec[i as usize] = match line.trim().parse::<f64>() {
            Ok(val) => val,
            Err(_) => {
                eprintln!("plleg(): error llegint coeficient !!");
                return (-3, None);
            }
        };
    }

    (n, Some(vec))
}

/*
 * Escriure polinomi a fitxer.
 */
pub fn pescr<W: Write>(n: i32, p: &Vec<f64>, fp: &mut W) {
    writeln!(fp, "{}", n).ok();
    for coef in p.iter().take((n + 1) as usize) {
        writeln!(fp, "{}", coef).ok();
    }
}

/*
 * Combinació lineal de polinomis.
 *
 * La funció que crida és responsable que r[] tingui lloc per
 * 1+max(m,n) coeficients.
 */
pub fn pcl(m: i32, p: &Vec<f64>, n: i32, q: &Vec<f64>, alf: f64, bet: f64, r: &mut [f64]) {
    let m_usize = (m + 1) as usize;
    let n_usize = (n + 1) as usize;

    for (i, val) in p.iter().take(m_usize).enumerate() {
        r[i] = alf * val;
    }
    for (i, val) in q.iter().take(n_usize).enumerate() {
        r[i] += bet * val;
    }
}

/*
 * Producte de polinomis.
 *
 * La funció que crida és responsable que r[] tingui lloc per
 * 1+m+n coeficients.
 */
pub fn pmul(m: i32, p: &Vec<f64>, n: i32, q: &Vec<f64>) -> Vec<f64> {
    let m_usize = (m + 1) as usize;
    let n_usize = (n + 1) as usize;
    let mut r = vec![0.0; m_usize + n_usize];

    for (i, p_val) in p.iter().take(m_usize).enumerate() {
        for (j, q_val) in q.iter().take(n_usize).enumerate() {
            r[i + j] += p_val * q_val;
        }
    }
    r
}

/*
 * Derivada d'un polinomi
 *
 * La funció que crida és responsable que dp[] tingui lloc
 * per a n coeficients.
 */
pub fn pder(n: i32, p: &Vec<f64>) -> Vec<f64> {
    let mut dp = vec![0.0; n as usize];
    for (i, val) in p.iter().skip(1).take(n as usize).enumerate() {
        dp[i] = ((i + 1) as f64) * val
    }
    dp
}

/*
 * Avaluar un polinomi.
 */
pub fn paval(n: i32, p: &Vec<f64>, x: f64) -> f64 {
    p.iter()
        .take((n + 1) as usize)
        .enumerate()
        .map(|(i, &coef)| coef * x.powi(i as i32))
        .sum()
}
