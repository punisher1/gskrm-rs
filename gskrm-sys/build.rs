use std::env;
use std::path::PathBuf;

fn main() {
    bindgen_ffi("gskrm");
}

fn bindgen_ffi(lib: &str) {
    let out_dir = env::var("OUT_DIR").unwrap();
    println!("cargo:rustc-link-lib={}", lib);

    println!("cargo:rerun-if-changed={}.h", lib);
    let bindings = bindgen::Builder::default()
        .header(format!("{}.h", lib))
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(out_dir);
    bindings
        .write_to_file(out_path.join(format!("{}.rs", lib)))
        .expect("Couldn't write bindings!");
}
