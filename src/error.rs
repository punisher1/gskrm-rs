use std::error::Error as StdError;

pub const HANDLE_NOTEXIST: &str = "gsk handle 不存在";

pub type Result<T> = std::result::Result<T, Error>;

#[derive(Debug)]
pub enum Kind {
    Communication,
    Processing,
    Parameter,
    CutterOffset,
    Macro,
    Pitch,
    Diagnose,
    File,
    Servo,
    Plc,
    Program,
    Other,
}

type BoxError = Box<dyn StdError + Send + Sync>;

#[derive(Debug)]
pub struct Error {
    kind: Kind,
    source: Option<BoxError>,
    index: Option<i32>,
}

impl Error {
    pub fn new<E>(kind: Kind, source: Option<E>, index: Option<i32>) -> Self
    where
        E: Into<BoxError>,
    {
        Error {
            kind,
            source: source.map(Into::into),
            index,
        }
    }
}
