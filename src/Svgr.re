type requiredReactClass = Js.t({.
  default: ReasonReact.reactClass,
});

[@bs.val] external req: string => requiredReactClass = "require";

module type Svg = {
  let component: requiredReactClass;
};

module SvgComponent = (File: Svg) => {
  [@bs.deriving abstract]
  type jsProps = {
    className: string,
    style: ReactDOMRe.style,
  }

  let make = (
    ~className="", 
    ~style=ReactDOMRe.Style.make(),
    children
  ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=File.component##default,
      ~props=jsProps(
        ~className,
        ~style,
      ),
      children,
    )
}