use std::error::Error as StdError;
use std::fmt;

pub const HANDLE_NOTEXIST: &str = "gsk handle 不存在";

pub type Result<T> = std::result::Result<T, Error>;

#[derive(Debug)]
pub enum Kind {
    /// 通信管理接口
    Communication,
    /// 实时加工信息
    Processing,
    /// 参数读写
    Parameter,
    /// 刀补读写
    CutterOffset,
    /// 宏变量读写
    Macro,
    /// 螺距补偿读写
    Pitch,
    /// 诊断数据与报警信息
    Diagnose,
    /// 获取文件信息
    File,
    /// 伺服数据传输
    Servo,
    /// PLC读写
    Plc,
    /// 程序加载
    Program,
    /// 其它
    Other,
}

type BoxError = Box<dyn StdError + Send + Sync>;

pub struct Error {
    inner: Box<Inner>,
}

struct Inner {
    kind: Kind,
    source: Option<BoxError>,
    error: Option<i32>,
}

impl Error {
    pub fn new<E>(kind: Kind, source: Option<E>, error: Option<i32>) -> Self
    where
        E: Into<BoxError>,
    {
        Error {
            inner: Box::new(Inner {
                kind,
                source: source.map(Into::into),
                error,
            }),
        }
    }
}

impl fmt::Debug for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        // f.debug_struct("Error").field("inner", &self.inner).finish()
        let mut builder = f.debug_struct("gskrm::Error");

        builder.field("kind", &self.inner.kind);

        if let Some(ref error) = self.inner.error {
            builder.field("error", error);
        }

        if let Some(ref source) = self.inner.source {
            builder.field("source", source);
        }

        builder.finish()
    }
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self.inner.kind {
            Kind::Communication => f.write_str("通讯管理错误")?,
            Kind::Processing => f.write_str("实时加工信息错误")?,
            Kind::Parameter => f.write_str("参数读写错误")?,
            Kind::CutterOffset => f.write_str("刀补读写错误")?,
            Kind::Macro => f.write_str("宏变量读写错误")?,
            Kind::Pitch => f.write_str("螺距补偿读写错误")?,
            Kind::Diagnose => f.write_str("诊断报警信息错误")?,
            Kind::File => f.write_str("获取文件信息错误")?,
            Kind::Servo => f.write_str("伺服数据传输错误")?,
            Kind::Plc => f.write_str("PLC读写错误")?,
            Kind::Program => f.write_str("程序加载错误")?,
            Kind::Other => f.write_str("未知错误")?,
        }

        if let Some(ref e) = self.inner.source {
            write!(f, ": {}", e)?;
        }

        Ok(())
    }
}

// constructors

pub(crate) fn communication<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Communication, Some(e), Some(error))
}

pub(crate) fn processing<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Processing, Some(e), Some(error))
}

pub(crate) fn parameter<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Parameter, Some(e), Some(error))
}

pub(crate) fn cutterOffset<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::CutterOffset, Some(e), Some(error))
}

pub(crate) fn macro_<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Macro, Some(e), Some(error))
}

pub(crate) fn pitch<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Pitch, Some(e), Some(error))
}

pub(crate) fn diagnose<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Diagnose, Some(e), Some(error))
}

pub(crate) fn file<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::File, Some(e), Some(error))
}

pub(crate) fn servo<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Servo, Some(e), Some(error))
}

pub(crate) fn plc<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Plc, Some(e), Some(error))
}

pub(crate) fn program<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Program, Some(e), Some(error))
}

pub(crate) fn other<E: Into<BoxError>>(e: E, error: i32) -> Error {
    Error::new(Kind::Other, Some(e), Some(error))
}
