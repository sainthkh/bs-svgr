# bs-svgr

[svgr](https://github.com/smooth-code/svgr) for BuckleScript. It transforms SVGs to ReasonReact components. 

## Installation

We need `svgr` because `bs-svgr` wraps the components created by it. 

```sh
npm i -D bs-svgr @svgr/webpack
```

## Set up

### `bsconfig.json`

`bs-svgr` should be added under `bs-dependencies` of your `bsconfig.json` file. 

```js
{
  /* ... */
  "bs-dependencies": [
    "bs-svgr",
    "reason-react"
  ],
  /* ... */
}
```

### webpack.config.js

You can simply set it up like any other webpack loaders. 

```js
// webpack.config.js
module.exports = {
  module: {
    rules: [
      {
        test: /\.svg$/i,
        use: ['@svgr/webpack'],
      },
    ]
  },
}
```

## Example

```reason
let styles = [%raw {| require("./Loading.scss") |}]
let component = ReasonReact.statelessComponent("Loading");

open Svgr;

module SvgFile: Svg = {
  let component = req("../assets/loading.svg")
}

module Icon = SvgComponent(SvgFile);

let make = (_children) => {
  ...component,

  render: _self => {
    <Icon 
      className=styles##wrap
      style=ReactDOMRe.Style.make(~width="100", ())
    />
  }
};
```

As SvgComponent is a functor, we need a bit complicated process. If you want to know how the `styles` work, check [reason-css-modules-loader](https://github.com/sainthkh/reason-css-modules-loader).