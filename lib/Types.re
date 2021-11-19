[@deriving yojson]
type empty;

type assoc = list((string, string));
let assoc_of_yojson =
  fun
  | `Assoc(l) => {
      l |> List.map(((key, value)) => (key, string_of_yojson(value)));
    }
  | _ => [];

let yojson_of_assoc = assoc => {
  `Assoc(
    assoc |> List.map(((key, value)) => (key, yojson_of_string(value))),
  );
};

module rec Accessibility: {
  module rec AXNodeId: {
    /* Unique accessibility node identifier. */
    [@deriving yojson]
    type t = string;
  }
  and AXValueType: {
    type _axvaluetype = [
      | `boolean
      | `tristate
      | `booleanOrUndefined
      | `idref
      | `idrefList
      | `integer
      | `node
      | `nodeList
      | `number
      | `string
      | `computedString
      | `token
      | `tokenList
      | `domRelation
      | `role
      | `internalRole
      | `valueUndefined
    ];
    let _axvaluetype_of_yojson: Yojson.Basic.t => _axvaluetype;
    let yojson_of__axvaluetype: _axvaluetype => Yojson.Basic.t;
    /* Enum of possible property types. */
    [@deriving yojson]
    type t = _axvaluetype;
  }
  and AXValueSourceType: {
    type _axvaluesourcetype = [
      | `attribute
      | `implicit
      | `style
      | `contents
      | `placeholder
      | `relatedElement
    ];
    let _axvaluesourcetype_of_yojson: Yojson.Basic.t => _axvaluesourcetype;
    let yojson_of__axvaluesourcetype: _axvaluesourcetype => Yojson.Basic.t;
    /* Enum of possible property sources. */
    [@deriving yojson]
    type t = _axvaluesourcetype;
  }
  and AXValueNativeSourceType: {
    type _axvaluenativesourcetype = [
      | `description
      | `figcaption
      | `label
      | `labelfor
      | `labelwrapped
      | `legend
      | `rubyannotation
      | `tablecaption
      | `title
      | `other
    ];
    let _axvaluenativesourcetype_of_yojson:
      Yojson.Basic.t => _axvaluenativesourcetype;
    let yojson_of__axvaluenativesourcetype:
      _axvaluenativesourcetype => Yojson.Basic.t;
    /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
    [@deriving yojson]
    type t = _axvaluenativesourcetype;
  }
  and AXValueSource: {
    /* A single source for a computed AX property. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: AXValueSourceType.t, /* What type of source this is. */
      [@yojson.option] [@key "value"]
      value: option(AXValue.t), /* The value of this property source. */
      [@yojson.option] [@key "attribute"]
      attribute: option(string), /* The name of the relevant attribute, if any. */
      [@yojson.option] [@key "attributeValue"]
      attributeValue: option(AXValue.t), /* The value of the relevant attribute, if any. */
      [@yojson.option] [@key "superseded"]
      superseded: option(bool), /* Whether this source is superseded by a higher priority source. */
      [@yojson.option] [@key "nativeSource"]
      nativeSource: option(AXValueNativeSourceType.t), /* The native markup source for this value, e.g. a <label> element. */
      [@yojson.option] [@key "nativeSourceValue"]
      nativeSourceValue: option(AXValue.t), /* The value, such as a node or node list, of the native source. */
      [@yojson.option] [@key "invalid"]
      invalid: option(bool), /* Whether the value for this property is invalid. */
      [@yojson.option] [@key "invalidReason"]
      invalidReason: option(string) /* Reason for the value being invalid, if it is. */,
    };
  }
  and AXRelatedNode: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "backendDOMNodeId"]
      backendDOMNodeId: DOM.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
      [@yojson.option] [@key "idref"]
      idref: option(string), /* The IDRef value provided, if any. */
      [@yojson.option] [@key "text"]
      text: option(string) /* The text alternative of this node in the current context. */,
    };
  }
  and AXProperty: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: AXPropertyName.t, /* The name of this property. */
      [@key "value"]
      value: AXValue.t /* The value of this property. */,
    };
  }
  and AXValue: {
    /* A single computed AX property. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: AXValueType.t, /* The type of this value. */
      [@yojson.option] [@key "value"]
      value: option(string), /* The computed value of this property. */
      [@yojson.option] [@key "relatedNodes"]
      relatedNodes: option(list(AXRelatedNode.t)), /* One or more related nodes, if applicable. */
      [@yojson.option] [@key "sources"]
      sources: option(list(AXValueSource.t)) /* The sources which contributed to the computation of this property. */,
    };
  }
  and AXPropertyName: {
    type _axpropertyname = [
      | `busy
      | `disabled
      | `editable
      | `focusable
      | `focused
      | `hidden
      | `hiddenRoot
      | `invalid
      | `keyshortcuts
      | `settable
      | `roledescription
      | `live
      | `atomic
      | `relevant
      | `root
      | `autocomplete
      | `hasPopup
      | `level
      | `multiselectable
      | `orientation
      | `multiline
      | `readonly
      | `required
      | `valuemin
      | `valuemax
      | `valuetext
      | `checked
      | `expanded
      | `modal
      | `pressed
      | `selected
      | `activedescendant
      | `controls
      | `describedby
      | `details
      | `errormessage
      | `flowto
      | `labelledby
      | `owns
    ];
    let _axpropertyname_of_yojson: Yojson.Basic.t => _axpropertyname;
    let yojson_of__axpropertyname: _axpropertyname => Yojson.Basic.t;
    /* Values of AXProperty name:
       - from 'busy' to 'roledescription': states which apply to every AX node
       - from 'live' to 'root': attributes which apply to nodes in live regions
       - from 'autocomplete' to 'valuetext': attributes which apply to widgets
       - from 'checked' to 'selected': states which apply to widgets
       - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
    [@deriving yojson]
    type t = _axpropertyname;
  }
  and AXNode: {
    /* A node in the accessibility tree. */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: AXNodeId.t, /* Unique identifier for this node. */
      [@key "ignored"]
      ignored: bool, /* Whether this node is ignored for accessibility */
      [@yojson.option] [@key "ignoredReasons"]
      ignoredReasons: option(list(AXProperty.t)), /* Collection of reasons why this node is hidden. */
      [@yojson.option] [@key "role"]
      role: option(AXValue.t), /* This `Node`'s role, whether explicit or implicit. */
      [@yojson.option] [@key "name"]
      name: option(AXValue.t), /* The accessible name for this `Node`. */
      [@yojson.option] [@key "description"]
      description: option(AXValue.t), /* The accessible description for this `Node`. */
      [@yojson.option] [@key "value"]
      value: option(AXValue.t), /* The value for this `Node`. */
      [@yojson.option] [@key "properties"]
      properties: option(list(AXProperty.t)), /* All other properties */
      [@yojson.option] [@key "parentId"]
      parentId: option(AXNodeId.t), /* ID for this node's parent. */
      [@yojson.option] [@key "childIds"]
      childIds: option(list(AXNodeId.t)), /* IDs for each of this node's child nodes. */
      [@yojson.option] [@key "backendDOMNodeId"]
      backendDOMNodeId: option(DOM.BackendNodeId.t), /* The backend ID for the associated DOM node, if any. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t) /* The frame ID for the frame associated with this nodes document. */,
    };
  };
} = {
  module rec AXNodeId: {
    /* Unique accessibility node identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique accessibility node identifier. */
    [@deriving yojson]
    type t = string;
  }
  and AXValueType: {
    type _axvaluetype = [
      | `boolean
      | `tristate
      | `booleanOrUndefined
      | `idref
      | `idrefList
      | `integer
      | `node
      | `nodeList
      | `number
      | `string
      | `computedString
      | `token
      | `tokenList
      | `domRelation
      | `role
      | `internalRole
      | `valueUndefined
    ];
    let _axvaluetype_of_yojson: Yojson.Basic.t => _axvaluetype;
    let yojson_of__axvaluetype: _axvaluetype => Yojson.Basic.t;
    /* Enum of possible property types. */
    [@deriving yojson]
    type t = _axvaluetype;
  } = {
    type _axvaluetype = [
      | `boolean
      | `tristate
      | `booleanOrUndefined
      | `idref
      | `idrefList
      | `integer
      | `node
      | `nodeList
      | `number
      | `string
      | `computedString
      | `token
      | `tokenList
      | `domRelation
      | `role
      | `internalRole
      | `valueUndefined
    ];
    let _axvaluetype_of_yojson =
      fun
      | `String("boolean") => `boolean
      | `String("tristate") => `tristate
      | `String("booleanOrUndefined") => `booleanOrUndefined
      | `String("idref") => `idref
      | `String("idrefList") => `idrefList
      | `String("integer") => `integer
      | `String("node") => `node
      | `String("nodeList") => `nodeList
      | `String("number") => `number
      | `String("string") => `string
      | `String("computedString") => `computedString
      | `String("token") => `token
      | `String("tokenList") => `tokenList
      | `String("domRelation") => `domRelation
      | `String("role") => `role
      | `String("internalRole") => `internalRole
      | `String("valueUndefined") => `valueUndefined
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__axvaluetype =
      fun
      | `boolean => `String("boolean")
      | `tristate => `String("tristate")
      | `booleanOrUndefined => `String("booleanOrUndefined")
      | `idref => `String("idref")
      | `idrefList => `String("idrefList")
      | `integer => `String("integer")
      | `node => `String("node")
      | `nodeList => `String("nodeList")
      | `number => `String("number")
      | `string => `String("string")
      | `computedString => `String("computedString")
      | `token => `String("token")
      | `tokenList => `String("tokenList")
      | `domRelation => `String("domRelation")
      | `role => `String("role")
      | `internalRole => `String("internalRole")
      | `valueUndefined => `String("valueUndefined");
    /* Enum of possible property types. */
    [@deriving yojson]
    type t = _axvaluetype;
  }
  and AXValueSourceType: {
    type _axvaluesourcetype = [
      | `attribute
      | `implicit
      | `style
      | `contents
      | `placeholder
      | `relatedElement
    ];
    let _axvaluesourcetype_of_yojson: Yojson.Basic.t => _axvaluesourcetype;
    let yojson_of__axvaluesourcetype: _axvaluesourcetype => Yojson.Basic.t;
    /* Enum of possible property sources. */
    [@deriving yojson]
    type t = _axvaluesourcetype;
  } = {
    type _axvaluesourcetype = [
      | `attribute
      | `implicit
      | `style
      | `contents
      | `placeholder
      | `relatedElement
    ];
    let _axvaluesourcetype_of_yojson =
      fun
      | `String("attribute") => `attribute
      | `String("implicit") => `implicit
      | `String("style") => `style
      | `String("contents") => `contents
      | `String("placeholder") => `placeholder
      | `String("relatedElement") => `relatedElement
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__axvaluesourcetype =
      fun
      | `attribute => `String("attribute")
      | `implicit => `String("implicit")
      | `style => `String("style")
      | `contents => `String("contents")
      | `placeholder => `String("placeholder")
      | `relatedElement => `String("relatedElement");
    /* Enum of possible property sources. */
    [@deriving yojson]
    type t = _axvaluesourcetype;
  }
  and AXValueNativeSourceType: {
    type _axvaluenativesourcetype = [
      | `description
      | `figcaption
      | `label
      | `labelfor
      | `labelwrapped
      | `legend
      | `rubyannotation
      | `tablecaption
      | `title
      | `other
    ];
    let _axvaluenativesourcetype_of_yojson:
      Yojson.Basic.t => _axvaluenativesourcetype;
    let yojson_of__axvaluenativesourcetype:
      _axvaluenativesourcetype => Yojson.Basic.t;
    /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
    [@deriving yojson]
    type t = _axvaluenativesourcetype;
  } = {
    type _axvaluenativesourcetype = [
      | `description
      | `figcaption
      | `label
      | `labelfor
      | `labelwrapped
      | `legend
      | `rubyannotation
      | `tablecaption
      | `title
      | `other
    ];
    let _axvaluenativesourcetype_of_yojson =
      fun
      | `String("description") => `description
      | `String("figcaption") => `figcaption
      | `String("label") => `label
      | `String("labelfor") => `labelfor
      | `String("labelwrapped") => `labelwrapped
      | `String("legend") => `legend
      | `String("rubyannotation") => `rubyannotation
      | `String("tablecaption") => `tablecaption
      | `String("title") => `title
      | `String("other") => `other
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__axvaluenativesourcetype =
      fun
      | `description => `String("description")
      | `figcaption => `String("figcaption")
      | `label => `String("label")
      | `labelfor => `String("labelfor")
      | `labelwrapped => `String("labelwrapped")
      | `legend => `String("legend")
      | `rubyannotation => `String("rubyannotation")
      | `tablecaption => `String("tablecaption")
      | `title => `String("title")
      | `other => `String("other");
    /* Enum of possible native property sources (as a subtype of a particular AXValueSourceType). */
    [@deriving yojson]
    type t = _axvaluenativesourcetype;
  }
  and AXValueSource: {
    /* A single source for a computed AX property. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: AXValueSourceType.t, /* What type of source this is. */
      [@yojson.option] [@key "value"]
      value: option(AXValue.t), /* The value of this property source. */
      [@yojson.option] [@key "attribute"]
      attribute: option(string), /* The name of the relevant attribute, if any. */
      [@yojson.option] [@key "attributeValue"]
      attributeValue: option(AXValue.t), /* The value of the relevant attribute, if any. */
      [@yojson.option] [@key "superseded"]
      superseded: option(bool), /* Whether this source is superseded by a higher priority source. */
      [@yojson.option] [@key "nativeSource"]
      nativeSource: option(AXValueNativeSourceType.t), /* The native markup source for this value, e.g. a <label> element. */
      [@yojson.option] [@key "nativeSourceValue"]
      nativeSourceValue: option(AXValue.t), /* The value, such as a node or node list, of the native source. */
      [@yojson.option] [@key "invalid"]
      invalid: option(bool), /* Whether the value for this property is invalid. */
      [@yojson.option] [@key "invalidReason"]
      invalidReason: option(string) /* Reason for the value being invalid, if it is. */,
    };
  } = {
    /* A single source for a computed AX property. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: AXValueSourceType.t, /* What type of source this is. */
      [@yojson.option] [@key "value"]
      value: option(AXValue.t), /* The value of this property source. */
      [@yojson.option] [@key "attribute"]
      attribute: option(string), /* The name of the relevant attribute, if any. */
      [@yojson.option] [@key "attributeValue"]
      attributeValue: option(AXValue.t), /* The value of the relevant attribute, if any. */
      [@yojson.option] [@key "superseded"]
      superseded: option(bool), /* Whether this source is superseded by a higher priority source. */
      [@yojson.option] [@key "nativeSource"]
      nativeSource: option(AXValueNativeSourceType.t), /* The native markup source for this value, e.g. a <label> element. */
      [@yojson.option] [@key "nativeSourceValue"]
      nativeSourceValue: option(AXValue.t), /* The value, such as a node or node list, of the native source. */
      [@yojson.option] [@key "invalid"]
      invalid: option(bool), /* Whether the value for this property is invalid. */
      [@yojson.option] [@key "invalidReason"]
      invalidReason: option(string) /* Reason for the value being invalid, if it is. */,
    };
  }
  and AXRelatedNode: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "backendDOMNodeId"]
      backendDOMNodeId: DOM.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
      [@yojson.option] [@key "idref"]
      idref: option(string), /* The IDRef value provided, if any. */
      [@yojson.option] [@key "text"]
      text: option(string) /* The text alternative of this node in the current context. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "backendDOMNodeId"]
      backendDOMNodeId: DOM.BackendNodeId.t, /* The BackendNodeId of the related DOM node. */
      [@yojson.option] [@key "idref"]
      idref: option(string), /* The IDRef value provided, if any. */
      [@yojson.option] [@key "text"]
      text: option(string) /* The text alternative of this node in the current context. */,
    };
  }
  and AXProperty: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: AXPropertyName.t, /* The name of this property. */
      [@key "value"]
      value: AXValue.t /* The value of this property. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: AXPropertyName.t, /* The name of this property. */
      [@key "value"]
      value: AXValue.t /* The value of this property. */,
    };
  }
  and AXValue: {
    /* A single computed AX property. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: AXValueType.t, /* The type of this value. */
      [@yojson.option] [@key "value"]
      value: option(string), /* The computed value of this property. */
      [@yojson.option] [@key "relatedNodes"]
      relatedNodes: option(list(AXRelatedNode.t)), /* One or more related nodes, if applicable. */
      [@yojson.option] [@key "sources"]
      sources: option(list(AXValueSource.t)) /* The sources which contributed to the computation of this property. */,
    };
  } = {
    /* A single computed AX property. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: AXValueType.t, /* The type of this value. */
      [@yojson.option] [@key "value"]
      value: option(string), /* The computed value of this property. */
      [@yojson.option] [@key "relatedNodes"]
      relatedNodes: option(list(AXRelatedNode.t)), /* One or more related nodes, if applicable. */
      [@yojson.option] [@key "sources"]
      sources: option(list(AXValueSource.t)) /* The sources which contributed to the computation of this property. */,
    };
  }
  and AXPropertyName: {
    type _axpropertyname = [
      | `busy
      | `disabled
      | `editable
      | `focusable
      | `focused
      | `hidden
      | `hiddenRoot
      | `invalid
      | `keyshortcuts
      | `settable
      | `roledescription
      | `live
      | `atomic
      | `relevant
      | `root
      | `autocomplete
      | `hasPopup
      | `level
      | `multiselectable
      | `orientation
      | `multiline
      | `readonly
      | `required
      | `valuemin
      | `valuemax
      | `valuetext
      | `checked
      | `expanded
      | `modal
      | `pressed
      | `selected
      | `activedescendant
      | `controls
      | `describedby
      | `details
      | `errormessage
      | `flowto
      | `labelledby
      | `owns
    ];
    let _axpropertyname_of_yojson: Yojson.Basic.t => _axpropertyname;
    let yojson_of__axpropertyname: _axpropertyname => Yojson.Basic.t;
    /* Values of AXProperty name:
       - from 'busy' to 'roledescription': states which apply to every AX node
       - from 'live' to 'root': attributes which apply to nodes in live regions
       - from 'autocomplete' to 'valuetext': attributes which apply to widgets
       - from 'checked' to 'selected': states which apply to widgets
       - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
    [@deriving yojson]
    type t = _axpropertyname;
  } = {
    type _axpropertyname = [
      | `busy
      | `disabled
      | `editable
      | `focusable
      | `focused
      | `hidden
      | `hiddenRoot
      | `invalid
      | `keyshortcuts
      | `settable
      | `roledescription
      | `live
      | `atomic
      | `relevant
      | `root
      | `autocomplete
      | `hasPopup
      | `level
      | `multiselectable
      | `orientation
      | `multiline
      | `readonly
      | `required
      | `valuemin
      | `valuemax
      | `valuetext
      | `checked
      | `expanded
      | `modal
      | `pressed
      | `selected
      | `activedescendant
      | `controls
      | `describedby
      | `details
      | `errormessage
      | `flowto
      | `labelledby
      | `owns
    ];
    let _axpropertyname_of_yojson =
      fun
      | `String("busy") => `busy
      | `String("disabled") => `disabled
      | `String("editable") => `editable
      | `String("focusable") => `focusable
      | `String("focused") => `focused
      | `String("hidden") => `hidden
      | `String("hiddenRoot") => `hiddenRoot
      | `String("invalid") => `invalid
      | `String("keyshortcuts") => `keyshortcuts
      | `String("settable") => `settable
      | `String("roledescription") => `roledescription
      | `String("live") => `live
      | `String("atomic") => `atomic
      | `String("relevant") => `relevant
      | `String("root") => `root
      | `String("autocomplete") => `autocomplete
      | `String("hasPopup") => `hasPopup
      | `String("level") => `level
      | `String("multiselectable") => `multiselectable
      | `String("orientation") => `orientation
      | `String("multiline") => `multiline
      | `String("readonly") => `readonly
      | `String("required") => `required
      | `String("valuemin") => `valuemin
      | `String("valuemax") => `valuemax
      | `String("valuetext") => `valuetext
      | `String("checked") => `checked
      | `String("expanded") => `expanded
      | `String("modal") => `modal
      | `String("pressed") => `pressed
      | `String("selected") => `selected
      | `String("activedescendant") => `activedescendant
      | `String("controls") => `controls
      | `String("describedby") => `describedby
      | `String("details") => `details
      | `String("errormessage") => `errormessage
      | `String("flowto") => `flowto
      | `String("labelledby") => `labelledby
      | `String("owns") => `owns
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__axpropertyname =
      fun
      | `busy => `String("busy")
      | `disabled => `String("disabled")
      | `editable => `String("editable")
      | `focusable => `String("focusable")
      | `focused => `String("focused")
      | `hidden => `String("hidden")
      | `hiddenRoot => `String("hiddenRoot")
      | `invalid => `String("invalid")
      | `keyshortcuts => `String("keyshortcuts")
      | `settable => `String("settable")
      | `roledescription => `String("roledescription")
      | `live => `String("live")
      | `atomic => `String("atomic")
      | `relevant => `String("relevant")
      | `root => `String("root")
      | `autocomplete => `String("autocomplete")
      | `hasPopup => `String("hasPopup")
      | `level => `String("level")
      | `multiselectable => `String("multiselectable")
      | `orientation => `String("orientation")
      | `multiline => `String("multiline")
      | `readonly => `String("readonly")
      | `required => `String("required")
      | `valuemin => `String("valuemin")
      | `valuemax => `String("valuemax")
      | `valuetext => `String("valuetext")
      | `checked => `String("checked")
      | `expanded => `String("expanded")
      | `modal => `String("modal")
      | `pressed => `String("pressed")
      | `selected => `String("selected")
      | `activedescendant => `String("activedescendant")
      | `controls => `String("controls")
      | `describedby => `String("describedby")
      | `details => `String("details")
      | `errormessage => `String("errormessage")
      | `flowto => `String("flowto")
      | `labelledby => `String("labelledby")
      | `owns => `String("owns");
    /* Values of AXProperty name:
       - from 'busy' to 'roledescription': states which apply to every AX node
       - from 'live' to 'root': attributes which apply to nodes in live regions
       - from 'autocomplete' to 'valuetext': attributes which apply to widgets
       - from 'checked' to 'selected': states which apply to widgets
       - from 'activedescendant' to 'owns' - relationships between elements other than parent/child/sibling. */
    [@deriving yojson]
    type t = _axpropertyname;
  }
  and AXNode: {
    /* A node in the accessibility tree. */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: AXNodeId.t, /* Unique identifier for this node. */
      [@key "ignored"]
      ignored: bool, /* Whether this node is ignored for accessibility */
      [@yojson.option] [@key "ignoredReasons"]
      ignoredReasons: option(list(AXProperty.t)), /* Collection of reasons why this node is hidden. */
      [@yojson.option] [@key "role"]
      role: option(AXValue.t), /* This `Node`'s role, whether explicit or implicit. */
      [@yojson.option] [@key "name"]
      name: option(AXValue.t), /* The accessible name for this `Node`. */
      [@yojson.option] [@key "description"]
      description: option(AXValue.t), /* The accessible description for this `Node`. */
      [@yojson.option] [@key "value"]
      value: option(AXValue.t), /* The value for this `Node`. */
      [@yojson.option] [@key "properties"]
      properties: option(list(AXProperty.t)), /* All other properties */
      [@yojson.option] [@key "parentId"]
      parentId: option(AXNodeId.t), /* ID for this node's parent. */
      [@yojson.option] [@key "childIds"]
      childIds: option(list(AXNodeId.t)), /* IDs for each of this node's child nodes. */
      [@yojson.option] [@key "backendDOMNodeId"]
      backendDOMNodeId: option(DOM.BackendNodeId.t), /* The backend ID for the associated DOM node, if any. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t) /* The frame ID for the frame associated with this nodes document. */,
    };
  } = {
    /* A node in the accessibility tree. */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: AXNodeId.t, /* Unique identifier for this node. */
      [@key "ignored"]
      ignored: bool, /* Whether this node is ignored for accessibility */
      [@yojson.option] [@key "ignoredReasons"]
      ignoredReasons: option(list(AXProperty.t)), /* Collection of reasons why this node is hidden. */
      [@yojson.option] [@key "role"]
      role: option(AXValue.t), /* This `Node`'s role, whether explicit or implicit. */
      [@yojson.option] [@key "name"]
      name: option(AXValue.t), /* The accessible name for this `Node`. */
      [@yojson.option] [@key "description"]
      description: option(AXValue.t), /* The accessible description for this `Node`. */
      [@yojson.option] [@key "value"]
      value: option(AXValue.t), /* The value for this `Node`. */
      [@yojson.option] [@key "properties"]
      properties: option(list(AXProperty.t)), /* All other properties */
      [@yojson.option] [@key "parentId"]
      parentId: option(AXNodeId.t), /* ID for this node's parent. */
      [@yojson.option] [@key "childIds"]
      childIds: option(list(AXNodeId.t)), /* IDs for each of this node's child nodes. */
      [@yojson.option] [@key "backendDOMNodeId"]
      backendDOMNodeId: option(DOM.BackendNodeId.t), /* The backend ID for the associated DOM node, if any. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t) /* The frame ID for the frame associated with this nodes document. */,
    };
  };
}
and Animation: {
  module rec Animation: {
    type _animation_type = [ | `CSSTransition | `CSSAnimation | `WebAnimation];
    let _animation_type_of_yojson: Yojson.Basic.t => _animation_type;
    let yojson_of__animation_type: _animation_type => Yojson.Basic.t;
    /* Animation instance. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: string, /* `Animation`'s id. */
      [@key "name"]
      name: string, /* `Animation`'s name. */
      [@key "pausedState"]
      pausedState: bool, /* `Animation`'s internal paused state. */
      [@key "playState"]
      playState: string, /* `Animation`'s play state. */
      [@key "playbackRate"]
      playbackRate: float, /* `Animation`'s playback rate. */
      [@key "startTime"]
      startTime: float, /* `Animation`'s start time. */
      [@key "currentTime"]
      currentTime: float, /* `Animation`'s current time. */
      [@key "type"]
      type_: _animation_type, /* Animation type of `Animation`. */
      [@yojson.option] [@key "source"]
      source: option(AnimationEffect.t), /* `Animation`'s source animation node. */
      [@yojson.option] [@key "cssId"]
      cssId: option(string) /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
    };
  }
  and AnimationEffect: {
    /* AnimationEffect instance */
    [@deriving yojson]
    type t = {
      [@key "delay"]
      delay: float, /* `AnimationEffect`'s delay. */
      [@key "endDelay"]
      endDelay: float, /* `AnimationEffect`'s end delay. */
      [@key "iterationStart"]
      iterationStart: float, /* `AnimationEffect`'s iteration start. */
      [@key "iterations"]
      iterations: float, /* `AnimationEffect`'s iterations. */
      [@key "duration"]
      duration: float, /* `AnimationEffect`'s iteration duration. */
      [@key "direction"]
      direction: string, /* `AnimationEffect`'s playback direction. */
      [@key "fill"]
      fill: string, /* `AnimationEffect`'s fill mode. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t), /* `AnimationEffect`'s target node. */
      [@yojson.option] [@key "keyframesRule"]
      keyframesRule: option(KeyframesRule.t), /* `AnimationEffect`'s keyframes. */
      [@key "easing"]
      easing: string /* `AnimationEffect`'s timing function. */,
    };
  }
  and KeyframesRule: {
    /* Keyframes Rule */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "name"]
      name: option(string), /* CSS keyframed animation's name. */
      [@key "keyframes"]
      keyframes: list(KeyframeStyle.t) /* List of animation keyframes. */,
    };
  }
  and KeyframeStyle: {
    /* Keyframe Style */
    [@deriving yojson]
    type t = {
      [@key "offset"]
      offset: string, /* Keyframe's time offset. */
      [@key "easing"]
      easing: string /* `AnimationEffect`'s timing function. */,
    };
  };
} = {
  module rec Animation: {
    type _animation_type = [ | `CSSTransition | `CSSAnimation | `WebAnimation];
    let _animation_type_of_yojson: Yojson.Basic.t => _animation_type;
    let yojson_of__animation_type: _animation_type => Yojson.Basic.t;
    /* Animation instance. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: string, /* `Animation`'s id. */
      [@key "name"]
      name: string, /* `Animation`'s name. */
      [@key "pausedState"]
      pausedState: bool, /* `Animation`'s internal paused state. */
      [@key "playState"]
      playState: string, /* `Animation`'s play state. */
      [@key "playbackRate"]
      playbackRate: float, /* `Animation`'s playback rate. */
      [@key "startTime"]
      startTime: float, /* `Animation`'s start time. */
      [@key "currentTime"]
      currentTime: float, /* `Animation`'s current time. */
      [@key "type"]
      type_: _animation_type, /* Animation type of `Animation`. */
      [@yojson.option] [@key "source"]
      source: option(AnimationEffect.t), /* `Animation`'s source animation node. */
      [@yojson.option] [@key "cssId"]
      cssId: option(string) /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
    };
  } = {
    type _animation_type = [ | `CSSTransition | `CSSAnimation | `WebAnimation];
    let _animation_type_of_yojson =
      fun
      | `String("CSSTransition") => `CSSTransition
      | `String("CSSAnimation") => `CSSAnimation
      | `String("WebAnimation") => `WebAnimation
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__animation_type =
      fun
      | `CSSTransition => `String("CSSTransition")
      | `CSSAnimation => `String("CSSAnimation")
      | `WebAnimation => `String("WebAnimation");
    /* Animation instance. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: string, /* `Animation`'s id. */
      [@key "name"]
      name: string, /* `Animation`'s name. */
      [@key "pausedState"]
      pausedState: bool, /* `Animation`'s internal paused state. */
      [@key "playState"]
      playState: string, /* `Animation`'s play state. */
      [@key "playbackRate"]
      playbackRate: float, /* `Animation`'s playback rate. */
      [@key "startTime"]
      startTime: float, /* `Animation`'s start time. */
      [@key "currentTime"]
      currentTime: float, /* `Animation`'s current time. */
      [@key "type"]
      type_: _animation_type, /* Animation type of `Animation`. */
      [@yojson.option] [@key "source"]
      source: option(AnimationEffect.t), /* `Animation`'s source animation node. */
      [@yojson.option] [@key "cssId"]
      cssId: option(string) /* A unique ID for `Animation` representing the sources that triggered this CSS
animation/transition. */,
    };
  }
  and AnimationEffect: {
    /* AnimationEffect instance */
    [@deriving yojson]
    type t = {
      [@key "delay"]
      delay: float, /* `AnimationEffect`'s delay. */
      [@key "endDelay"]
      endDelay: float, /* `AnimationEffect`'s end delay. */
      [@key "iterationStart"]
      iterationStart: float, /* `AnimationEffect`'s iteration start. */
      [@key "iterations"]
      iterations: float, /* `AnimationEffect`'s iterations. */
      [@key "duration"]
      duration: float, /* `AnimationEffect`'s iteration duration. */
      [@key "direction"]
      direction: string, /* `AnimationEffect`'s playback direction. */
      [@key "fill"]
      fill: string, /* `AnimationEffect`'s fill mode. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t), /* `AnimationEffect`'s target node. */
      [@yojson.option] [@key "keyframesRule"]
      keyframesRule: option(KeyframesRule.t), /* `AnimationEffect`'s keyframes. */
      [@key "easing"]
      easing: string /* `AnimationEffect`'s timing function. */,
    };
  } = {
    /* AnimationEffect instance */
    [@deriving yojson]
    type t = {
      [@key "delay"]
      delay: float, /* `AnimationEffect`'s delay. */
      [@key "endDelay"]
      endDelay: float, /* `AnimationEffect`'s end delay. */
      [@key "iterationStart"]
      iterationStart: float, /* `AnimationEffect`'s iteration start. */
      [@key "iterations"]
      iterations: float, /* `AnimationEffect`'s iterations. */
      [@key "duration"]
      duration: float, /* `AnimationEffect`'s iteration duration. */
      [@key "direction"]
      direction: string, /* `AnimationEffect`'s playback direction. */
      [@key "fill"]
      fill: string, /* `AnimationEffect`'s fill mode. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t), /* `AnimationEffect`'s target node. */
      [@yojson.option] [@key "keyframesRule"]
      keyframesRule: option(KeyframesRule.t), /* `AnimationEffect`'s keyframes. */
      [@key "easing"]
      easing: string /* `AnimationEffect`'s timing function. */,
    };
  }
  and KeyframesRule: {
    /* Keyframes Rule */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "name"]
      name: option(string), /* CSS keyframed animation's name. */
      [@key "keyframes"]
      keyframes: list(KeyframeStyle.t) /* List of animation keyframes. */,
    };
  } = {
    /* Keyframes Rule */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "name"]
      name: option(string), /* CSS keyframed animation's name. */
      [@key "keyframes"]
      keyframes: list(KeyframeStyle.t) /* List of animation keyframes. */,
    };
  }
  and KeyframeStyle: {
    /* Keyframe Style */
    [@deriving yojson]
    type t = {
      [@key "offset"]
      offset: string, /* Keyframe's time offset. */
      [@key "easing"]
      easing: string /* `AnimationEffect`'s timing function. */,
    };
  } = {
    /* Keyframe Style */
    [@deriving yojson]
    type t = {
      [@key "offset"]
      offset: string, /* Keyframe's time offset. */
      [@key "easing"]
      easing: string /* `AnimationEffect`'s timing function. */,
    };
  };
}
and Audits: {
  module rec AffectedCookie: {
    /* Information about a cookie that is affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* The following three properties uniquely identify a cookie */
      [@key "path"]
      path: string, /* No description provided */
      [@key "domain"]
      domain: string /* No description provided */,
    };
  }
  and AffectedRequest: {
    /* Information about a request that is affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "requestId"]
      requestId: Network.RequestId.t, /* The unique request id. */
      [@yojson.option] [@key "url"]
      url: option(string) /* No description provided */,
    };
  }
  and AffectedFrame: {
    /* Information about the frame affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: Page.FrameId.t /* No description provided */,
    };
  }
  and SameSiteCookieExclusionReason: {
    type _samesitecookieexclusionreason = [
      | `ExcludeSameSiteUnspecifiedTreatedAsLax
      | `ExcludeSameSiteNoneInsecure
      | `ExcludeSameSiteLax
      | `ExcludeSameSiteStrict
      | `ExcludeInvalidSameParty
      | `ExcludeSamePartyCrossPartyContext
    ];
    let _samesitecookieexclusionreason_of_yojson:
      Yojson.Basic.t => _samesitecookieexclusionreason;
    let yojson_of__samesitecookieexclusionreason:
      _samesitecookieexclusionreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookieexclusionreason;
  }
  and SameSiteCookieWarningReason: {
    type _samesitecookiewarningreason = [
      | `WarnSameSiteUnspecifiedCrossSiteContext
      | `WarnSameSiteNoneInsecure
      | `WarnSameSiteUnspecifiedLaxAllowUnsafe
      | `WarnSameSiteStrictLaxDowngradeStrict
      | `WarnSameSiteStrictCrossDowngradeStrict
      | `WarnSameSiteStrictCrossDowngradeLax
      | `WarnSameSiteLaxCrossDowngradeStrict
      | `WarnSameSiteLaxCrossDowngradeLax
    ];
    let _samesitecookiewarningreason_of_yojson:
      Yojson.Basic.t => _samesitecookiewarningreason;
    let yojson_of__samesitecookiewarningreason:
      _samesitecookiewarningreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookiewarningreason;
  }
  and SameSiteCookieOperation: {
    type _samesitecookieoperation = [ | `SetCookie | `ReadCookie];
    let _samesitecookieoperation_of_yojson:
      Yojson.Basic.t => _samesitecookieoperation;
    let yojson_of__samesitecookieoperation:
      _samesitecookieoperation => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookieoperation;
  }
  and SameSiteCookieIssueDetails: {
    /* This information is currently necessary, as the front-end has a difficult
       time finding a specific cookie. With this, we can convey specific error
       information without the cookie. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "cookie"]
      cookie: option(AffectedCookie.t), /* If AffectedCookie is not set then rawCookieLine contains the raw
Set-Cookie header string. This hints at a problem where the
cookie line is syntactically or semantically malformed in a way
that no valid cookie could be created. */
      [@yojson.option] [@key "rawCookieLine"]
      rawCookieLine: option(string), /* No description provided */
      [@key "cookieWarningReasons"]
      cookieWarningReasons: list(SameSiteCookieWarningReason.t), /* No description provided */
      [@key "cookieExclusionReasons"]
      cookieExclusionReasons: list(SameSiteCookieExclusionReason.t), /* No description provided */
      [@key "operation"]
      operation: SameSiteCookieOperation.t, /* Optionally identifies the site-for-cookies and the cookie url, which
may be used by the front-end as additional context. */
      [@yojson.option] [@key "siteForCookies"]
      siteForCookies: option(string), /* No description provided */
      [@yojson.option] [@key "cookieUrl"]
      cookieUrl: option(string), /* No description provided */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t) /* No description provided */,
    };
  }
  and MixedContentResolutionStatus: {
    type _mixedcontentresolutionstatus = [
      | `MixedContentBlocked
      | `MixedContentAutomaticallyUpgraded
      | `MixedContentWarning
    ];
    let _mixedcontentresolutionstatus_of_yojson:
      Yojson.Basic.t => _mixedcontentresolutionstatus;
    let yojson_of__mixedcontentresolutionstatus:
      _mixedcontentresolutionstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _mixedcontentresolutionstatus;
  }
  and MixedContentResourceType: {
    type _mixedcontentresourcetype = [
      | `Audio
      | `Beacon
      | `CSPReport
      | `Download
      | `EventSource
      | `Favicon
      | `Font
      | `Form
      | `Frame
      | `Image
      | `Import
      | `Manifest
      | `Ping
      | `PluginData
      | `PluginResource
      | `Prefetch
      | `Resource
      | `Script
      | `ServiceWorker
      | `SharedWorker
      | `Stylesheet
      | `Track
      | `Video
      | `Worker
      | `XMLHttpRequest
      | `XSLT
    ];
    let _mixedcontentresourcetype_of_yojson:
      Yojson.Basic.t => _mixedcontentresourcetype;
    let yojson_of__mixedcontentresourcetype:
      _mixedcontentresourcetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _mixedcontentresourcetype;
  }
  and MixedContentIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "resourceType"]
      resourceType: option(MixedContentResourceType.t), /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
      [@key "resolutionStatus"]
      resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
      [@key "insecureURL"]
      insecureURL: string, /* The unsafe http url causing the mixed content issue. */
      [@key "mainResourceURL"]
      mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t), /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
      [@yojson.option] [@key "frame"]
      frame: option(AffectedFrame.t) /* Optional because not every mixed content issue is necessarily linked to a frame. */,
    };
  }
  and BlockedByResponseReason: {
    type _blockedbyresponsereason = [
      | `CoepFrameResourceNeedsCoepHeader
      | `CoopSandboxedIFrameCannotNavigateToCoopPage
      | `CorpNotSameOrigin
      | `CorpNotSameOriginAfterDefaultedToSameOriginByCoep
      | `CorpNotSameSite
    ];
    let _blockedbyresponsereason_of_yojson:
      Yojson.Basic.t => _blockedbyresponsereason;
    let yojson_of__blockedbyresponsereason:
      _blockedbyresponsereason => Yojson.Basic.t;
    /* Enum indicating the reason a response has been blocked. These reasons are
       refinements of the net error BLOCKED_BY_RESPONSE. */
    [@deriving yojson]
    type t = _blockedbyresponsereason;
  }
  and BlockedByResponseIssueDetails: {
    /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
       code. Currently only used for COEP/COOP, but may be extended to include
       some CSP errors in the future. */
    [@deriving yojson]
    type t = {
      [@key "request"]
      request: AffectedRequest.t, /* No description provided */
      [@yojson.option] [@key "parentFrame"]
      parentFrame: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "blockedFrame"]
      blockedFrame: option(AffectedFrame.t), /* No description provided */
      [@key "reason"]
      reason: BlockedByResponseReason.t /* No description provided */,
    };
  }
  and HeavyAdResolutionStatus: {
    type _heavyadresolutionstatus = [ | `HeavyAdBlocked | `HeavyAdWarning];
    let _heavyadresolutionstatus_of_yojson:
      Yojson.Basic.t => _heavyadresolutionstatus;
    let yojson_of__heavyadresolutionstatus:
      _heavyadresolutionstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _heavyadresolutionstatus;
  }
  and HeavyAdReason: {
    type _heavyadreason = [
      | `NetworkTotalLimit
      | `CpuTotalLimit
      | `CpuPeakLimit
    ];
    let _heavyadreason_of_yojson: Yojson.Basic.t => _heavyadreason;
    let yojson_of__heavyadreason: _heavyadreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _heavyadreason;
  }
  and HeavyAdIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "resolution"]
      resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
      [@key "reason"]
      reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
      [@key "frame"]
      frame: AffectedFrame.t /* The frame that was blocked. */,
    };
  }
  and ContentSecurityPolicyViolationType: {
    type _contentsecuritypolicyviolationtype = [
      | `kInlineViolation
      | `kEvalViolation
      | `kURLViolation
      | `kTrustedTypesSinkViolation
      | `kTrustedTypesPolicyViolation
      | `kWasmEvalViolation
    ];
    let _contentsecuritypolicyviolationtype_of_yojson:
      Yojson.Basic.t => _contentsecuritypolicyviolationtype;
    let yojson_of__contentsecuritypolicyviolationtype:
      _contentsecuritypolicyviolationtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _contentsecuritypolicyviolationtype;
  }
  and SourceCodeLocation: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "scriptId"]
      scriptId: option(Runtime.ScriptId.t), /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  }
  and ContentSecurityPolicyIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "blockedURL"]
      blockedURL: option(string), /* The url not included in allowed sources. */
      [@key "violatedDirective"]
      violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
      [@key "isReportOnly"]
      isReportOnly: bool, /* No description provided */
      [@key "contentSecurityPolicyViolationType"]
      contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
      [@yojson.option] [@key "frameAncestor"]
      frameAncestor: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "sourceCodeLocation"]
      sourceCodeLocation: option(SourceCodeLocation.t), /* No description provided */
      [@yojson.option] [@key "violatingNodeId"]
      violatingNodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  }
  and SharedArrayBufferIssueType: {
    type _sharedarraybufferissuetype = [ | `TransferIssue | `CreationIssue];
    let _sharedarraybufferissuetype_of_yojson:
      Yojson.Basic.t => _sharedarraybufferissuetype;
    let yojson_of__sharedarraybufferissuetype:
      _sharedarraybufferissuetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _sharedarraybufferissuetype;
  }
  and SharedArrayBufferIssueDetails: {
    /* Details for a issue arising from an SAB being instantiated in, or
       transferred to a context that is not cross-origin isolated. */
    [@deriving yojson]
    type t = {
      [@key "sourceCodeLocation"]
      sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
      [@key "isWarning"]
      isWarning: bool, /* No description provided */
      [@key "type"]
      type_: SharedArrayBufferIssueType.t /* No description provided */,
    };
  }
  and TwaQualityEnforcementViolationType: {
    type _twaqualityenforcementviolationtype = [
      | `kHttpError
      | `kUnavailableOffline
      | `kDigitalAssetLinks
    ];
    let _twaqualityenforcementviolationtype_of_yojson:
      Yojson.Basic.t => _twaqualityenforcementviolationtype;
    let yojson_of__twaqualityenforcementviolationtype:
      _twaqualityenforcementviolationtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _twaqualityenforcementviolationtype;
  }
  and TrustedWebActivityIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The url that triggers the violation. */
      [@key "violationType"]
      violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
      [@yojson.option] [@key "httpStatusCode"]
      httpStatusCode: option(float), /* No description provided */
      [@yojson.option] [@key "packageName"]
      packageName: option(string), /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
      [@yojson.option] [@key "signature"]
      signature: option(string) /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
    };
  }
  and LowTextContrastIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "violatingNodeId"]
      violatingNodeId: DOM.BackendNodeId.t, /* No description provided */
      [@key "violatingNodeSelector"]
      violatingNodeSelector: string, /* No description provided */
      [@key "contrastRatio"]
      contrastRatio: float, /* No description provided */
      [@key "thresholdAA"]
      thresholdAA: float, /* No description provided */
      [@key "thresholdAAA"]
      thresholdAAA: float, /* No description provided */
      [@key "fontSize"]
      fontSize: string, /* No description provided */
      [@key "fontWeight"]
      fontWeight: string /* No description provided */,
    };
  }
  and CorsIssueDetails: {
    /* Details for a CORS related issue, e.g. a warning or error related to
       CORS RFC1918 enforcement. */
    [@deriving yojson]
    type t = {
      [@key "corsErrorStatus"]
      corsErrorStatus: Network.CorsErrorStatus.t, /* No description provided */
      [@key "isWarning"]
      isWarning: bool, /* No description provided */
      [@key "request"]
      request: AffectedRequest.t, /* No description provided */
      [@yojson.option] [@key "location"]
      location: option(SourceCodeLocation.t), /* No description provided */
      [@yojson.option] [@key "initiatorOrigin"]
      initiatorOrigin: option(string), /* No description provided */
      [@yojson.option] [@key "resourceIPAddressSpace"]
      resourceIPAddressSpace: option(Network.IPAddressSpace.t), /* No description provided */
      [@yojson.option] [@key "clientSecurityState"]
      clientSecurityState: option(Network.ClientSecurityState.t) /* No description provided */,
    };
  }
  and AttributionReportingIssueType: {
    type _attributionreportingissuetype = [
      | `PermissionPolicyDisabled
      | `InvalidAttributionSourceEventId
      | `InvalidAttributionData
      | `AttributionSourceUntrustworthyOrigin
      | `AttributionUntrustworthyOrigin
      | `AttributionTriggerDataTooLarge
      | `AttributionEventSourceTriggerDataTooLarge
    ];
    let _attributionreportingissuetype_of_yojson:
      Yojson.Basic.t => _attributionreportingissuetype;
    let yojson_of__attributionreportingissuetype:
      _attributionreportingissuetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _attributionreportingissuetype;
  }
  and AttributionReportingIssueDetails: {
    /* Details for issues around "Attribution Reporting API" usage.
       Explainer: https://github.com/WICG/conversion-measurement-api */
    [@deriving yojson]
    type t = {
      [@key "violationType"]
      violationType: AttributionReportingIssueType.t, /* No description provided */
      [@yojson.option] [@key "frame"]
      frame: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t), /* No description provided */
      [@yojson.option] [@key "violatingNodeId"]
      violatingNodeId: option(DOM.BackendNodeId.t), /* No description provided */
      [@yojson.option] [@key "invalidParameter"]
      invalidParameter: option(string) /* No description provided */,
    };
  }
  and QuirksModeIssueDetails: {
    /* Details for issues about documents in Quirks Mode
       or Limited Quirks Mode that affects page layouting. */
    [@deriving yojson]
    type t = {
      [@key "isLimitedQuirksMode"]
      isLimitedQuirksMode: bool, /* If false, it means the document's mode is "quirks"
instead of "limited-quirks". */
      [@key "documentNodeId"]
      documentNodeId: DOM.BackendNodeId.t, /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "frameId"]
      frameId: Page.FrameId.t, /* No description provided */
      [@key "loaderId"]
      loaderId: Network.LoaderId.t /* No description provided */,
    };
  }
  and NavigatorUserAgentIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* No description provided */
      [@yojson.option] [@key "location"]
      location: option(SourceCodeLocation.t) /* No description provided */,
    };
  }
  and WasmCrossOriginModuleSharingIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "wasmModuleUrl"]
      wasmModuleUrl: string, /* No description provided */
      [@key "sourceOrigin"]
      sourceOrigin: string, /* No description provided */
      [@key "targetOrigin"]
      targetOrigin: string, /* No description provided */
      [@key "isWarning"]
      isWarning: bool /* No description provided */,
    };
  }
  and GenericIssueErrorType: {
    type _genericissueerrortype = [ | `CrossOriginPortalPostMessageError];
    let _genericissueerrortype_of_yojson:
      Yojson.Basic.t => _genericissueerrortype;
    let yojson_of__genericissueerrortype:
      _genericissueerrortype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _genericissueerrortype;
  }
  and GenericIssueDetails: {
    /* Depending on the concrete errorType, different properties are set. */
    [@deriving yojson]
    type t = {
      [@key "errorType"]
      errorType: GenericIssueErrorType.t, /* Issues with the same errorType are aggregated in the frontend. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t) /* No description provided */,
    };
  }
  and DeprecationIssueDetails: {
    /* This issue tracks information needed to print a deprecation message.
       The formatting is inherited from the old console.log version, see more at:
       https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/renderer/core/frame/deprecation.cc
       TODO(crbug.com/1264960): Re-work format to add i18n support per:
       https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/public/devtools_protocol/README.md */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "affectedFrame"]
      affectedFrame: option(AffectedFrame.t), /* No description provided */
      [@key "sourceCodeLocation"]
      sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
      [@yojson.option] [@key "message"]
      message: option(string) /* The content of the deprecation issue (this won't be translated),
e.g. "window.inefficientLegacyStorageMethod will be removed in M97,
around January 2022. Please use Web Storage or Indexed Database
instead. This standard was abandoned in January, 1970. See
https://www.chromestatus.com/feature/5684870116278272 for more details." */,
    };
  }
  and InspectorIssueCode: {
    type _inspectorissuecode = [
      | `SameSiteCookieIssue
      | `MixedContentIssue
      | `BlockedByResponseIssue
      | `HeavyAdIssue
      | `ContentSecurityPolicyIssue
      | `SharedArrayBufferIssue
      | `TrustedWebActivityIssue
      | `LowTextContrastIssue
      | `CorsIssue
      | `AttributionReportingIssue
      | `QuirksModeIssue
      | `NavigatorUserAgentIssue
      | `WasmCrossOriginModuleSharingIssue
      | `GenericIssue
      | `DeprecationIssue
    ];
    let _inspectorissuecode_of_yojson: Yojson.Basic.t => _inspectorissuecode;
    let yojson_of__inspectorissuecode: _inspectorissuecode => Yojson.Basic.t;
    /* A unique identifier for the type of issue. Each type may use one of the
       optional fields in InspectorIssueDetails to convey more specific
       information about the kind of issue. */
    [@deriving yojson]
    type t = _inspectorissuecode;
  }
  and InspectorIssueDetails: {
    /* This struct holds a list of optional fields with additional information
       specific to the kind of issue. When adding a new issue code, please also
       add a new optional field to this type. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "sameSiteCookieIssueDetails"]
      sameSiteCookieIssueDetails: option(SameSiteCookieIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "mixedContentIssueDetails"]
      mixedContentIssueDetails: option(MixedContentIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "blockedByResponseIssueDetails"]
      blockedByResponseIssueDetails: option(BlockedByResponseIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "heavyAdIssueDetails"]
      heavyAdIssueDetails: option(HeavyAdIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "contentSecurityPolicyIssueDetails"]
      contentSecurityPolicyIssueDetails:
        option(ContentSecurityPolicyIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "sharedArrayBufferIssueDetails"]
      sharedArrayBufferIssueDetails: option(SharedArrayBufferIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "twaQualityEnforcementDetails"]
      twaQualityEnforcementDetails: option(TrustedWebActivityIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "lowTextContrastIssueDetails"]
      lowTextContrastIssueDetails: option(LowTextContrastIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "corsIssueDetails"]
      corsIssueDetails: option(CorsIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "attributionReportingIssueDetails"]
      attributionReportingIssueDetails:
        option(AttributionReportingIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "quirksModeIssueDetails"]
      quirksModeIssueDetails: option(QuirksModeIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "navigatorUserAgentIssueDetails"]
      navigatorUserAgentIssueDetails:
        option(NavigatorUserAgentIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "wasmCrossOriginModuleSharingIssue"]
      wasmCrossOriginModuleSharingIssue:
        option(WasmCrossOriginModuleSharingIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "genericIssueDetails"]
      genericIssueDetails: option(GenericIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "deprecationIssueDetails"]
      deprecationIssueDetails: option(DeprecationIssueDetails.t) /* No description provided */,
    };
  }
  and IssueId: {
    /* A unique id for a DevTools inspector issue. Allows other entities (e.g.
       exceptions, CDP message, console messages, etc.) to reference an issue. */
    [@deriving yojson]
    type t = string;
  }
  and InspectorIssue: {
    /* An inspector issue reported from the back-end. */
    [@deriving yojson]
    type t = {
      [@key "code"]
      code: InspectorIssueCode.t, /* No description provided */
      [@key "details"]
      details: InspectorIssueDetails.t, /* No description provided */
      [@yojson.option] [@key "issueId"]
      issueId: option(IssueId.t) /* A unique id for this issue. May be omitted if no other entity (e.g.
exception, CDP message, etc.) is referencing this issue. */,
    };
  };
} = {
  module rec AffectedCookie: {
    /* Information about a cookie that is affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* The following three properties uniquely identify a cookie */
      [@key "path"]
      path: string, /* No description provided */
      [@key "domain"]
      domain: string /* No description provided */,
    };
  } = {
    /* Information about a cookie that is affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* The following three properties uniquely identify a cookie */
      [@key "path"]
      path: string, /* No description provided */
      [@key "domain"]
      domain: string /* No description provided */,
    };
  }
  and AffectedRequest: {
    /* Information about a request that is affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "requestId"]
      requestId: Network.RequestId.t, /* The unique request id. */
      [@yojson.option] [@key "url"]
      url: option(string) /* No description provided */,
    };
  } = {
    /* Information about a request that is affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "requestId"]
      requestId: Network.RequestId.t, /* The unique request id. */
      [@yojson.option] [@key "url"]
      url: option(string) /* No description provided */,
    };
  }
  and AffectedFrame: {
    /* Information about the frame affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: Page.FrameId.t /* No description provided */,
    };
  } = {
    /* Information about the frame affected by an inspector issue. */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: Page.FrameId.t /* No description provided */,
    };
  }
  and SameSiteCookieExclusionReason: {
    type _samesitecookieexclusionreason = [
      | `ExcludeSameSiteUnspecifiedTreatedAsLax
      | `ExcludeSameSiteNoneInsecure
      | `ExcludeSameSiteLax
      | `ExcludeSameSiteStrict
      | `ExcludeInvalidSameParty
      | `ExcludeSamePartyCrossPartyContext
    ];
    let _samesitecookieexclusionreason_of_yojson:
      Yojson.Basic.t => _samesitecookieexclusionreason;
    let yojson_of__samesitecookieexclusionreason:
      _samesitecookieexclusionreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookieexclusionreason;
  } = {
    type _samesitecookieexclusionreason = [
      | `ExcludeSameSiteUnspecifiedTreatedAsLax
      | `ExcludeSameSiteNoneInsecure
      | `ExcludeSameSiteLax
      | `ExcludeSameSiteStrict
      | `ExcludeInvalidSameParty
      | `ExcludeSamePartyCrossPartyContext
    ];
    let _samesitecookieexclusionreason_of_yojson =
      fun
      | `String("ExcludeSameSiteUnspecifiedTreatedAsLax") => `ExcludeSameSiteUnspecifiedTreatedAsLax
      | `String("ExcludeSameSiteNoneInsecure") => `ExcludeSameSiteNoneInsecure
      | `String("ExcludeSameSiteLax") => `ExcludeSameSiteLax
      | `String("ExcludeSameSiteStrict") => `ExcludeSameSiteStrict
      | `String("ExcludeInvalidSameParty") => `ExcludeInvalidSameParty
      | `String("ExcludeSamePartyCrossPartyContext") => `ExcludeSamePartyCrossPartyContext
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__samesitecookieexclusionreason =
      fun
      | `ExcludeSameSiteUnspecifiedTreatedAsLax =>
        `String("ExcludeSameSiteUnspecifiedTreatedAsLax")
      | `ExcludeSameSiteNoneInsecure => `String("ExcludeSameSiteNoneInsecure")
      | `ExcludeSameSiteLax => `String("ExcludeSameSiteLax")
      | `ExcludeSameSiteStrict => `String("ExcludeSameSiteStrict")
      | `ExcludeInvalidSameParty => `String("ExcludeInvalidSameParty")
      | `ExcludeSamePartyCrossPartyContext =>
        `String("ExcludeSamePartyCrossPartyContext");
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookieexclusionreason;
  }
  and SameSiteCookieWarningReason: {
    type _samesitecookiewarningreason = [
      | `WarnSameSiteUnspecifiedCrossSiteContext
      | `WarnSameSiteNoneInsecure
      | `WarnSameSiteUnspecifiedLaxAllowUnsafe
      | `WarnSameSiteStrictLaxDowngradeStrict
      | `WarnSameSiteStrictCrossDowngradeStrict
      | `WarnSameSiteStrictCrossDowngradeLax
      | `WarnSameSiteLaxCrossDowngradeStrict
      | `WarnSameSiteLaxCrossDowngradeLax
    ];
    let _samesitecookiewarningreason_of_yojson:
      Yojson.Basic.t => _samesitecookiewarningreason;
    let yojson_of__samesitecookiewarningreason:
      _samesitecookiewarningreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookiewarningreason;
  } = {
    type _samesitecookiewarningreason = [
      | `WarnSameSiteUnspecifiedCrossSiteContext
      | `WarnSameSiteNoneInsecure
      | `WarnSameSiteUnspecifiedLaxAllowUnsafe
      | `WarnSameSiteStrictLaxDowngradeStrict
      | `WarnSameSiteStrictCrossDowngradeStrict
      | `WarnSameSiteStrictCrossDowngradeLax
      | `WarnSameSiteLaxCrossDowngradeStrict
      | `WarnSameSiteLaxCrossDowngradeLax
    ];
    let _samesitecookiewarningreason_of_yojson =
      fun
      | `String("WarnSameSiteUnspecifiedCrossSiteContext") => `WarnSameSiteUnspecifiedCrossSiteContext
      | `String("WarnSameSiteNoneInsecure") => `WarnSameSiteNoneInsecure
      | `String("WarnSameSiteUnspecifiedLaxAllowUnsafe") => `WarnSameSiteUnspecifiedLaxAllowUnsafe
      | `String("WarnSameSiteStrictLaxDowngradeStrict") => `WarnSameSiteStrictLaxDowngradeStrict
      | `String("WarnSameSiteStrictCrossDowngradeStrict") => `WarnSameSiteStrictCrossDowngradeStrict
      | `String("WarnSameSiteStrictCrossDowngradeLax") => `WarnSameSiteStrictCrossDowngradeLax
      | `String("WarnSameSiteLaxCrossDowngradeStrict") => `WarnSameSiteLaxCrossDowngradeStrict
      | `String("WarnSameSiteLaxCrossDowngradeLax") => `WarnSameSiteLaxCrossDowngradeLax
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__samesitecookiewarningreason =
      fun
      | `WarnSameSiteUnspecifiedCrossSiteContext =>
        `String("WarnSameSiteUnspecifiedCrossSiteContext")
      | `WarnSameSiteNoneInsecure => `String("WarnSameSiteNoneInsecure")
      | `WarnSameSiteUnspecifiedLaxAllowUnsafe =>
        `String("WarnSameSiteUnspecifiedLaxAllowUnsafe")
      | `WarnSameSiteStrictLaxDowngradeStrict =>
        `String("WarnSameSiteStrictLaxDowngradeStrict")
      | `WarnSameSiteStrictCrossDowngradeStrict =>
        `String("WarnSameSiteStrictCrossDowngradeStrict")
      | `WarnSameSiteStrictCrossDowngradeLax =>
        `String("WarnSameSiteStrictCrossDowngradeLax")
      | `WarnSameSiteLaxCrossDowngradeStrict =>
        `String("WarnSameSiteLaxCrossDowngradeStrict")
      | `WarnSameSiteLaxCrossDowngradeLax =>
        `String("WarnSameSiteLaxCrossDowngradeLax");
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookiewarningreason;
  }
  and SameSiteCookieOperation: {
    type _samesitecookieoperation = [ | `SetCookie | `ReadCookie];
    let _samesitecookieoperation_of_yojson:
      Yojson.Basic.t => _samesitecookieoperation;
    let yojson_of__samesitecookieoperation:
      _samesitecookieoperation => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookieoperation;
  } = {
    type _samesitecookieoperation = [ | `SetCookie | `ReadCookie];
    let _samesitecookieoperation_of_yojson =
      fun
      | `String("SetCookie") => `SetCookie
      | `String("ReadCookie") => `ReadCookie
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__samesitecookieoperation =
      fun
      | `SetCookie => `String("SetCookie")
      | `ReadCookie => `String("ReadCookie");
    /* No description provided */
    [@deriving yojson]
    type t = _samesitecookieoperation;
  }
  and SameSiteCookieIssueDetails: {
    /* This information is currently necessary, as the front-end has a difficult
       time finding a specific cookie. With this, we can convey specific error
       information without the cookie. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "cookie"]
      cookie: option(AffectedCookie.t), /* If AffectedCookie is not set then rawCookieLine contains the raw
Set-Cookie header string. This hints at a problem where the
cookie line is syntactically or semantically malformed in a way
that no valid cookie could be created. */
      [@yojson.option] [@key "rawCookieLine"]
      rawCookieLine: option(string), /* No description provided */
      [@key "cookieWarningReasons"]
      cookieWarningReasons: list(SameSiteCookieWarningReason.t), /* No description provided */
      [@key "cookieExclusionReasons"]
      cookieExclusionReasons: list(SameSiteCookieExclusionReason.t), /* No description provided */
      [@key "operation"]
      operation: SameSiteCookieOperation.t, /* Optionally identifies the site-for-cookies and the cookie url, which
may be used by the front-end as additional context. */
      [@yojson.option] [@key "siteForCookies"]
      siteForCookies: option(string), /* No description provided */
      [@yojson.option] [@key "cookieUrl"]
      cookieUrl: option(string), /* No description provided */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t) /* No description provided */,
    };
  } = {
    /* This information is currently necessary, as the front-end has a difficult
       time finding a specific cookie. With this, we can convey specific error
       information without the cookie. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "cookie"]
      cookie: option(AffectedCookie.t), /* If AffectedCookie is not set then rawCookieLine contains the raw
Set-Cookie header string. This hints at a problem where the
cookie line is syntactically or semantically malformed in a way
that no valid cookie could be created. */
      [@yojson.option] [@key "rawCookieLine"]
      rawCookieLine: option(string), /* No description provided */
      [@key "cookieWarningReasons"]
      cookieWarningReasons: list(SameSiteCookieWarningReason.t), /* No description provided */
      [@key "cookieExclusionReasons"]
      cookieExclusionReasons: list(SameSiteCookieExclusionReason.t), /* No description provided */
      [@key "operation"]
      operation: SameSiteCookieOperation.t, /* Optionally identifies the site-for-cookies and the cookie url, which
may be used by the front-end as additional context. */
      [@yojson.option] [@key "siteForCookies"]
      siteForCookies: option(string), /* No description provided */
      [@yojson.option] [@key "cookieUrl"]
      cookieUrl: option(string), /* No description provided */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t) /* No description provided */,
    };
  }
  and MixedContentResolutionStatus: {
    type _mixedcontentresolutionstatus = [
      | `MixedContentBlocked
      | `MixedContentAutomaticallyUpgraded
      | `MixedContentWarning
    ];
    let _mixedcontentresolutionstatus_of_yojson:
      Yojson.Basic.t => _mixedcontentresolutionstatus;
    let yojson_of__mixedcontentresolutionstatus:
      _mixedcontentresolutionstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _mixedcontentresolutionstatus;
  } = {
    type _mixedcontentresolutionstatus = [
      | `MixedContentBlocked
      | `MixedContentAutomaticallyUpgraded
      | `MixedContentWarning
    ];
    let _mixedcontentresolutionstatus_of_yojson =
      fun
      | `String("MixedContentBlocked") => `MixedContentBlocked
      | `String("MixedContentAutomaticallyUpgraded") => `MixedContentAutomaticallyUpgraded
      | `String("MixedContentWarning") => `MixedContentWarning
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__mixedcontentresolutionstatus =
      fun
      | `MixedContentBlocked => `String("MixedContentBlocked")
      | `MixedContentAutomaticallyUpgraded =>
        `String("MixedContentAutomaticallyUpgraded")
      | `MixedContentWarning => `String("MixedContentWarning");
    /* No description provided */
    [@deriving yojson]
    type t = _mixedcontentresolutionstatus;
  }
  and MixedContentResourceType: {
    type _mixedcontentresourcetype = [
      | `Audio
      | `Beacon
      | `CSPReport
      | `Download
      | `EventSource
      | `Favicon
      | `Font
      | `Form
      | `Frame
      | `Image
      | `Import
      | `Manifest
      | `Ping
      | `PluginData
      | `PluginResource
      | `Prefetch
      | `Resource
      | `Script
      | `ServiceWorker
      | `SharedWorker
      | `Stylesheet
      | `Track
      | `Video
      | `Worker
      | `XMLHttpRequest
      | `XSLT
    ];
    let _mixedcontentresourcetype_of_yojson:
      Yojson.Basic.t => _mixedcontentresourcetype;
    let yojson_of__mixedcontentresourcetype:
      _mixedcontentresourcetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _mixedcontentresourcetype;
  } = {
    type _mixedcontentresourcetype = [
      | `Audio
      | `Beacon
      | `CSPReport
      | `Download
      | `EventSource
      | `Favicon
      | `Font
      | `Form
      | `Frame
      | `Image
      | `Import
      | `Manifest
      | `Ping
      | `PluginData
      | `PluginResource
      | `Prefetch
      | `Resource
      | `Script
      | `ServiceWorker
      | `SharedWorker
      | `Stylesheet
      | `Track
      | `Video
      | `Worker
      | `XMLHttpRequest
      | `XSLT
    ];
    let _mixedcontentresourcetype_of_yojson =
      fun
      | `String("Audio") => `Audio
      | `String("Beacon") => `Beacon
      | `String("CSPReport") => `CSPReport
      | `String("Download") => `Download
      | `String("EventSource") => `EventSource
      | `String("Favicon") => `Favicon
      | `String("Font") => `Font
      | `String("Form") => `Form
      | `String("Frame") => `Frame
      | `String("Image") => `Image
      | `String("Import") => `Import
      | `String("Manifest") => `Manifest
      | `String("Ping") => `Ping
      | `String("PluginData") => `PluginData
      | `String("PluginResource") => `PluginResource
      | `String("Prefetch") => `Prefetch
      | `String("Resource") => `Resource
      | `String("Script") => `Script
      | `String("ServiceWorker") => `ServiceWorker
      | `String("SharedWorker") => `SharedWorker
      | `String("Stylesheet") => `Stylesheet
      | `String("Track") => `Track
      | `String("Video") => `Video
      | `String("Worker") => `Worker
      | `String("XMLHttpRequest") => `XMLHttpRequest
      | `String("XSLT") => `XSLT
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__mixedcontentresourcetype =
      fun
      | `Audio => `String("Audio")
      | `Beacon => `String("Beacon")
      | `CSPReport => `String("CSPReport")
      | `Download => `String("Download")
      | `EventSource => `String("EventSource")
      | `Favicon => `String("Favicon")
      | `Font => `String("Font")
      | `Form => `String("Form")
      | `Frame => `String("Frame")
      | `Image => `String("Image")
      | `Import => `String("Import")
      | `Manifest => `String("Manifest")
      | `Ping => `String("Ping")
      | `PluginData => `String("PluginData")
      | `PluginResource => `String("PluginResource")
      | `Prefetch => `String("Prefetch")
      | `Resource => `String("Resource")
      | `Script => `String("Script")
      | `ServiceWorker => `String("ServiceWorker")
      | `SharedWorker => `String("SharedWorker")
      | `Stylesheet => `String("Stylesheet")
      | `Track => `String("Track")
      | `Video => `String("Video")
      | `Worker => `String("Worker")
      | `XMLHttpRequest => `String("XMLHttpRequest")
      | `XSLT => `String("XSLT");
    /* No description provided */
    [@deriving yojson]
    type t = _mixedcontentresourcetype;
  }
  and MixedContentIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "resourceType"]
      resourceType: option(MixedContentResourceType.t), /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
      [@key "resolutionStatus"]
      resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
      [@key "insecureURL"]
      insecureURL: string, /* The unsafe http url causing the mixed content issue. */
      [@key "mainResourceURL"]
      mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t), /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
      [@yojson.option] [@key "frame"]
      frame: option(AffectedFrame.t) /* Optional because not every mixed content issue is necessarily linked to a frame. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "resourceType"]
      resourceType: option(MixedContentResourceType.t), /* The type of resource causing the mixed content issue (css, js, iframe,
form,...). Marked as optional because it is mapped to from
blink::mojom::RequestContextType, which will be replaced
by network::mojom::RequestDestination */
      [@key "resolutionStatus"]
      resolutionStatus: MixedContentResolutionStatus.t, /* The way the mixed content issue is being resolved. */
      [@key "insecureURL"]
      insecureURL: string, /* The unsafe http url causing the mixed content issue. */
      [@key "mainResourceURL"]
      mainResourceURL: string, /* The url responsible for the call to an unsafe url. */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t), /* The mixed content request.
Does not always exist (e.g. for unsafe form submission urls). */
      [@yojson.option] [@key "frame"]
      frame: option(AffectedFrame.t) /* Optional because not every mixed content issue is necessarily linked to a frame. */,
    };
  }
  and BlockedByResponseReason: {
    type _blockedbyresponsereason = [
      | `CoepFrameResourceNeedsCoepHeader
      | `CoopSandboxedIFrameCannotNavigateToCoopPage
      | `CorpNotSameOrigin
      | `CorpNotSameOriginAfterDefaultedToSameOriginByCoep
      | `CorpNotSameSite
    ];
    let _blockedbyresponsereason_of_yojson:
      Yojson.Basic.t => _blockedbyresponsereason;
    let yojson_of__blockedbyresponsereason:
      _blockedbyresponsereason => Yojson.Basic.t;
    /* Enum indicating the reason a response has been blocked. These reasons are
       refinements of the net error BLOCKED_BY_RESPONSE. */
    [@deriving yojson]
    type t = _blockedbyresponsereason;
  } = {
    type _blockedbyresponsereason = [
      | `CoepFrameResourceNeedsCoepHeader
      | `CoopSandboxedIFrameCannotNavigateToCoopPage
      | `CorpNotSameOrigin
      | `CorpNotSameOriginAfterDefaultedToSameOriginByCoep
      | `CorpNotSameSite
    ];
    let _blockedbyresponsereason_of_yojson =
      fun
      | `String("CoepFrameResourceNeedsCoepHeader") => `CoepFrameResourceNeedsCoepHeader
      | `String("CoopSandboxedIFrameCannotNavigateToCoopPage") => `CoopSandboxedIFrameCannotNavigateToCoopPage
      | `String("CorpNotSameOrigin") => `CorpNotSameOrigin
      | `String("CorpNotSameOriginAfterDefaultedToSameOriginByCoep") => `CorpNotSameOriginAfterDefaultedToSameOriginByCoep
      | `String("CorpNotSameSite") => `CorpNotSameSite
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__blockedbyresponsereason =
      fun
      | `CoepFrameResourceNeedsCoepHeader =>
        `String("CoepFrameResourceNeedsCoepHeader")
      | `CoopSandboxedIFrameCannotNavigateToCoopPage =>
        `String("CoopSandboxedIFrameCannotNavigateToCoopPage")
      | `CorpNotSameOrigin => `String("CorpNotSameOrigin")
      | `CorpNotSameOriginAfterDefaultedToSameOriginByCoep =>
        `String("CorpNotSameOriginAfterDefaultedToSameOriginByCoep")
      | `CorpNotSameSite => `String("CorpNotSameSite");
    /* Enum indicating the reason a response has been blocked. These reasons are
       refinements of the net error BLOCKED_BY_RESPONSE. */
    [@deriving yojson]
    type t = _blockedbyresponsereason;
  }
  and BlockedByResponseIssueDetails: {
    /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
       code. Currently only used for COEP/COOP, but may be extended to include
       some CSP errors in the future. */
    [@deriving yojson]
    type t = {
      [@key "request"]
      request: AffectedRequest.t, /* No description provided */
      [@yojson.option] [@key "parentFrame"]
      parentFrame: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "blockedFrame"]
      blockedFrame: option(AffectedFrame.t), /* No description provided */
      [@key "reason"]
      reason: BlockedByResponseReason.t /* No description provided */,
    };
  } = {
    /* Details for a request that has been blocked with the BLOCKED_BY_RESPONSE
       code. Currently only used for COEP/COOP, but may be extended to include
       some CSP errors in the future. */
    [@deriving yojson]
    type t = {
      [@key "request"]
      request: AffectedRequest.t, /* No description provided */
      [@yojson.option] [@key "parentFrame"]
      parentFrame: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "blockedFrame"]
      blockedFrame: option(AffectedFrame.t), /* No description provided */
      [@key "reason"]
      reason: BlockedByResponseReason.t /* No description provided */,
    };
  }
  and HeavyAdResolutionStatus: {
    type _heavyadresolutionstatus = [ | `HeavyAdBlocked | `HeavyAdWarning];
    let _heavyadresolutionstatus_of_yojson:
      Yojson.Basic.t => _heavyadresolutionstatus;
    let yojson_of__heavyadresolutionstatus:
      _heavyadresolutionstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _heavyadresolutionstatus;
  } = {
    type _heavyadresolutionstatus = [ | `HeavyAdBlocked | `HeavyAdWarning];
    let _heavyadresolutionstatus_of_yojson =
      fun
      | `String("HeavyAdBlocked") => `HeavyAdBlocked
      | `String("HeavyAdWarning") => `HeavyAdWarning
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__heavyadresolutionstatus =
      fun
      | `HeavyAdBlocked => `String("HeavyAdBlocked")
      | `HeavyAdWarning => `String("HeavyAdWarning");
    /* No description provided */
    [@deriving yojson]
    type t = _heavyadresolutionstatus;
  }
  and HeavyAdReason: {
    type _heavyadreason = [
      | `NetworkTotalLimit
      | `CpuTotalLimit
      | `CpuPeakLimit
    ];
    let _heavyadreason_of_yojson: Yojson.Basic.t => _heavyadreason;
    let yojson_of__heavyadreason: _heavyadreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _heavyadreason;
  } = {
    type _heavyadreason = [
      | `NetworkTotalLimit
      | `CpuTotalLimit
      | `CpuPeakLimit
    ];
    let _heavyadreason_of_yojson =
      fun
      | `String("NetworkTotalLimit") => `NetworkTotalLimit
      | `String("CpuTotalLimit") => `CpuTotalLimit
      | `String("CpuPeakLimit") => `CpuPeakLimit
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__heavyadreason =
      fun
      | `NetworkTotalLimit => `String("NetworkTotalLimit")
      | `CpuTotalLimit => `String("CpuTotalLimit")
      | `CpuPeakLimit => `String("CpuPeakLimit");
    /* No description provided */
    [@deriving yojson]
    type t = _heavyadreason;
  }
  and HeavyAdIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "resolution"]
      resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
      [@key "reason"]
      reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
      [@key "frame"]
      frame: AffectedFrame.t /* The frame that was blocked. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "resolution"]
      resolution: HeavyAdResolutionStatus.t, /* The resolution status, either blocking the content or warning. */
      [@key "reason"]
      reason: HeavyAdReason.t, /* The reason the ad was blocked, total network or cpu or peak cpu. */
      [@key "frame"]
      frame: AffectedFrame.t /* The frame that was blocked. */,
    };
  }
  and ContentSecurityPolicyViolationType: {
    type _contentsecuritypolicyviolationtype = [
      | `kInlineViolation
      | `kEvalViolation
      | `kURLViolation
      | `kTrustedTypesSinkViolation
      | `kTrustedTypesPolicyViolation
      | `kWasmEvalViolation
    ];
    let _contentsecuritypolicyviolationtype_of_yojson:
      Yojson.Basic.t => _contentsecuritypolicyviolationtype;
    let yojson_of__contentsecuritypolicyviolationtype:
      _contentsecuritypolicyviolationtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _contentsecuritypolicyviolationtype;
  } = {
    type _contentsecuritypolicyviolationtype = [
      | `kInlineViolation
      | `kEvalViolation
      | `kURLViolation
      | `kTrustedTypesSinkViolation
      | `kTrustedTypesPolicyViolation
      | `kWasmEvalViolation
    ];
    let _contentsecuritypolicyviolationtype_of_yojson =
      fun
      | `String("kInlineViolation") => `kInlineViolation
      | `String("kEvalViolation") => `kEvalViolation
      | `String("kURLViolation") => `kURLViolation
      | `String("kTrustedTypesSinkViolation") => `kTrustedTypesSinkViolation
      | `String("kTrustedTypesPolicyViolation") => `kTrustedTypesPolicyViolation
      | `String("kWasmEvalViolation") => `kWasmEvalViolation
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__contentsecuritypolicyviolationtype =
      fun
      | `kInlineViolation => `String("kInlineViolation")
      | `kEvalViolation => `String("kEvalViolation")
      | `kURLViolation => `String("kURLViolation")
      | `kTrustedTypesSinkViolation => `String("kTrustedTypesSinkViolation")
      | `kTrustedTypesPolicyViolation =>
        `String("kTrustedTypesPolicyViolation")
      | `kWasmEvalViolation => `String("kWasmEvalViolation");
    /* No description provided */
    [@deriving yojson]
    type t = _contentsecuritypolicyviolationtype;
  }
  and SourceCodeLocation: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "scriptId"]
      scriptId: option(Runtime.ScriptId.t), /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "scriptId"]
      scriptId: option(Runtime.ScriptId.t), /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  }
  and ContentSecurityPolicyIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "blockedURL"]
      blockedURL: option(string), /* The url not included in allowed sources. */
      [@key "violatedDirective"]
      violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
      [@key "isReportOnly"]
      isReportOnly: bool, /* No description provided */
      [@key "contentSecurityPolicyViolationType"]
      contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
      [@yojson.option] [@key "frameAncestor"]
      frameAncestor: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "sourceCodeLocation"]
      sourceCodeLocation: option(SourceCodeLocation.t), /* No description provided */
      [@yojson.option] [@key "violatingNodeId"]
      violatingNodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "blockedURL"]
      blockedURL: option(string), /* The url not included in allowed sources. */
      [@key "violatedDirective"]
      violatedDirective: string, /* Specific directive that is violated, causing the CSP issue. */
      [@key "isReportOnly"]
      isReportOnly: bool, /* No description provided */
      [@key "contentSecurityPolicyViolationType"]
      contentSecurityPolicyViolationType: ContentSecurityPolicyViolationType.t, /* No description provided */
      [@yojson.option] [@key "frameAncestor"]
      frameAncestor: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "sourceCodeLocation"]
      sourceCodeLocation: option(SourceCodeLocation.t), /* No description provided */
      [@yojson.option] [@key "violatingNodeId"]
      violatingNodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  }
  and SharedArrayBufferIssueType: {
    type _sharedarraybufferissuetype = [ | `TransferIssue | `CreationIssue];
    let _sharedarraybufferissuetype_of_yojson:
      Yojson.Basic.t => _sharedarraybufferissuetype;
    let yojson_of__sharedarraybufferissuetype:
      _sharedarraybufferissuetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _sharedarraybufferissuetype;
  } = {
    type _sharedarraybufferissuetype = [ | `TransferIssue | `CreationIssue];
    let _sharedarraybufferissuetype_of_yojson =
      fun
      | `String("TransferIssue") => `TransferIssue
      | `String("CreationIssue") => `CreationIssue
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__sharedarraybufferissuetype =
      fun
      | `TransferIssue => `String("TransferIssue")
      | `CreationIssue => `String("CreationIssue");
    /* No description provided */
    [@deriving yojson]
    type t = _sharedarraybufferissuetype;
  }
  and SharedArrayBufferIssueDetails: {
    /* Details for a issue arising from an SAB being instantiated in, or
       transferred to a context that is not cross-origin isolated. */
    [@deriving yojson]
    type t = {
      [@key "sourceCodeLocation"]
      sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
      [@key "isWarning"]
      isWarning: bool, /* No description provided */
      [@key "type"]
      type_: SharedArrayBufferIssueType.t /* No description provided */,
    };
  } = {
    /* Details for a issue arising from an SAB being instantiated in, or
       transferred to a context that is not cross-origin isolated. */
    [@deriving yojson]
    type t = {
      [@key "sourceCodeLocation"]
      sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
      [@key "isWarning"]
      isWarning: bool, /* No description provided */
      [@key "type"]
      type_: SharedArrayBufferIssueType.t /* No description provided */,
    };
  }
  and TwaQualityEnforcementViolationType: {
    type _twaqualityenforcementviolationtype = [
      | `kHttpError
      | `kUnavailableOffline
      | `kDigitalAssetLinks
    ];
    let _twaqualityenforcementviolationtype_of_yojson:
      Yojson.Basic.t => _twaqualityenforcementviolationtype;
    let yojson_of__twaqualityenforcementviolationtype:
      _twaqualityenforcementviolationtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _twaqualityenforcementviolationtype;
  } = {
    type _twaqualityenforcementviolationtype = [
      | `kHttpError
      | `kUnavailableOffline
      | `kDigitalAssetLinks
    ];
    let _twaqualityenforcementviolationtype_of_yojson =
      fun
      | `String("kHttpError") => `kHttpError
      | `String("kUnavailableOffline") => `kUnavailableOffline
      | `String("kDigitalAssetLinks") => `kDigitalAssetLinks
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__twaqualityenforcementviolationtype =
      fun
      | `kHttpError => `String("kHttpError")
      | `kUnavailableOffline => `String("kUnavailableOffline")
      | `kDigitalAssetLinks => `String("kDigitalAssetLinks");
    /* No description provided */
    [@deriving yojson]
    type t = _twaqualityenforcementviolationtype;
  }
  and TrustedWebActivityIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The url that triggers the violation. */
      [@key "violationType"]
      violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
      [@yojson.option] [@key "httpStatusCode"]
      httpStatusCode: option(float), /* No description provided */
      [@yojson.option] [@key "packageName"]
      packageName: option(string), /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
      [@yojson.option] [@key "signature"]
      signature: option(string) /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The url that triggers the violation. */
      [@key "violationType"]
      violationType: TwaQualityEnforcementViolationType.t, /* No description provided */
      [@yojson.option] [@key "httpStatusCode"]
      httpStatusCode: option(float), /* No description provided */
      [@yojson.option] [@key "packageName"]
      packageName: option(string), /* The package name of the Trusted Web Activity client app. This field is
only used when violation type is kDigitalAssetLinks. */
      [@yojson.option] [@key "signature"]
      signature: option(string) /* The signature of the Trusted Web Activity client app. This field is only
used when violation type is kDigitalAssetLinks. */,
    };
  }
  and LowTextContrastIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "violatingNodeId"]
      violatingNodeId: DOM.BackendNodeId.t, /* No description provided */
      [@key "violatingNodeSelector"]
      violatingNodeSelector: string, /* No description provided */
      [@key "contrastRatio"]
      contrastRatio: float, /* No description provided */
      [@key "thresholdAA"]
      thresholdAA: float, /* No description provided */
      [@key "thresholdAAA"]
      thresholdAAA: float, /* No description provided */
      [@key "fontSize"]
      fontSize: string, /* No description provided */
      [@key "fontWeight"]
      fontWeight: string /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "violatingNodeId"]
      violatingNodeId: DOM.BackendNodeId.t, /* No description provided */
      [@key "violatingNodeSelector"]
      violatingNodeSelector: string, /* No description provided */
      [@key "contrastRatio"]
      contrastRatio: float, /* No description provided */
      [@key "thresholdAA"]
      thresholdAA: float, /* No description provided */
      [@key "thresholdAAA"]
      thresholdAAA: float, /* No description provided */
      [@key "fontSize"]
      fontSize: string, /* No description provided */
      [@key "fontWeight"]
      fontWeight: string /* No description provided */,
    };
  }
  and CorsIssueDetails: {
    /* Details for a CORS related issue, e.g. a warning or error related to
       CORS RFC1918 enforcement. */
    [@deriving yojson]
    type t = {
      [@key "corsErrorStatus"]
      corsErrorStatus: Network.CorsErrorStatus.t, /* No description provided */
      [@key "isWarning"]
      isWarning: bool, /* No description provided */
      [@key "request"]
      request: AffectedRequest.t, /* No description provided */
      [@yojson.option] [@key "location"]
      location: option(SourceCodeLocation.t), /* No description provided */
      [@yojson.option] [@key "initiatorOrigin"]
      initiatorOrigin: option(string), /* No description provided */
      [@yojson.option] [@key "resourceIPAddressSpace"]
      resourceIPAddressSpace: option(Network.IPAddressSpace.t), /* No description provided */
      [@yojson.option] [@key "clientSecurityState"]
      clientSecurityState: option(Network.ClientSecurityState.t) /* No description provided */,
    };
  } = {
    /* Details for a CORS related issue, e.g. a warning or error related to
       CORS RFC1918 enforcement. */
    [@deriving yojson]
    type t = {
      [@key "corsErrorStatus"]
      corsErrorStatus: Network.CorsErrorStatus.t, /* No description provided */
      [@key "isWarning"]
      isWarning: bool, /* No description provided */
      [@key "request"]
      request: AffectedRequest.t, /* No description provided */
      [@yojson.option] [@key "location"]
      location: option(SourceCodeLocation.t), /* No description provided */
      [@yojson.option] [@key "initiatorOrigin"]
      initiatorOrigin: option(string), /* No description provided */
      [@yojson.option] [@key "resourceIPAddressSpace"]
      resourceIPAddressSpace: option(Network.IPAddressSpace.t), /* No description provided */
      [@yojson.option] [@key "clientSecurityState"]
      clientSecurityState: option(Network.ClientSecurityState.t) /* No description provided */,
    };
  }
  and AttributionReportingIssueType: {
    type _attributionreportingissuetype = [
      | `PermissionPolicyDisabled
      | `InvalidAttributionSourceEventId
      | `InvalidAttributionData
      | `AttributionSourceUntrustworthyOrigin
      | `AttributionUntrustworthyOrigin
      | `AttributionTriggerDataTooLarge
      | `AttributionEventSourceTriggerDataTooLarge
    ];
    let _attributionreportingissuetype_of_yojson:
      Yojson.Basic.t => _attributionreportingissuetype;
    let yojson_of__attributionreportingissuetype:
      _attributionreportingissuetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _attributionreportingissuetype;
  } = {
    type _attributionreportingissuetype = [
      | `PermissionPolicyDisabled
      | `InvalidAttributionSourceEventId
      | `InvalidAttributionData
      | `AttributionSourceUntrustworthyOrigin
      | `AttributionUntrustworthyOrigin
      | `AttributionTriggerDataTooLarge
      | `AttributionEventSourceTriggerDataTooLarge
    ];
    let _attributionreportingissuetype_of_yojson =
      fun
      | `String("PermissionPolicyDisabled") => `PermissionPolicyDisabled
      | `String("InvalidAttributionSourceEventId") => `InvalidAttributionSourceEventId
      | `String("InvalidAttributionData") => `InvalidAttributionData
      | `String("AttributionSourceUntrustworthyOrigin") => `AttributionSourceUntrustworthyOrigin
      | `String("AttributionUntrustworthyOrigin") => `AttributionUntrustworthyOrigin
      | `String("AttributionTriggerDataTooLarge") => `AttributionTriggerDataTooLarge
      | `String("AttributionEventSourceTriggerDataTooLarge") => `AttributionEventSourceTriggerDataTooLarge
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__attributionreportingissuetype =
      fun
      | `PermissionPolicyDisabled => `String("PermissionPolicyDisabled")
      | `InvalidAttributionSourceEventId =>
        `String("InvalidAttributionSourceEventId")
      | `InvalidAttributionData => `String("InvalidAttributionData")
      | `AttributionSourceUntrustworthyOrigin =>
        `String("AttributionSourceUntrustworthyOrigin")
      | `AttributionUntrustworthyOrigin =>
        `String("AttributionUntrustworthyOrigin")
      | `AttributionTriggerDataTooLarge =>
        `String("AttributionTriggerDataTooLarge")
      | `AttributionEventSourceTriggerDataTooLarge =>
        `String("AttributionEventSourceTriggerDataTooLarge");
    /* No description provided */
    [@deriving yojson]
    type t = _attributionreportingissuetype;
  }
  and AttributionReportingIssueDetails: {
    /* Details for issues around "Attribution Reporting API" usage.
       Explainer: https://github.com/WICG/conversion-measurement-api */
    [@deriving yojson]
    type t = {
      [@key "violationType"]
      violationType: AttributionReportingIssueType.t, /* No description provided */
      [@yojson.option] [@key "frame"]
      frame: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t), /* No description provided */
      [@yojson.option] [@key "violatingNodeId"]
      violatingNodeId: option(DOM.BackendNodeId.t), /* No description provided */
      [@yojson.option] [@key "invalidParameter"]
      invalidParameter: option(string) /* No description provided */,
    };
  } = {
    /* Details for issues around "Attribution Reporting API" usage.
       Explainer: https://github.com/WICG/conversion-measurement-api */
    [@deriving yojson]
    type t = {
      [@key "violationType"]
      violationType: AttributionReportingIssueType.t, /* No description provided */
      [@yojson.option] [@key "frame"]
      frame: option(AffectedFrame.t), /* No description provided */
      [@yojson.option] [@key "request"]
      request: option(AffectedRequest.t), /* No description provided */
      [@yojson.option] [@key "violatingNodeId"]
      violatingNodeId: option(DOM.BackendNodeId.t), /* No description provided */
      [@yojson.option] [@key "invalidParameter"]
      invalidParameter: option(string) /* No description provided */,
    };
  }
  and QuirksModeIssueDetails: {
    /* Details for issues about documents in Quirks Mode
       or Limited Quirks Mode that affects page layouting. */
    [@deriving yojson]
    type t = {
      [@key "isLimitedQuirksMode"]
      isLimitedQuirksMode: bool, /* If false, it means the document's mode is "quirks"
instead of "limited-quirks". */
      [@key "documentNodeId"]
      documentNodeId: DOM.BackendNodeId.t, /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "frameId"]
      frameId: Page.FrameId.t, /* No description provided */
      [@key "loaderId"]
      loaderId: Network.LoaderId.t /* No description provided */,
    };
  } = {
    /* Details for issues about documents in Quirks Mode
       or Limited Quirks Mode that affects page layouting. */
    [@deriving yojson]
    type t = {
      [@key "isLimitedQuirksMode"]
      isLimitedQuirksMode: bool, /* If false, it means the document's mode is "quirks"
instead of "limited-quirks". */
      [@key "documentNodeId"]
      documentNodeId: DOM.BackendNodeId.t, /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "frameId"]
      frameId: Page.FrameId.t, /* No description provided */
      [@key "loaderId"]
      loaderId: Network.LoaderId.t /* No description provided */,
    };
  }
  and NavigatorUserAgentIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* No description provided */
      [@yojson.option] [@key "location"]
      location: option(SourceCodeLocation.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* No description provided */
      [@yojson.option] [@key "location"]
      location: option(SourceCodeLocation.t) /* No description provided */,
    };
  }
  and WasmCrossOriginModuleSharingIssueDetails: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "wasmModuleUrl"]
      wasmModuleUrl: string, /* No description provided */
      [@key "sourceOrigin"]
      sourceOrigin: string, /* No description provided */
      [@key "targetOrigin"]
      targetOrigin: string, /* No description provided */
      [@key "isWarning"]
      isWarning: bool /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "wasmModuleUrl"]
      wasmModuleUrl: string, /* No description provided */
      [@key "sourceOrigin"]
      sourceOrigin: string, /* No description provided */
      [@key "targetOrigin"]
      targetOrigin: string, /* No description provided */
      [@key "isWarning"]
      isWarning: bool /* No description provided */,
    };
  }
  and GenericIssueErrorType: {
    type _genericissueerrortype = [ | `CrossOriginPortalPostMessageError];
    let _genericissueerrortype_of_yojson:
      Yojson.Basic.t => _genericissueerrortype;
    let yojson_of__genericissueerrortype:
      _genericissueerrortype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _genericissueerrortype;
  } = {
    type _genericissueerrortype = [ | `CrossOriginPortalPostMessageError];
    let _genericissueerrortype_of_yojson =
      fun
      | `String("CrossOriginPortalPostMessageError") => `CrossOriginPortalPostMessageError
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__genericissueerrortype =
      fun
      | `CrossOriginPortalPostMessageError =>
        `String("CrossOriginPortalPostMessageError");
    /* No description provided */
    [@deriving yojson]
    type t = _genericissueerrortype;
  }
  and GenericIssueDetails: {
    /* Depending on the concrete errorType, different properties are set. */
    [@deriving yojson]
    type t = {
      [@key "errorType"]
      errorType: GenericIssueErrorType.t, /* Issues with the same errorType are aggregated in the frontend. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t) /* No description provided */,
    };
  } = {
    /* Depending on the concrete errorType, different properties are set. */
    [@deriving yojson]
    type t = {
      [@key "errorType"]
      errorType: GenericIssueErrorType.t, /* Issues with the same errorType are aggregated in the frontend. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t) /* No description provided */,
    };
  }
  and DeprecationIssueDetails: {
    /* This issue tracks information needed to print a deprecation message.
       The formatting is inherited from the old console.log version, see more at:
       https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/renderer/core/frame/deprecation.cc
       TODO(crbug.com/1264960): Re-work format to add i18n support per:
       https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/public/devtools_protocol/README.md */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "affectedFrame"]
      affectedFrame: option(AffectedFrame.t), /* No description provided */
      [@key "sourceCodeLocation"]
      sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
      [@yojson.option] [@key "message"]
      message: option(string) /* The content of the deprecation issue (this won't be translated),
e.g. "window.inefficientLegacyStorageMethod will be removed in M97,
around January 2022. Please use Web Storage or Indexed Database
instead. This standard was abandoned in January, 1970. See
https://www.chromestatus.com/feature/5684870116278272 for more details." */,
    };
  } = {
    /* This issue tracks information needed to print a deprecation message.
       The formatting is inherited from the old console.log version, see more at:
       https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/renderer/core/frame/deprecation.cc
       TODO(crbug.com/1264960): Re-work format to add i18n support per:
       https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/public/devtools_protocol/README.md */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "affectedFrame"]
      affectedFrame: option(AffectedFrame.t), /* No description provided */
      [@key "sourceCodeLocation"]
      sourceCodeLocation: SourceCodeLocation.t, /* No description provided */
      [@yojson.option] [@key "message"]
      message: option(string) /* The content of the deprecation issue (this won't be translated),
e.g. "window.inefficientLegacyStorageMethod will be removed in M97,
around January 2022. Please use Web Storage or Indexed Database
instead. This standard was abandoned in January, 1970. See
https://www.chromestatus.com/feature/5684870116278272 for more details." */,
    };
  }
  and InspectorIssueCode: {
    type _inspectorissuecode = [
      | `SameSiteCookieIssue
      | `MixedContentIssue
      | `BlockedByResponseIssue
      | `HeavyAdIssue
      | `ContentSecurityPolicyIssue
      | `SharedArrayBufferIssue
      | `TrustedWebActivityIssue
      | `LowTextContrastIssue
      | `CorsIssue
      | `AttributionReportingIssue
      | `QuirksModeIssue
      | `NavigatorUserAgentIssue
      | `WasmCrossOriginModuleSharingIssue
      | `GenericIssue
      | `DeprecationIssue
    ];
    let _inspectorissuecode_of_yojson: Yojson.Basic.t => _inspectorissuecode;
    let yojson_of__inspectorissuecode: _inspectorissuecode => Yojson.Basic.t;
    /* A unique identifier for the type of issue. Each type may use one of the
       optional fields in InspectorIssueDetails to convey more specific
       information about the kind of issue. */
    [@deriving yojson]
    type t = _inspectorissuecode;
  } = {
    type _inspectorissuecode = [
      | `SameSiteCookieIssue
      | `MixedContentIssue
      | `BlockedByResponseIssue
      | `HeavyAdIssue
      | `ContentSecurityPolicyIssue
      | `SharedArrayBufferIssue
      | `TrustedWebActivityIssue
      | `LowTextContrastIssue
      | `CorsIssue
      | `AttributionReportingIssue
      | `QuirksModeIssue
      | `NavigatorUserAgentIssue
      | `WasmCrossOriginModuleSharingIssue
      | `GenericIssue
      | `DeprecationIssue
    ];
    let _inspectorissuecode_of_yojson =
      fun
      | `String("SameSiteCookieIssue") => `SameSiteCookieIssue
      | `String("MixedContentIssue") => `MixedContentIssue
      | `String("BlockedByResponseIssue") => `BlockedByResponseIssue
      | `String("HeavyAdIssue") => `HeavyAdIssue
      | `String("ContentSecurityPolicyIssue") => `ContentSecurityPolicyIssue
      | `String("SharedArrayBufferIssue") => `SharedArrayBufferIssue
      | `String("TrustedWebActivityIssue") => `TrustedWebActivityIssue
      | `String("LowTextContrastIssue") => `LowTextContrastIssue
      | `String("CorsIssue") => `CorsIssue
      | `String("AttributionReportingIssue") => `AttributionReportingIssue
      | `String("QuirksModeIssue") => `QuirksModeIssue
      | `String("NavigatorUserAgentIssue") => `NavigatorUserAgentIssue
      | `String("WasmCrossOriginModuleSharingIssue") => `WasmCrossOriginModuleSharingIssue
      | `String("GenericIssue") => `GenericIssue
      | `String("DeprecationIssue") => `DeprecationIssue
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__inspectorissuecode =
      fun
      | `SameSiteCookieIssue => `String("SameSiteCookieIssue")
      | `MixedContentIssue => `String("MixedContentIssue")
      | `BlockedByResponseIssue => `String("BlockedByResponseIssue")
      | `HeavyAdIssue => `String("HeavyAdIssue")
      | `ContentSecurityPolicyIssue => `String("ContentSecurityPolicyIssue")
      | `SharedArrayBufferIssue => `String("SharedArrayBufferIssue")
      | `TrustedWebActivityIssue => `String("TrustedWebActivityIssue")
      | `LowTextContrastIssue => `String("LowTextContrastIssue")
      | `CorsIssue => `String("CorsIssue")
      | `AttributionReportingIssue => `String("AttributionReportingIssue")
      | `QuirksModeIssue => `String("QuirksModeIssue")
      | `NavigatorUserAgentIssue => `String("NavigatorUserAgentIssue")
      | `WasmCrossOriginModuleSharingIssue =>
        `String("WasmCrossOriginModuleSharingIssue")
      | `GenericIssue => `String("GenericIssue")
      | `DeprecationIssue => `String("DeprecationIssue");
    /* A unique identifier for the type of issue. Each type may use one of the
       optional fields in InspectorIssueDetails to convey more specific
       information about the kind of issue. */
    [@deriving yojson]
    type t = _inspectorissuecode;
  }
  and InspectorIssueDetails: {
    /* This struct holds a list of optional fields with additional information
       specific to the kind of issue. When adding a new issue code, please also
       add a new optional field to this type. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "sameSiteCookieIssueDetails"]
      sameSiteCookieIssueDetails: option(SameSiteCookieIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "mixedContentIssueDetails"]
      mixedContentIssueDetails: option(MixedContentIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "blockedByResponseIssueDetails"]
      blockedByResponseIssueDetails: option(BlockedByResponseIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "heavyAdIssueDetails"]
      heavyAdIssueDetails: option(HeavyAdIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "contentSecurityPolicyIssueDetails"]
      contentSecurityPolicyIssueDetails:
        option(ContentSecurityPolicyIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "sharedArrayBufferIssueDetails"]
      sharedArrayBufferIssueDetails: option(SharedArrayBufferIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "twaQualityEnforcementDetails"]
      twaQualityEnforcementDetails: option(TrustedWebActivityIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "lowTextContrastIssueDetails"]
      lowTextContrastIssueDetails: option(LowTextContrastIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "corsIssueDetails"]
      corsIssueDetails: option(CorsIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "attributionReportingIssueDetails"]
      attributionReportingIssueDetails:
        option(AttributionReportingIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "quirksModeIssueDetails"]
      quirksModeIssueDetails: option(QuirksModeIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "navigatorUserAgentIssueDetails"]
      navigatorUserAgentIssueDetails:
        option(NavigatorUserAgentIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "wasmCrossOriginModuleSharingIssue"]
      wasmCrossOriginModuleSharingIssue:
        option(WasmCrossOriginModuleSharingIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "genericIssueDetails"]
      genericIssueDetails: option(GenericIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "deprecationIssueDetails"]
      deprecationIssueDetails: option(DeprecationIssueDetails.t) /* No description provided */,
    };
  } = {
    /* This struct holds a list of optional fields with additional information
       specific to the kind of issue. When adding a new issue code, please also
       add a new optional field to this type. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "sameSiteCookieIssueDetails"]
      sameSiteCookieIssueDetails: option(SameSiteCookieIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "mixedContentIssueDetails"]
      mixedContentIssueDetails: option(MixedContentIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "blockedByResponseIssueDetails"]
      blockedByResponseIssueDetails: option(BlockedByResponseIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "heavyAdIssueDetails"]
      heavyAdIssueDetails: option(HeavyAdIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "contentSecurityPolicyIssueDetails"]
      contentSecurityPolicyIssueDetails:
        option(ContentSecurityPolicyIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "sharedArrayBufferIssueDetails"]
      sharedArrayBufferIssueDetails: option(SharedArrayBufferIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "twaQualityEnforcementDetails"]
      twaQualityEnforcementDetails: option(TrustedWebActivityIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "lowTextContrastIssueDetails"]
      lowTextContrastIssueDetails: option(LowTextContrastIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "corsIssueDetails"]
      corsIssueDetails: option(CorsIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "attributionReportingIssueDetails"]
      attributionReportingIssueDetails:
        option(AttributionReportingIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "quirksModeIssueDetails"]
      quirksModeIssueDetails: option(QuirksModeIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "navigatorUserAgentIssueDetails"]
      navigatorUserAgentIssueDetails:
        option(NavigatorUserAgentIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "wasmCrossOriginModuleSharingIssue"]
      wasmCrossOriginModuleSharingIssue:
        option(WasmCrossOriginModuleSharingIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "genericIssueDetails"]
      genericIssueDetails: option(GenericIssueDetails.t), /* No description provided */
      [@yojson.option] [@key "deprecationIssueDetails"]
      deprecationIssueDetails: option(DeprecationIssueDetails.t) /* No description provided */,
    };
  }
  and IssueId: {
    /* A unique id for a DevTools inspector issue. Allows other entities (e.g.
       exceptions, CDP message, console messages, etc.) to reference an issue. */
    [@deriving yojson]
    type t = string;
  } = {
    /* A unique id for a DevTools inspector issue. Allows other entities (e.g.
       exceptions, CDP message, console messages, etc.) to reference an issue. */
    [@deriving yojson]
    type t = string;
  }
  and InspectorIssue: {
    /* An inspector issue reported from the back-end. */
    [@deriving yojson]
    type t = {
      [@key "code"]
      code: InspectorIssueCode.t, /* No description provided */
      [@key "details"]
      details: InspectorIssueDetails.t, /* No description provided */
      [@yojson.option] [@key "issueId"]
      issueId: option(IssueId.t) /* A unique id for this issue. May be omitted if no other entity (e.g.
exception, CDP message, etc.) is referencing this issue. */,
    };
  } = {
    /* An inspector issue reported from the back-end. */
    [@deriving yojson]
    type t = {
      [@key "code"]
      code: InspectorIssueCode.t, /* No description provided */
      [@key "details"]
      details: InspectorIssueDetails.t, /* No description provided */
      [@yojson.option] [@key "issueId"]
      issueId: option(IssueId.t) /* A unique id for this issue. May be omitted if no other entity (e.g.
exception, CDP message, etc.) is referencing this issue. */,
    };
  };
}
and BackgroundService: {
  module rec ServiceName: {
    type _servicename = [
      | `backgroundFetch
      | `backgroundSync
      | `pushMessaging
      | `notifications
      | `paymentHandler
      | `periodicBackgroundSync
    ];
    let _servicename_of_yojson: Yojson.Basic.t => _servicename;
    let yojson_of__servicename: _servicename => Yojson.Basic.t;
    /* The Background Service that will be associated with the commands/events.
       Every Background Service operates independently, but they share the same
       API. */
    [@deriving yojson]
    type t = _servicename;
  }
  and EventMetadata: {
    /* A key-value pair for additional event information to pass along. */
    [@deriving yojson]
    type t = {
      [@key "key"]
      key: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and BackgroundServiceEvent: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "timestamp"]
      timestamp: Network.TimeSinceEpoch.t, /* Timestamp of the event (in seconds). */
      [@key "origin"]
      origin: string, /* The origin this event belongs to. */
      [@key "serviceWorkerRegistrationId"]
      serviceWorkerRegistrationId: ServiceWorker.RegistrationID.t, /* The Service Worker ID that initiated the event. */
      [@key "service"]
      service: ServiceName.t, /* The Background Service this event belongs to. */
      [@key "eventName"]
      eventName: string, /* A description of the event. */
      [@key "instanceId"]
      instanceId: string, /* An identifier that groups related events together. */
      [@key "eventMetadata"]
      eventMetadata: list(EventMetadata.t) /* A list of event-specific information. */,
    };
  };
} = {
  module rec ServiceName: {
    type _servicename = [
      | `backgroundFetch
      | `backgroundSync
      | `pushMessaging
      | `notifications
      | `paymentHandler
      | `periodicBackgroundSync
    ];
    let _servicename_of_yojson: Yojson.Basic.t => _servicename;
    let yojson_of__servicename: _servicename => Yojson.Basic.t;
    /* The Background Service that will be associated with the commands/events.
       Every Background Service operates independently, but they share the same
       API. */
    [@deriving yojson]
    type t = _servicename;
  } = {
    type _servicename = [
      | `backgroundFetch
      | `backgroundSync
      | `pushMessaging
      | `notifications
      | `paymentHandler
      | `periodicBackgroundSync
    ];
    let _servicename_of_yojson =
      fun
      | `String("backgroundFetch") => `backgroundFetch
      | `String("backgroundSync") => `backgroundSync
      | `String("pushMessaging") => `pushMessaging
      | `String("notifications") => `notifications
      | `String("paymentHandler") => `paymentHandler
      | `String("periodicBackgroundSync") => `periodicBackgroundSync
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__servicename =
      fun
      | `backgroundFetch => `String("backgroundFetch")
      | `backgroundSync => `String("backgroundSync")
      | `pushMessaging => `String("pushMessaging")
      | `notifications => `String("notifications")
      | `paymentHandler => `String("paymentHandler")
      | `periodicBackgroundSync => `String("periodicBackgroundSync");
    /* The Background Service that will be associated with the commands/events.
       Every Background Service operates independently, but they share the same
       API. */
    [@deriving yojson]
    type t = _servicename;
  }
  and EventMetadata: {
    /* A key-value pair for additional event information to pass along. */
    [@deriving yojson]
    type t = {
      [@key "key"]
      key: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  } = {
    /* A key-value pair for additional event information to pass along. */
    [@deriving yojson]
    type t = {
      [@key "key"]
      key: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and BackgroundServiceEvent: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "timestamp"]
      timestamp: Network.TimeSinceEpoch.t, /* Timestamp of the event (in seconds). */
      [@key "origin"]
      origin: string, /* The origin this event belongs to. */
      [@key "serviceWorkerRegistrationId"]
      serviceWorkerRegistrationId: ServiceWorker.RegistrationID.t, /* The Service Worker ID that initiated the event. */
      [@key "service"]
      service: ServiceName.t, /* The Background Service this event belongs to. */
      [@key "eventName"]
      eventName: string, /* A description of the event. */
      [@key "instanceId"]
      instanceId: string, /* An identifier that groups related events together. */
      [@key "eventMetadata"]
      eventMetadata: list(EventMetadata.t) /* A list of event-specific information. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "timestamp"]
      timestamp: Network.TimeSinceEpoch.t, /* Timestamp of the event (in seconds). */
      [@key "origin"]
      origin: string, /* The origin this event belongs to. */
      [@key "serviceWorkerRegistrationId"]
      serviceWorkerRegistrationId: ServiceWorker.RegistrationID.t, /* The Service Worker ID that initiated the event. */
      [@key "service"]
      service: ServiceName.t, /* The Background Service this event belongs to. */
      [@key "eventName"]
      eventName: string, /* A description of the event. */
      [@key "instanceId"]
      instanceId: string, /* An identifier that groups related events together. */
      [@key "eventMetadata"]
      eventMetadata: list(EventMetadata.t) /* A list of event-specific information. */,
    };
  };
}
and Browser: {
  module rec BrowserContextID: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and WindowID: {
    /* No description provided */
    [@deriving yojson]
    type t = float;
  }
  and WindowState: {
    type _windowstate = [ | `normal | `minimized | `maximized | `fullscreen];
    let _windowstate_of_yojson: Yojson.Basic.t => _windowstate;
    let yojson_of__windowstate: _windowstate => Yojson.Basic.t;
    /* The state of the browser window. */
    [@deriving yojson]
    type t = _windowstate;
  }
  and Bounds: {
    /* Browser window bounds information */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "left"]
      left: option(float), /* The offset from the left edge of the screen to the window in pixels. */
      [@yojson.option] [@key "top"]
      top: option(float), /* The offset from the top edge of the screen to the window in pixels. */
      [@yojson.option] [@key "width"]
      width: option(float), /* The window width in pixels. */
      [@yojson.option] [@key "height"]
      height: option(float), /* The window height in pixels. */
      [@yojson.option] [@key "windowState"]
      windowState: option(WindowState.t) /* The window state. Default to normal. */,
    };
  }
  and PermissionType: {
    type _permissiontype = [
      | `accessibilityEvents
      | `audioCapture
      | `backgroundSync
      | `backgroundFetch
      | `clipboardReadWrite
      | `clipboardSanitizedWrite
      | `displayCapture
      | `durableStorage
      | `flash
      | `geolocation
      | `midi
      | `midiSysex
      | `nfc
      | `notifications
      | `paymentHandler
      | `periodicBackgroundSync
      | `protectedMediaIdentifier
      | `sensors
      | `videoCapture
      | `videoCapturePanTiltZoom
      | `idleDetection
      | `wakeLockScreen
      | `wakeLockSystem
    ];
    let _permissiontype_of_yojson: Yojson.Basic.t => _permissiontype;
    let yojson_of__permissiontype: _permissiontype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _permissiontype;
  }
  and PermissionSetting: {
    type _permissionsetting = [ | `granted | `denied | `prompt];
    let _permissionsetting_of_yojson: Yojson.Basic.t => _permissionsetting;
    let yojson_of__permissionsetting: _permissionsetting => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _permissionsetting;
  }
  and PermissionDescriptor: {
    /* Definition of PermissionDescriptor defined in the Permissions API:
       https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
      [@yojson.option] [@key "sysex"]
      sysex: option(bool), /* For "midi" permission, may also specify sysex control. */
      [@yojson.option] [@key "userVisibleOnly"]
      userVisibleOnly: option(bool), /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
      [@yojson.option] [@key "allowWithoutSanitization"]
      allowWithoutSanitization: option(bool), /* For "clipboard" permission, may specify allowWithoutSanitization. */
      [@yojson.option] [@key "panTiltZoom"]
      panTiltZoom: option(bool) /* For "camera" permission, may specify panTiltZoom. */,
    };
  }
  and BrowserCommandId: {
    type _browsercommandid = [ | `openTabSearch | `closeTabSearch];
    let _browsercommandid_of_yojson: Yojson.Basic.t => _browsercommandid;
    let yojson_of__browsercommandid: _browsercommandid => Yojson.Basic.t;
    /* Browser command ids used by executeBrowserCommand. */
    [@deriving yojson]
    type t = _browsercommandid;
  }
  and Bucket: {
    /* Chrome histogram bucket. */
    [@deriving yojson]
    type t = {
      [@key "low"]
      low: float, /* Minimum value (inclusive). */
      [@key "high"]
      high: float, /* Maximum value (exclusive). */
      [@key "count"]
      count: float /* Number of samples. */,
    };
  }
  and Histogram: {
    /* Chrome histogram. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name. */
      [@key "sum"]
      sum: float, /* Sum of sample values. */
      [@key "count"]
      count: float, /* Total number of samples. */
      [@key "buckets"]
      buckets: list(Bucket.t) /* Buckets. */,
    };
  };
} = {
  module rec BrowserContextID: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and WindowID: {
    /* No description provided */
    [@deriving yojson]
    type t = float;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = float;
  }
  and WindowState: {
    type _windowstate = [ | `normal | `minimized | `maximized | `fullscreen];
    let _windowstate_of_yojson: Yojson.Basic.t => _windowstate;
    let yojson_of__windowstate: _windowstate => Yojson.Basic.t;
    /* The state of the browser window. */
    [@deriving yojson]
    type t = _windowstate;
  } = {
    type _windowstate = [ | `normal | `minimized | `maximized | `fullscreen];
    let _windowstate_of_yojson =
      fun
      | `String("normal") => `normal
      | `String("minimized") => `minimized
      | `String("maximized") => `maximized
      | `String("fullscreen") => `fullscreen
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__windowstate =
      fun
      | `normal => `String("normal")
      | `minimized => `String("minimized")
      | `maximized => `String("maximized")
      | `fullscreen => `String("fullscreen");
    /* The state of the browser window. */
    [@deriving yojson]
    type t = _windowstate;
  }
  and Bounds: {
    /* Browser window bounds information */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "left"]
      left: option(float), /* The offset from the left edge of the screen to the window in pixels. */
      [@yojson.option] [@key "top"]
      top: option(float), /* The offset from the top edge of the screen to the window in pixels. */
      [@yojson.option] [@key "width"]
      width: option(float), /* The window width in pixels. */
      [@yojson.option] [@key "height"]
      height: option(float), /* The window height in pixels. */
      [@yojson.option] [@key "windowState"]
      windowState: option(WindowState.t) /* The window state. Default to normal. */,
    };
  } = {
    /* Browser window bounds information */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "left"]
      left: option(float), /* The offset from the left edge of the screen to the window in pixels. */
      [@yojson.option] [@key "top"]
      top: option(float), /* The offset from the top edge of the screen to the window in pixels. */
      [@yojson.option] [@key "width"]
      width: option(float), /* The window width in pixels. */
      [@yojson.option] [@key "height"]
      height: option(float), /* The window height in pixels. */
      [@yojson.option] [@key "windowState"]
      windowState: option(WindowState.t) /* The window state. Default to normal. */,
    };
  }
  and PermissionType: {
    type _permissiontype = [
      | `accessibilityEvents
      | `audioCapture
      | `backgroundSync
      | `backgroundFetch
      | `clipboardReadWrite
      | `clipboardSanitizedWrite
      | `displayCapture
      | `durableStorage
      | `flash
      | `geolocation
      | `midi
      | `midiSysex
      | `nfc
      | `notifications
      | `paymentHandler
      | `periodicBackgroundSync
      | `protectedMediaIdentifier
      | `sensors
      | `videoCapture
      | `videoCapturePanTiltZoom
      | `idleDetection
      | `wakeLockScreen
      | `wakeLockSystem
    ];
    let _permissiontype_of_yojson: Yojson.Basic.t => _permissiontype;
    let yojson_of__permissiontype: _permissiontype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _permissiontype;
  } = {
    type _permissiontype = [
      | `accessibilityEvents
      | `audioCapture
      | `backgroundSync
      | `backgroundFetch
      | `clipboardReadWrite
      | `clipboardSanitizedWrite
      | `displayCapture
      | `durableStorage
      | `flash
      | `geolocation
      | `midi
      | `midiSysex
      | `nfc
      | `notifications
      | `paymentHandler
      | `periodicBackgroundSync
      | `protectedMediaIdentifier
      | `sensors
      | `videoCapture
      | `videoCapturePanTiltZoom
      | `idleDetection
      | `wakeLockScreen
      | `wakeLockSystem
    ];
    let _permissiontype_of_yojson =
      fun
      | `String("accessibilityEvents") => `accessibilityEvents
      | `String("audioCapture") => `audioCapture
      | `String("backgroundSync") => `backgroundSync
      | `String("backgroundFetch") => `backgroundFetch
      | `String("clipboardReadWrite") => `clipboardReadWrite
      | `String("clipboardSanitizedWrite") => `clipboardSanitizedWrite
      | `String("displayCapture") => `displayCapture
      | `String("durableStorage") => `durableStorage
      | `String("flash") => `flash
      | `String("geolocation") => `geolocation
      | `String("midi") => `midi
      | `String("midiSysex") => `midiSysex
      | `String("nfc") => `nfc
      | `String("notifications") => `notifications
      | `String("paymentHandler") => `paymentHandler
      | `String("periodicBackgroundSync") => `periodicBackgroundSync
      | `String("protectedMediaIdentifier") => `protectedMediaIdentifier
      | `String("sensors") => `sensors
      | `String("videoCapture") => `videoCapture
      | `String("videoCapturePanTiltZoom") => `videoCapturePanTiltZoom
      | `String("idleDetection") => `idleDetection
      | `String("wakeLockScreen") => `wakeLockScreen
      | `String("wakeLockSystem") => `wakeLockSystem
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__permissiontype =
      fun
      | `accessibilityEvents => `String("accessibilityEvents")
      | `audioCapture => `String("audioCapture")
      | `backgroundSync => `String("backgroundSync")
      | `backgroundFetch => `String("backgroundFetch")
      | `clipboardReadWrite => `String("clipboardReadWrite")
      | `clipboardSanitizedWrite => `String("clipboardSanitizedWrite")
      | `displayCapture => `String("displayCapture")
      | `durableStorage => `String("durableStorage")
      | `flash => `String("flash")
      | `geolocation => `String("geolocation")
      | `midi => `String("midi")
      | `midiSysex => `String("midiSysex")
      | `nfc => `String("nfc")
      | `notifications => `String("notifications")
      | `paymentHandler => `String("paymentHandler")
      | `periodicBackgroundSync => `String("periodicBackgroundSync")
      | `protectedMediaIdentifier => `String("protectedMediaIdentifier")
      | `sensors => `String("sensors")
      | `videoCapture => `String("videoCapture")
      | `videoCapturePanTiltZoom => `String("videoCapturePanTiltZoom")
      | `idleDetection => `String("idleDetection")
      | `wakeLockScreen => `String("wakeLockScreen")
      | `wakeLockSystem => `String("wakeLockSystem");
    /* No description provided */
    [@deriving yojson]
    type t = _permissiontype;
  }
  and PermissionSetting: {
    type _permissionsetting = [ | `granted | `denied | `prompt];
    let _permissionsetting_of_yojson: Yojson.Basic.t => _permissionsetting;
    let yojson_of__permissionsetting: _permissionsetting => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _permissionsetting;
  } = {
    type _permissionsetting = [ | `granted | `denied | `prompt];
    let _permissionsetting_of_yojson =
      fun
      | `String("granted") => `granted
      | `String("denied") => `denied
      | `String("prompt") => `prompt
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__permissionsetting =
      fun
      | `granted => `String("granted")
      | `denied => `String("denied")
      | `prompt => `String("prompt");
    /* No description provided */
    [@deriving yojson]
    type t = _permissionsetting;
  }
  and PermissionDescriptor: {
    /* Definition of PermissionDescriptor defined in the Permissions API:
       https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
      [@yojson.option] [@key "sysex"]
      sysex: option(bool), /* For "midi" permission, may also specify sysex control. */
      [@yojson.option] [@key "userVisibleOnly"]
      userVisibleOnly: option(bool), /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
      [@yojson.option] [@key "allowWithoutSanitization"]
      allowWithoutSanitization: option(bool), /* For "clipboard" permission, may specify allowWithoutSanitization. */
      [@yojson.option] [@key "panTiltZoom"]
      panTiltZoom: option(bool) /* For "camera" permission, may specify panTiltZoom. */,
    };
  } = {
    /* Definition of PermissionDescriptor defined in the Permissions API:
       https://w3c.github.io/permissions/#dictdef-permissiondescriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name of permission.
See https://cs.chromium.org/chromium/src/third_party/blink/renderer/modules/permissions/permission_descriptor.idl for valid permission names. */
      [@yojson.option] [@key "sysex"]
      sysex: option(bool), /* For "midi" permission, may also specify sysex control. */
      [@yojson.option] [@key "userVisibleOnly"]
      userVisibleOnly: option(bool), /* For "push" permission, may specify userVisibleOnly.
Note that userVisibleOnly = true is the only currently supported type. */
      [@yojson.option] [@key "allowWithoutSanitization"]
      allowWithoutSanitization: option(bool), /* For "clipboard" permission, may specify allowWithoutSanitization. */
      [@yojson.option] [@key "panTiltZoom"]
      panTiltZoom: option(bool) /* For "camera" permission, may specify panTiltZoom. */,
    };
  }
  and BrowserCommandId: {
    type _browsercommandid = [ | `openTabSearch | `closeTabSearch];
    let _browsercommandid_of_yojson: Yojson.Basic.t => _browsercommandid;
    let yojson_of__browsercommandid: _browsercommandid => Yojson.Basic.t;
    /* Browser command ids used by executeBrowserCommand. */
    [@deriving yojson]
    type t = _browsercommandid;
  } = {
    type _browsercommandid = [ | `openTabSearch | `closeTabSearch];
    let _browsercommandid_of_yojson =
      fun
      | `String("openTabSearch") => `openTabSearch
      | `String("closeTabSearch") => `closeTabSearch
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__browsercommandid =
      fun
      | `openTabSearch => `String("openTabSearch")
      | `closeTabSearch => `String("closeTabSearch");
    /* Browser command ids used by executeBrowserCommand. */
    [@deriving yojson]
    type t = _browsercommandid;
  }
  and Bucket: {
    /* Chrome histogram bucket. */
    [@deriving yojson]
    type t = {
      [@key "low"]
      low: float, /* Minimum value (inclusive). */
      [@key "high"]
      high: float, /* Maximum value (exclusive). */
      [@key "count"]
      count: float /* Number of samples. */,
    };
  } = {
    /* Chrome histogram bucket. */
    [@deriving yojson]
    type t = {
      [@key "low"]
      low: float, /* Minimum value (inclusive). */
      [@key "high"]
      high: float, /* Maximum value (exclusive). */
      [@key "count"]
      count: float /* Number of samples. */,
    };
  }
  and Histogram: {
    /* Chrome histogram. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name. */
      [@key "sum"]
      sum: float, /* Sum of sample values. */
      [@key "count"]
      count: float, /* Total number of samples. */
      [@key "buckets"]
      buckets: list(Bucket.t) /* Buckets. */,
    };
  } = {
    /* Chrome histogram. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name. */
      [@key "sum"]
      sum: float, /* Sum of sample values. */
      [@key "count"]
      count: float, /* Total number of samples. */
      [@key "buckets"]
      buckets: list(Bucket.t) /* Buckets. */,
    };
  };
}
and CSS: {
  module rec StyleSheetId: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and StyleSheetOrigin: {
    type _stylesheetorigin = [
      | `injected
      | `user_agent
      | `inspector
      | `regular
    ];
    let _stylesheetorigin_of_yojson: Yojson.Basic.t => _stylesheetorigin;
    let yojson_of__stylesheetorigin: _stylesheetorigin => Yojson.Basic.t;
    /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
       stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
       inspector" rules), "regular" for regular stylesheets. */
    [@deriving yojson]
    type t = _stylesheetorigin;
  }
  and PseudoElementMatches: {
    /* CSS rule collection for a single pseudo style. */
    [@deriving yojson]
    type t = {
      [@key "pseudoType"]
      pseudoType: DOM.PseudoType.t, /* Pseudo element type. */
      [@key "matches"]
      matches: list(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
    };
  }
  and InheritedStyleEntry: {
    /* Inherited CSS rule collection from ancestor node. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "inlineStyle"]
      inlineStyle: option(CSSStyle.t), /* The ancestor node's inline style, if any, in the style inheritance chain. */
      [@key "matchedCSSRules"]
      matchedCSSRules: list(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
    };
  }
  and RuleMatch: {
    /* Match data for a CSS rule. */
    [@deriving yojson]
    type t = {
      [@key "rule"]
      rule: CSSRule.t, /* CSS rule in the match. */
      [@key "matchingSelectors"]
      matchingSelectors: list(float) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
    };
  }
  and Value: {
    /* Data for a simple selector (these are delimited by commas in a selector list). */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Value text. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* Value range in the underlying resource (if available). */,
    };
  }
  and SelectorList: {
    /* Selector list data. */
    [@deriving yojson]
    type t = {
      [@key "selectors"]
      selectors: list(Value.t), /* Selectors in the list. */
      [@key "text"]
      text: string /* Rule selector text. */,
    };
  }
  and CSSStyleSheetHeader: {
    /* CSS stylesheet metainformation. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
      [@key "frameId"]
      frameId: Page.FrameId.t, /* Owner frame identifier. */
      [@key "sourceURL"]
      sourceURL: string, /* Stylesheet resource URL. Empty if this is a constructed stylesheet created using
new CSSStyleSheet() (but non-empty if this is a constructed sylesheet imported
as a CSS module script). */
      [@yojson.option] [@key "sourceMapURL"]
      sourceMapURL: option(string), /* URL of source map associated with the stylesheet (if any). */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Stylesheet origin. */
      [@key "title"]
      title: string, /* Stylesheet title. */
      [@yojson.option] [@key "ownerNode"]
      ownerNode: option(DOM.BackendNodeId.t), /* The backend id for the owner node of the stylesheet. */
      [@key "disabled"]
      disabled: bool, /* Denotes whether the stylesheet is disabled. */
      [@yojson.option] [@key "hasSourceURL"]
      hasSourceURL: option(bool), /* Whether the sourceURL field value comes from the sourceURL comment. */
      [@key "isInline"]
      isInline: bool, /* Whether this stylesheet is created for STYLE tag by parser. This flag is not set for
document.written STYLE tags. */
      [@key "isMutable"]
      isMutable: bool, /* Whether this stylesheet is mutable. Inline stylesheets become mutable
after they have been modified via CSSOM API.
<link> element's stylesheets become mutable only if DevTools modifies them.
Constructed stylesheets (new CSSStyleSheet()) are mutable immediately after creation. */
      [@key "isConstructed"]
      isConstructed: bool, /* True if this stylesheet is created through new CSSStyleSheet() or imported as a
CSS module script. */
      [@key "startLine"]
      startLine: float, /* Line offset of the stylesheet within the resource (zero based). */
      [@key "startColumn"]
      startColumn: float, /* Column offset of the stylesheet within the resource (zero based). */
      [@key "length"]
      length: float, /* Size of the content (in characters). */
      [@key "endLine"]
      endLine: float, /* Line offset of the end of the stylesheet within the resource (zero based). */
      [@key "endColumn"]
      endColumn: float /* Column offset of the end of the stylesheet within the resource (zero based). */,
    };
  }
  and CSSRule: {
    /* CSS rule representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "selectorList"]
      selectorList: SelectorList.t, /* Rule selector data. */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
      [@key "style"]
      style: CSSStyle.t, /* Associated style declaration. */
      [@yojson.option] [@key "media"]
      media: option(list(CSSMedia.t)), /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */
      [@yojson.option] [@key "containerQueries"]
      containerQueries: option(list(CSSContainerQuery.t)) /* Container query list array (for rules involving container queries).
The array enumerates container queries starting with the innermost one, going outwards. */,
    };
  }
  and RuleUsage: {
    /* CSS coverage information. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "startOffset"]
      startOffset: float, /* Offset of the start of the rule (including selector) from the beginning of the stylesheet. */
      [@key "endOffset"]
      endOffset: float, /* Offset of the end of the rule body from the beginning of the stylesheet. */
      [@key "used"]
      used: bool /* Indicates whether the rule was actually used by some element in the page. */,
    };
  }
  and SourceRange: {
    /* Text range within a resource. All numbers are zero-based. */
    [@deriving yojson]
    type t = {
      [@key "startLine"]
      startLine: float, /* Start line of range. */
      [@key "startColumn"]
      startColumn: float, /* Start column of range (inclusive). */
      [@key "endLine"]
      endLine: float, /* End line of range */
      [@key "endColumn"]
      endColumn: float /* End column of range (exclusive). */,
    };
  }
  and ShorthandEntry: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Shorthand name. */
      [@key "value"]
      value: string, /* Shorthand value. */
      [@yojson.option] [@key "important"]
      important: option(bool) /* Whether the property has "!important" annotation (implies `false` if absent). */,
    };
  }
  and CSSComputedStyleProperty: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Computed style property name. */
      [@key "value"]
      value: string /* Computed style property value. */,
    };
  }
  and CSSStyle: {
    /* CSS style representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "cssProperties"]
      cssProperties: list(CSSProperty.t), /* CSS properties in the style. */
      [@key "shorthandEntries"]
      shorthandEntries: list(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
      [@yojson.option] [@key "cssText"]
      cssText: option(string), /* Style declaration text (if available). */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* Style declaration range in the enclosing stylesheet (if available). */,
    };
  }
  and CSSProperty: {
    /* CSS property declaration data. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* The property name. */
      [@key "value"]
      value: string, /* The property value. */
      [@yojson.option] [@key "important"]
      important: option(bool), /* Whether the property has "!important" annotation (implies `false` if absent). */
      [@yojson.option] [@key "implicit"]
      implicit: option(bool), /* Whether the property is implicit (implies `false` if absent). */
      [@yojson.option] [@key "text"]
      text: option(string), /* The full property text as specified in the style. */
      [@yojson.option] [@key "parsedOk"]
      parsedOk: option(bool), /* Whether the property is understood by the browser (implies `true` if absent). */
      [@yojson.option] [@key "disabled"]
      disabled: option(bool), /* Whether the property is disabled by the user (present for source-based properties only). */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* The entire property range in the enclosing style declaration (if available). */,
    };
  }
  and CSSMedia: {
    type _cssmedia_source = [
      | `mediaRule
      | `importRule
      | `linkedSheet
      | `inlineSheet
    ];
    let _cssmedia_source_of_yojson: Yojson.Basic.t => _cssmedia_source;
    let yojson_of__cssmedia_source: _cssmedia_source => Yojson.Basic.t;
    /* CSS media rule descriptor. */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Media query text. */
      [@key "source"]
      source: _cssmedia_source, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
      [@yojson.option] [@key "sourceURL"]
      sourceURL: option(string), /* URL of the document containing the media query description. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t), /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
      [@yojson.option] [@key "mediaList"]
      mediaList: option(list(MediaQuery.t)) /* Array of media queries. */,
    };
  }
  and MediaQuery: {
    /* Media query descriptor. */
    [@deriving yojson]
    type t = {
      [@key "expressions"]
      expressions: list(MediaQueryExpression.t), /* Array of media query expressions. */
      [@key "active"]
      active: bool /* Whether the media query condition is satisfied. */,
    };
  }
  and MediaQueryExpression: {
    /* Media query expression descriptor. */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: float, /* Media query expression value. */
      [@key "unit"]
      unit: string, /* Media query expression units. */
      [@key "feature"]
      feature: string, /* Media query expression feature. */
      [@yojson.option] [@key "valueRange"]
      valueRange: option(SourceRange.t), /* The associated range of the value text in the enclosing stylesheet (if available). */
      [@yojson.option] [@key "computedLength"]
      computedLength: option(float) /* Computed length of media query expression (if applicable). */,
    };
  }
  and CSSContainerQuery: {
    /* CSS container query rule descriptor. */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Container query text. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t), /* The associated rule header range in the enclosing stylesheet (if
available). */
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
      [@yojson.option] [@key "name"]
      name: option(string) /* Optional name for the container. */,
    };
  }
  and PlatformFontUsage: {
    /* Information about amount of glyphs that were rendered with given font. */
    [@deriving yojson]
    type t = {
      [@key "familyName"]
      familyName: string, /* Font's family name reported by platform. */
      [@key "isCustomFont"]
      isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
      [@key "glyphCount"]
      glyphCount: float /* Amount of glyphs that were rendered with this font. */,
    };
  }
  and FontVariationAxis: {
    /* Information about font variation axes for variable fonts */
    [@deriving yojson]
    type t = {
      [@key "tag"]
      tag: string, /* The font-variation-setting tag (a.k.a. "axis tag"). */
      [@key "name"]
      name: string, /* Human-readable variation name in the default language (normally, "en"). */
      [@key "minValue"]
      minValue: float, /* The minimum value (inclusive) the font supports for this tag. */
      [@key "maxValue"]
      maxValue: float, /* The maximum value (inclusive) the font supports for this tag. */
      [@key "defaultValue"]
      defaultValue: float /* The default value. */,
    };
  }
  and FontFace: {
    /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
       and additional information such as platformFontFamily and fontVariationAxes. */
    [@deriving yojson]
    type t = {
      [@key "fontFamily"]
      fontFamily: string, /* The font-family. */
      [@key "fontStyle"]
      fontStyle: string, /* The font-style. */
      [@key "fontVariant"]
      fontVariant: string, /* The font-variant. */
      [@key "fontWeight"]
      fontWeight: string, /* The font-weight. */
      [@key "fontStretch"]
      fontStretch: string, /* The font-stretch. */
      [@key "unicodeRange"]
      unicodeRange: string, /* The unicode-range. */
      [@key "src"]
      src: string, /* The src. */
      [@key "platformFontFamily"]
      platformFontFamily: string, /* The resolved platform font family */
      [@yojson.option] [@key "fontVariationAxes"]
      fontVariationAxes: option(list(FontVariationAxis.t)) /* Available variation settings (a.k.a. "axes"). */,
    };
  }
  and CSSKeyframesRule: {
    /* CSS keyframes rule representation. */
    [@deriving yojson]
    type t = {
      [@key "animationName"]
      animationName: Value.t, /* Animation name. */
      [@key "keyframes"]
      keyframes: list(CSSKeyframeRule.t) /* List of keyframes. */,
    };
  }
  and CSSKeyframeRule: {
    /* CSS keyframe rule representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
      [@key "keyText"]
      keyText: Value.t, /* Associated key text. */
      [@key "style"]
      style: CSSStyle.t /* Associated style declaration. */,
    };
  }
  and StyleDeclarationEdit: {
    /* A descriptor of operation to mutate style declaration text. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
      [@key "range"]
      range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
      [@key "text"]
      text: string /* New style text. */,
    };
  };
} = {
  module rec StyleSheetId: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and StyleSheetOrigin: {
    type _stylesheetorigin = [
      | `injected
      | `user_agent
      | `inspector
      | `regular
    ];
    let _stylesheetorigin_of_yojson: Yojson.Basic.t => _stylesheetorigin;
    let yojson_of__stylesheetorigin: _stylesheetorigin => Yojson.Basic.t;
    /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
       stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
       inspector" rules), "regular" for regular stylesheets. */
    [@deriving yojson]
    type t = _stylesheetorigin;
  } = {
    type _stylesheetorigin = [
      | `injected
      | `user_agent
      | `inspector
      | `regular
    ];
    let _stylesheetorigin_of_yojson =
      fun
      | `String("injected") => `injected
      | `String("user-agent") => `user_agent
      | `String("inspector") => `inspector
      | `String("regular") => `regular
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__stylesheetorigin =
      fun
      | `injected => `String("injected")
      | `user_agent => `String("user-agent")
      | `inspector => `String("inspector")
      | `regular => `String("regular");
    /* Stylesheet type: "injected" for stylesheets injected via extension, "user-agent" for user-agent
       stylesheets, "inspector" for stylesheets created by the inspector (i.e. those holding the "via
       inspector" rules), "regular" for regular stylesheets. */
    [@deriving yojson]
    type t = _stylesheetorigin;
  }
  and PseudoElementMatches: {
    /* CSS rule collection for a single pseudo style. */
    [@deriving yojson]
    type t = {
      [@key "pseudoType"]
      pseudoType: DOM.PseudoType.t, /* Pseudo element type. */
      [@key "matches"]
      matches: list(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
    };
  } = {
    /* CSS rule collection for a single pseudo style. */
    [@deriving yojson]
    type t = {
      [@key "pseudoType"]
      pseudoType: DOM.PseudoType.t, /* Pseudo element type. */
      [@key "matches"]
      matches: list(RuleMatch.t) /* Matches of CSS rules applicable to the pseudo style. */,
    };
  }
  and InheritedStyleEntry: {
    /* Inherited CSS rule collection from ancestor node. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "inlineStyle"]
      inlineStyle: option(CSSStyle.t), /* The ancestor node's inline style, if any, in the style inheritance chain. */
      [@key "matchedCSSRules"]
      matchedCSSRules: list(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
    };
  } = {
    /* Inherited CSS rule collection from ancestor node. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "inlineStyle"]
      inlineStyle: option(CSSStyle.t), /* The ancestor node's inline style, if any, in the style inheritance chain. */
      [@key "matchedCSSRules"]
      matchedCSSRules: list(RuleMatch.t) /* Matches of CSS rules matching the ancestor node in the style inheritance chain. */,
    };
  }
  and RuleMatch: {
    /* Match data for a CSS rule. */
    [@deriving yojson]
    type t = {
      [@key "rule"]
      rule: CSSRule.t, /* CSS rule in the match. */
      [@key "matchingSelectors"]
      matchingSelectors: list(float) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
    };
  } = {
    /* Match data for a CSS rule. */
    [@deriving yojson]
    type t = {
      [@key "rule"]
      rule: CSSRule.t, /* CSS rule in the match. */
      [@key "matchingSelectors"]
      matchingSelectors: list(float) /* Matching selector indices in the rule's selectorList selectors (0-based). */,
    };
  }
  and Value: {
    /* Data for a simple selector (these are delimited by commas in a selector list). */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Value text. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* Value range in the underlying resource (if available). */,
    };
  } = {
    /* Data for a simple selector (these are delimited by commas in a selector list). */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Value text. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* Value range in the underlying resource (if available). */,
    };
  }
  and SelectorList: {
    /* Selector list data. */
    [@deriving yojson]
    type t = {
      [@key "selectors"]
      selectors: list(Value.t), /* Selectors in the list. */
      [@key "text"]
      text: string /* Rule selector text. */,
    };
  } = {
    /* Selector list data. */
    [@deriving yojson]
    type t = {
      [@key "selectors"]
      selectors: list(Value.t), /* Selectors in the list. */
      [@key "text"]
      text: string /* Rule selector text. */,
    };
  }
  and CSSStyleSheetHeader: {
    /* CSS stylesheet metainformation. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
      [@key "frameId"]
      frameId: Page.FrameId.t, /* Owner frame identifier. */
      [@key "sourceURL"]
      sourceURL: string, /* Stylesheet resource URL. Empty if this is a constructed stylesheet created using
new CSSStyleSheet() (but non-empty if this is a constructed sylesheet imported
as a CSS module script). */
      [@yojson.option] [@key "sourceMapURL"]
      sourceMapURL: option(string), /* URL of source map associated with the stylesheet (if any). */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Stylesheet origin. */
      [@key "title"]
      title: string, /* Stylesheet title. */
      [@yojson.option] [@key "ownerNode"]
      ownerNode: option(DOM.BackendNodeId.t), /* The backend id for the owner node of the stylesheet. */
      [@key "disabled"]
      disabled: bool, /* Denotes whether the stylesheet is disabled. */
      [@yojson.option] [@key "hasSourceURL"]
      hasSourceURL: option(bool), /* Whether the sourceURL field value comes from the sourceURL comment. */
      [@key "isInline"]
      isInline: bool, /* Whether this stylesheet is created for STYLE tag by parser. This flag is not set for
document.written STYLE tags. */
      [@key "isMutable"]
      isMutable: bool, /* Whether this stylesheet is mutable. Inline stylesheets become mutable
after they have been modified via CSSOM API.
<link> element's stylesheets become mutable only if DevTools modifies them.
Constructed stylesheets (new CSSStyleSheet()) are mutable immediately after creation. */
      [@key "isConstructed"]
      isConstructed: bool, /* True if this stylesheet is created through new CSSStyleSheet() or imported as a
CSS module script. */
      [@key "startLine"]
      startLine: float, /* Line offset of the stylesheet within the resource (zero based). */
      [@key "startColumn"]
      startColumn: float, /* Column offset of the stylesheet within the resource (zero based). */
      [@key "length"]
      length: float, /* Size of the content (in characters). */
      [@key "endLine"]
      endLine: float, /* Line offset of the end of the stylesheet within the resource (zero based). */
      [@key "endColumn"]
      endColumn: float /* Column offset of the end of the stylesheet within the resource (zero based). */,
    };
  } = {
    /* CSS stylesheet metainformation. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The stylesheet identifier. */
      [@key "frameId"]
      frameId: Page.FrameId.t, /* Owner frame identifier. */
      [@key "sourceURL"]
      sourceURL: string, /* Stylesheet resource URL. Empty if this is a constructed stylesheet created using
new CSSStyleSheet() (but non-empty if this is a constructed sylesheet imported
as a CSS module script). */
      [@yojson.option] [@key "sourceMapURL"]
      sourceMapURL: option(string), /* URL of source map associated with the stylesheet (if any). */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Stylesheet origin. */
      [@key "title"]
      title: string, /* Stylesheet title. */
      [@yojson.option] [@key "ownerNode"]
      ownerNode: option(DOM.BackendNodeId.t), /* The backend id for the owner node of the stylesheet. */
      [@key "disabled"]
      disabled: bool, /* Denotes whether the stylesheet is disabled. */
      [@yojson.option] [@key "hasSourceURL"]
      hasSourceURL: option(bool), /* Whether the sourceURL field value comes from the sourceURL comment. */
      [@key "isInline"]
      isInline: bool, /* Whether this stylesheet is created for STYLE tag by parser. This flag is not set for
document.written STYLE tags. */
      [@key "isMutable"]
      isMutable: bool, /* Whether this stylesheet is mutable. Inline stylesheets become mutable
after they have been modified via CSSOM API.
<link> element's stylesheets become mutable only if DevTools modifies them.
Constructed stylesheets (new CSSStyleSheet()) are mutable immediately after creation. */
      [@key "isConstructed"]
      isConstructed: bool, /* True if this stylesheet is created through new CSSStyleSheet() or imported as a
CSS module script. */
      [@key "startLine"]
      startLine: float, /* Line offset of the stylesheet within the resource (zero based). */
      [@key "startColumn"]
      startColumn: float, /* Column offset of the stylesheet within the resource (zero based). */
      [@key "length"]
      length: float, /* Size of the content (in characters). */
      [@key "endLine"]
      endLine: float, /* Line offset of the end of the stylesheet within the resource (zero based). */
      [@key "endColumn"]
      endColumn: float /* Column offset of the end of the stylesheet within the resource (zero based). */,
    };
  }
  and CSSRule: {
    /* CSS rule representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "selectorList"]
      selectorList: SelectorList.t, /* Rule selector data. */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
      [@key "style"]
      style: CSSStyle.t, /* Associated style declaration. */
      [@yojson.option] [@key "media"]
      media: option(list(CSSMedia.t)), /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */
      [@yojson.option] [@key "containerQueries"]
      containerQueries: option(list(CSSContainerQuery.t)) /* Container query list array (for rules involving container queries).
The array enumerates container queries starting with the innermost one, going outwards. */,
    };
  } = {
    /* CSS rule representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "selectorList"]
      selectorList: SelectorList.t, /* Rule selector data. */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
      [@key "style"]
      style: CSSStyle.t, /* Associated style declaration. */
      [@yojson.option] [@key "media"]
      media: option(list(CSSMedia.t)), /* Media list array (for rules involving media queries). The array enumerates media queries
starting with the innermost one, going outwards. */
      [@yojson.option] [@key "containerQueries"]
      containerQueries: option(list(CSSContainerQuery.t)) /* Container query list array (for rules involving container queries).
The array enumerates container queries starting with the innermost one, going outwards. */,
    };
  }
  and RuleUsage: {
    /* CSS coverage information. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "startOffset"]
      startOffset: float, /* Offset of the start of the rule (including selector) from the beginning of the stylesheet. */
      [@key "endOffset"]
      endOffset: float, /* Offset of the end of the rule body from the beginning of the stylesheet. */
      [@key "used"]
      used: bool /* Indicates whether the rule was actually used by some element in the page. */,
    };
  } = {
    /* CSS coverage information. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "startOffset"]
      startOffset: float, /* Offset of the start of the rule (including selector) from the beginning of the stylesheet. */
      [@key "endOffset"]
      endOffset: float, /* Offset of the end of the rule body from the beginning of the stylesheet. */
      [@key "used"]
      used: bool /* Indicates whether the rule was actually used by some element in the page. */,
    };
  }
  and SourceRange: {
    /* Text range within a resource. All numbers are zero-based. */
    [@deriving yojson]
    type t = {
      [@key "startLine"]
      startLine: float, /* Start line of range. */
      [@key "startColumn"]
      startColumn: float, /* Start column of range (inclusive). */
      [@key "endLine"]
      endLine: float, /* End line of range */
      [@key "endColumn"]
      endColumn: float /* End column of range (exclusive). */,
    };
  } = {
    /* Text range within a resource. All numbers are zero-based. */
    [@deriving yojson]
    type t = {
      [@key "startLine"]
      startLine: float, /* Start line of range. */
      [@key "startColumn"]
      startColumn: float, /* Start column of range (inclusive). */
      [@key "endLine"]
      endLine: float, /* End line of range */
      [@key "endColumn"]
      endColumn: float /* End column of range (exclusive). */,
    };
  }
  and ShorthandEntry: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Shorthand name. */
      [@key "value"]
      value: string, /* Shorthand value. */
      [@yojson.option] [@key "important"]
      important: option(bool) /* Whether the property has "!important" annotation (implies `false` if absent). */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Shorthand name. */
      [@key "value"]
      value: string, /* Shorthand value. */
      [@yojson.option] [@key "important"]
      important: option(bool) /* Whether the property has "!important" annotation (implies `false` if absent). */,
    };
  }
  and CSSComputedStyleProperty: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Computed style property name. */
      [@key "value"]
      value: string /* Computed style property value. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Computed style property name. */
      [@key "value"]
      value: string /* Computed style property value. */,
    };
  }
  and CSSStyle: {
    /* CSS style representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "cssProperties"]
      cssProperties: list(CSSProperty.t), /* CSS properties in the style. */
      [@key "shorthandEntries"]
      shorthandEntries: list(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
      [@yojson.option] [@key "cssText"]
      cssText: option(string), /* Style declaration text (if available). */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* Style declaration range in the enclosing stylesheet (if available). */,
    };
  } = {
    /* CSS style representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "cssProperties"]
      cssProperties: list(CSSProperty.t), /* CSS properties in the style. */
      [@key "shorthandEntries"]
      shorthandEntries: list(ShorthandEntry.t), /* Computed values for all shorthands found in the style. */
      [@yojson.option] [@key "cssText"]
      cssText: option(string), /* Style declaration text (if available). */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* Style declaration range in the enclosing stylesheet (if available). */,
    };
  }
  and CSSProperty: {
    /* CSS property declaration data. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* The property name. */
      [@key "value"]
      value: string, /* The property value. */
      [@yojson.option] [@key "important"]
      important: option(bool), /* Whether the property has "!important" annotation (implies `false` if absent). */
      [@yojson.option] [@key "implicit"]
      implicit: option(bool), /* Whether the property is implicit (implies `false` if absent). */
      [@yojson.option] [@key "text"]
      text: option(string), /* The full property text as specified in the style. */
      [@yojson.option] [@key "parsedOk"]
      parsedOk: option(bool), /* Whether the property is understood by the browser (implies `true` if absent). */
      [@yojson.option] [@key "disabled"]
      disabled: option(bool), /* Whether the property is disabled by the user (present for source-based properties only). */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* The entire property range in the enclosing style declaration (if available). */,
    };
  } = {
    /* CSS property declaration data. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* The property name. */
      [@key "value"]
      value: string, /* The property value. */
      [@yojson.option] [@key "important"]
      important: option(bool), /* Whether the property has "!important" annotation (implies `false` if absent). */
      [@yojson.option] [@key "implicit"]
      implicit: option(bool), /* Whether the property is implicit (implies `false` if absent). */
      [@yojson.option] [@key "text"]
      text: option(string), /* The full property text as specified in the style. */
      [@yojson.option] [@key "parsedOk"]
      parsedOk: option(bool), /* Whether the property is understood by the browser (implies `true` if absent). */
      [@yojson.option] [@key "disabled"]
      disabled: option(bool), /* Whether the property is disabled by the user (present for source-based properties only). */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t) /* The entire property range in the enclosing style declaration (if available). */,
    };
  }
  and CSSMedia: {
    type _cssmedia_source = [
      | `mediaRule
      | `importRule
      | `linkedSheet
      | `inlineSheet
    ];
    let _cssmedia_source_of_yojson: Yojson.Basic.t => _cssmedia_source;
    let yojson_of__cssmedia_source: _cssmedia_source => Yojson.Basic.t;
    /* CSS media rule descriptor. */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Media query text. */
      [@key "source"]
      source: _cssmedia_source, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
      [@yojson.option] [@key "sourceURL"]
      sourceURL: option(string), /* URL of the document containing the media query description. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t), /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
      [@yojson.option] [@key "mediaList"]
      mediaList: option(list(MediaQuery.t)) /* Array of media queries. */,
    };
  } = {
    type _cssmedia_source = [
      | `mediaRule
      | `importRule
      | `linkedSheet
      | `inlineSheet
    ];
    let _cssmedia_source_of_yojson =
      fun
      | `String("mediaRule") => `mediaRule
      | `String("importRule") => `importRule
      | `String("linkedSheet") => `linkedSheet
      | `String("inlineSheet") => `inlineSheet
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__cssmedia_source =
      fun
      | `mediaRule => `String("mediaRule")
      | `importRule => `String("importRule")
      | `linkedSheet => `String("linkedSheet")
      | `inlineSheet => `String("inlineSheet");
    /* CSS media rule descriptor. */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Media query text. */
      [@key "source"]
      source: _cssmedia_source, /* Source of the media query: "mediaRule" if specified by a @media rule, "importRule" if
specified by an @import rule, "linkedSheet" if specified by a "media" attribute in a linked
stylesheet's LINK tag, "inlineSheet" if specified by a "media" attribute in an inline
stylesheet's STYLE tag. */
      [@yojson.option] [@key "sourceURL"]
      sourceURL: option(string), /* URL of the document containing the media query description. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t), /* The associated rule (@media or @import) header range in the enclosing stylesheet (if
available). */
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
      [@yojson.option] [@key "mediaList"]
      mediaList: option(list(MediaQuery.t)) /* Array of media queries. */,
    };
  }
  and MediaQuery: {
    /* Media query descriptor. */
    [@deriving yojson]
    type t = {
      [@key "expressions"]
      expressions: list(MediaQueryExpression.t), /* Array of media query expressions. */
      [@key "active"]
      active: bool /* Whether the media query condition is satisfied. */,
    };
  } = {
    /* Media query descriptor. */
    [@deriving yojson]
    type t = {
      [@key "expressions"]
      expressions: list(MediaQueryExpression.t), /* Array of media query expressions. */
      [@key "active"]
      active: bool /* Whether the media query condition is satisfied. */,
    };
  }
  and MediaQueryExpression: {
    /* Media query expression descriptor. */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: float, /* Media query expression value. */
      [@key "unit"]
      unit: string, /* Media query expression units. */
      [@key "feature"]
      feature: string, /* Media query expression feature. */
      [@yojson.option] [@key "valueRange"]
      valueRange: option(SourceRange.t), /* The associated range of the value text in the enclosing stylesheet (if available). */
      [@yojson.option] [@key "computedLength"]
      computedLength: option(float) /* Computed length of media query expression (if applicable). */,
    };
  } = {
    /* Media query expression descriptor. */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: float, /* Media query expression value. */
      [@key "unit"]
      unit: string, /* Media query expression units. */
      [@key "feature"]
      feature: string, /* Media query expression feature. */
      [@yojson.option] [@key "valueRange"]
      valueRange: option(SourceRange.t), /* The associated range of the value text in the enclosing stylesheet (if available). */
      [@yojson.option] [@key "computedLength"]
      computedLength: option(float) /* Computed length of media query expression (if applicable). */,
    };
  }
  and CSSContainerQuery: {
    /* CSS container query rule descriptor. */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Container query text. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t), /* The associated rule header range in the enclosing stylesheet (if
available). */
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
      [@yojson.option] [@key "name"]
      name: option(string) /* Optional name for the container. */,
    };
  } = {
    /* CSS container query rule descriptor. */
    [@deriving yojson]
    type t = {
      [@key "text"]
      text: string, /* Container query text. */
      [@yojson.option] [@key "range"]
      range: option(SourceRange.t), /* The associated rule header range in the enclosing stylesheet (if
available). */
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* Identifier of the stylesheet containing this object (if exists). */
      [@yojson.option] [@key "name"]
      name: option(string) /* Optional name for the container. */,
    };
  }
  and PlatformFontUsage: {
    /* Information about amount of glyphs that were rendered with given font. */
    [@deriving yojson]
    type t = {
      [@key "familyName"]
      familyName: string, /* Font's family name reported by platform. */
      [@key "isCustomFont"]
      isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
      [@key "glyphCount"]
      glyphCount: float /* Amount of glyphs that were rendered with this font. */,
    };
  } = {
    /* Information about amount of glyphs that were rendered with given font. */
    [@deriving yojson]
    type t = {
      [@key "familyName"]
      familyName: string, /* Font's family name reported by platform. */
      [@key "isCustomFont"]
      isCustomFont: bool, /* Indicates if the font was downloaded or resolved locally. */
      [@key "glyphCount"]
      glyphCount: float /* Amount of glyphs that were rendered with this font. */,
    };
  }
  and FontVariationAxis: {
    /* Information about font variation axes for variable fonts */
    [@deriving yojson]
    type t = {
      [@key "tag"]
      tag: string, /* The font-variation-setting tag (a.k.a. "axis tag"). */
      [@key "name"]
      name: string, /* Human-readable variation name in the default language (normally, "en"). */
      [@key "minValue"]
      minValue: float, /* The minimum value (inclusive) the font supports for this tag. */
      [@key "maxValue"]
      maxValue: float, /* The maximum value (inclusive) the font supports for this tag. */
      [@key "defaultValue"]
      defaultValue: float /* The default value. */,
    };
  } = {
    /* Information about font variation axes for variable fonts */
    [@deriving yojson]
    type t = {
      [@key "tag"]
      tag: string, /* The font-variation-setting tag (a.k.a. "axis tag"). */
      [@key "name"]
      name: string, /* Human-readable variation name in the default language (normally, "en"). */
      [@key "minValue"]
      minValue: float, /* The minimum value (inclusive) the font supports for this tag. */
      [@key "maxValue"]
      maxValue: float, /* The maximum value (inclusive) the font supports for this tag. */
      [@key "defaultValue"]
      defaultValue: float /* The default value. */,
    };
  }
  and FontFace: {
    /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
       and additional information such as platformFontFamily and fontVariationAxes. */
    [@deriving yojson]
    type t = {
      [@key "fontFamily"]
      fontFamily: string, /* The font-family. */
      [@key "fontStyle"]
      fontStyle: string, /* The font-style. */
      [@key "fontVariant"]
      fontVariant: string, /* The font-variant. */
      [@key "fontWeight"]
      fontWeight: string, /* The font-weight. */
      [@key "fontStretch"]
      fontStretch: string, /* The font-stretch. */
      [@key "unicodeRange"]
      unicodeRange: string, /* The unicode-range. */
      [@key "src"]
      src: string, /* The src. */
      [@key "platformFontFamily"]
      platformFontFamily: string, /* The resolved platform font family */
      [@yojson.option] [@key "fontVariationAxes"]
      fontVariationAxes: option(list(FontVariationAxis.t)) /* Available variation settings (a.k.a. "axes"). */,
    };
  } = {
    /* Properties of a web font: https://www.w3.org/TR/2008/REC-CSS2-20080411/fonts.html#font-descriptions
       and additional information such as platformFontFamily and fontVariationAxes. */
    [@deriving yojson]
    type t = {
      [@key "fontFamily"]
      fontFamily: string, /* The font-family. */
      [@key "fontStyle"]
      fontStyle: string, /* The font-style. */
      [@key "fontVariant"]
      fontVariant: string, /* The font-variant. */
      [@key "fontWeight"]
      fontWeight: string, /* The font-weight. */
      [@key "fontStretch"]
      fontStretch: string, /* The font-stretch. */
      [@key "unicodeRange"]
      unicodeRange: string, /* The unicode-range. */
      [@key "src"]
      src: string, /* The src. */
      [@key "platformFontFamily"]
      platformFontFamily: string, /* The resolved platform font family */
      [@yojson.option] [@key "fontVariationAxes"]
      fontVariationAxes: option(list(FontVariationAxis.t)) /* Available variation settings (a.k.a. "axes"). */,
    };
  }
  and CSSKeyframesRule: {
    /* CSS keyframes rule representation. */
    [@deriving yojson]
    type t = {
      [@key "animationName"]
      animationName: Value.t, /* Animation name. */
      [@key "keyframes"]
      keyframes: list(CSSKeyframeRule.t) /* List of keyframes. */,
    };
  } = {
    /* CSS keyframes rule representation. */
    [@deriving yojson]
    type t = {
      [@key "animationName"]
      animationName: Value.t, /* Animation name. */
      [@key "keyframes"]
      keyframes: list(CSSKeyframeRule.t) /* List of keyframes. */,
    };
  }
  and CSSKeyframeRule: {
    /* CSS keyframe rule representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
      [@key "keyText"]
      keyText: Value.t, /* Associated key text. */
      [@key "style"]
      style: CSSStyle.t /* Associated style declaration. */,
    };
  } = {
    /* CSS keyframe rule representation. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "styleSheetId"]
      styleSheetId: option(StyleSheetId.t), /* The css style sheet identifier (absent for user agent stylesheet and user-specified
stylesheet rules) this rule came from. */
      [@key "origin"]
      origin: StyleSheetOrigin.t, /* Parent stylesheet's origin. */
      [@key "keyText"]
      keyText: Value.t, /* Associated key text. */
      [@key "style"]
      style: CSSStyle.t /* Associated style declaration. */,
    };
  }
  and StyleDeclarationEdit: {
    /* A descriptor of operation to mutate style declaration text. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
      [@key "range"]
      range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
      [@key "text"]
      text: string /* New style text. */,
    };
  } = {
    /* A descriptor of operation to mutate style declaration text. */
    [@deriving yojson]
    type t = {
      [@key "styleSheetId"]
      styleSheetId: StyleSheetId.t, /* The css style sheet identifier. */
      [@key "range"]
      range: SourceRange.t, /* The range of the style text in the enclosing stylesheet. */
      [@key "text"]
      text: string /* New style text. */,
    };
  };
}
and CacheStorage: {
  module rec CacheId: {
    /* Unique identifier of the Cache object. */
    [@deriving yojson]
    type t = string;
  }
  and CachedResponseType: {
    type _cachedresponsetype = [
      | `basic
      | `cors
      | `default
      | `error
      | `opaqueResponse
      | `opaqueRedirect
    ];
    let _cachedresponsetype_of_yojson: Yojson.Basic.t => _cachedresponsetype;
    let yojson_of__cachedresponsetype: _cachedresponsetype => Yojson.Basic.t;
    /* type of HTTP response cached */
    [@deriving yojson]
    type t = _cachedresponsetype;
  }
  and DataEntry: {
    /* Data entry. */
    [@deriving yojson]
    type t = {
      [@key "requestURL"]
      requestURL: string, /* Request URL. */
      [@key "requestMethod"]
      requestMethod: string, /* Request method. */
      [@key "requestHeaders"]
      requestHeaders: list(Header.t), /* Request headers */
      [@key "responseTime"]
      responseTime: float, /* Number of seconds since epoch. */
      [@key "responseStatus"]
      responseStatus: float, /* HTTP response status code. */
      [@key "responseStatusText"]
      responseStatusText: string, /* HTTP response status text. */
      [@key "responseType"]
      responseType: CachedResponseType.t, /* HTTP response type */
      [@key "responseHeaders"]
      responseHeaders: list(Header.t) /* Response headers */,
    };
  }
  and Cache: {
    /* Cache identifier. */
    [@deriving yojson]
    type t = {
      [@key "cacheId"]
      cacheId: CacheId.t, /* An opaque unique id of the cache. */
      [@key "securityOrigin"]
      securityOrigin: string, /* Security origin of the cache. */
      [@key "cacheName"]
      cacheName: string /* The name of the cache. */,
    };
  }
  and Header: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and CachedResponse: {
    /* Cached response */
    [@deriving yojson]
    type t = {
      [@key "body"]
      body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
    };
  };
} = {
  module rec CacheId: {
    /* Unique identifier of the Cache object. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique identifier of the Cache object. */
    [@deriving yojson]
    type t = string;
  }
  and CachedResponseType: {
    type _cachedresponsetype = [
      | `basic
      | `cors
      | `default
      | `error
      | `opaqueResponse
      | `opaqueRedirect
    ];
    let _cachedresponsetype_of_yojson: Yojson.Basic.t => _cachedresponsetype;
    let yojson_of__cachedresponsetype: _cachedresponsetype => Yojson.Basic.t;
    /* type of HTTP response cached */
    [@deriving yojson]
    type t = _cachedresponsetype;
  } = {
    type _cachedresponsetype = [
      | `basic
      | `cors
      | `default
      | `error
      | `opaqueResponse
      | `opaqueRedirect
    ];
    let _cachedresponsetype_of_yojson =
      fun
      | `String("basic") => `basic
      | `String("cors") => `cors
      | `String("default") => `default
      | `String("error") => `error
      | `String("opaqueResponse") => `opaqueResponse
      | `String("opaqueRedirect") => `opaqueRedirect
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__cachedresponsetype =
      fun
      | `basic => `String("basic")
      | `cors => `String("cors")
      | `default => `String("default")
      | `error => `String("error")
      | `opaqueResponse => `String("opaqueResponse")
      | `opaqueRedirect => `String("opaqueRedirect");
    /* type of HTTP response cached */
    [@deriving yojson]
    type t = _cachedresponsetype;
  }
  and DataEntry: {
    /* Data entry. */
    [@deriving yojson]
    type t = {
      [@key "requestURL"]
      requestURL: string, /* Request URL. */
      [@key "requestMethod"]
      requestMethod: string, /* Request method. */
      [@key "requestHeaders"]
      requestHeaders: list(Header.t), /* Request headers */
      [@key "responseTime"]
      responseTime: float, /* Number of seconds since epoch. */
      [@key "responseStatus"]
      responseStatus: float, /* HTTP response status code. */
      [@key "responseStatusText"]
      responseStatusText: string, /* HTTP response status text. */
      [@key "responseType"]
      responseType: CachedResponseType.t, /* HTTP response type */
      [@key "responseHeaders"]
      responseHeaders: list(Header.t) /* Response headers */,
    };
  } = {
    /* Data entry. */
    [@deriving yojson]
    type t = {
      [@key "requestURL"]
      requestURL: string, /* Request URL. */
      [@key "requestMethod"]
      requestMethod: string, /* Request method. */
      [@key "requestHeaders"]
      requestHeaders: list(Header.t), /* Request headers */
      [@key "responseTime"]
      responseTime: float, /* Number of seconds since epoch. */
      [@key "responseStatus"]
      responseStatus: float, /* HTTP response status code. */
      [@key "responseStatusText"]
      responseStatusText: string, /* HTTP response status text. */
      [@key "responseType"]
      responseType: CachedResponseType.t, /* HTTP response type */
      [@key "responseHeaders"]
      responseHeaders: list(Header.t) /* Response headers */,
    };
  }
  and Cache: {
    /* Cache identifier. */
    [@deriving yojson]
    type t = {
      [@key "cacheId"]
      cacheId: CacheId.t, /* An opaque unique id of the cache. */
      [@key "securityOrigin"]
      securityOrigin: string, /* Security origin of the cache. */
      [@key "cacheName"]
      cacheName: string /* The name of the cache. */,
    };
  } = {
    /* Cache identifier. */
    [@deriving yojson]
    type t = {
      [@key "cacheId"]
      cacheId: CacheId.t, /* An opaque unique id of the cache. */
      [@key "securityOrigin"]
      securityOrigin: string, /* Security origin of the cache. */
      [@key "cacheName"]
      cacheName: string /* The name of the cache. */,
    };
  }
  and Header: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and CachedResponse: {
    /* Cached response */
    [@deriving yojson]
    type t = {
      [@key "body"]
      body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
    };
  } = {
    /* Cached response */
    [@deriving yojson]
    type t = {
      [@key "body"]
      body: string /* Entry content, base64-encoded. (Encoded as a base64 string when passed over JSON) */,
    };
  };
}
and Cast: {
  module rec Sink: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "id"]
      id: string, /* No description provided */
      [@yojson.option] [@key "session"]
      session: option(string) /* Text describing the current session. Present only if there is an active
session on the sink. */,
    };
  };
} = {
  module rec Sink: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "id"]
      id: string, /* No description provided */
      [@yojson.option] [@key "session"]
      session: option(string) /* Text describing the current session. Present only if there is an active
session on the sink. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "id"]
      id: string, /* No description provided */
      [@yojson.option] [@key "session"]
      session: option(string) /* Text describing the current session. Present only if there is an active
session on the sink. */,
    };
  };
}
and DOM: {
  module rec NodeId: {
    /* Unique DOM node identifier. */
    [@deriving yojson]
    type t = float;
  }
  and BackendNodeId: {
    /* Unique DOM node identifier used to reference a node that may not have been pushed to the
       front-end. */
    [@deriving yojson]
    type t = float;
  }
  and BackendNode: {
    /* Backend node with a friendly name. */
    [@deriving yojson]
    type t = {
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "backendNodeId"]
      backendNodeId: BackendNodeId.t /* No description provided */,
    };
  }
  and PseudoType: {
    type _pseudotype = [
      | `first_line
      | `first_letter
      | `before
      | `after
      | `marker
      | `backdrop
      | `selection
      | `target_text
      | `spelling_error
      | `grammar_error
      | `highlight
      | `first_line_inherited
      | `scrollbar
      | `scrollbar_thumb
      | `scrollbar_button
      | `scrollbar_track
      | `scrollbar_track_piece
      | `scrollbar_corner
      | `resizer
      | `input_list_button
    ];
    let _pseudotype_of_yojson: Yojson.Basic.t => _pseudotype;
    let yojson_of__pseudotype: _pseudotype => Yojson.Basic.t;
    /* Pseudo element type. */
    [@deriving yojson]
    type t = _pseudotype;
  }
  and ShadowRootType: {
    type _shadowroottype = [ | `user_agent | `open_ | `closed];
    let _shadowroottype_of_yojson: Yojson.Basic.t => _shadowroottype;
    let yojson_of__shadowroottype: _shadowroottype => Yojson.Basic.t;
    /* Shadow root type. */
    [@deriving yojson]
    type t = _shadowroottype;
  }
  and CompatibilityMode: {
    type _compatibilitymode = [
      | `QuirksMode
      | `LimitedQuirksMode
      | `NoQuirksMode
    ];
    let _compatibilitymode_of_yojson: Yojson.Basic.t => _compatibilitymode;
    let yojson_of__compatibilitymode: _compatibilitymode => Yojson.Basic.t;
    /* Document compatibility mode. */
    [@deriving yojson]
    type t = _compatibilitymode;
  }
  and Node: {
    /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
       DOMNode is a base node mirror type. */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
      [@yojson.option] [@key "parentId"]
      parentId: option(NodeId.t), /* The id of the parent node if any. */
      [@key "backendNodeId"]
      backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "localName"]
      localName: string, /* `Node`'s localName. */
      [@key "nodeValue"]
      nodeValue: string, /* `Node`'s nodeValue. */
      [@yojson.option] [@key "childNodeCount"]
      childNodeCount: option(float), /* Child count for `Container` nodes. */
      [@yojson.option] [@key "children"]
      children: option(list(Node.t)), /* Child nodes of this node when requested with children. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(string)), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
      [@yojson.option] [@key "documentURL"]
      documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@yojson.option] [@key "publicId"]
      publicId: option(string), /* `DocumentType`'s publicId. */
      [@yojson.option] [@key "systemId"]
      systemId: option(string), /* `DocumentType`'s systemId. */
      [@yojson.option] [@key "internalSubset"]
      internalSubset: option(string), /* `DocumentType`'s internalSubset. */
      [@yojson.option] [@key "xmlVersion"]
      xmlVersion: option(string), /* `Document`'s XML version in case of XML documents. */
      [@yojson.option] [@key "name"]
      name: option(string), /* `Attr`'s name. */
      [@yojson.option] [@key "value"]
      value: option(string), /* `Attr`'s value. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(PseudoType.t), /* Pseudo element type for this node. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(ShadowRootType.t), /* Shadow root type. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t), /* Frame ID for frame owner elements. */
      [@yojson.option] [@key "contentDocument"]
      contentDocument: option(Node.t), /* Content document for frame owner elements. */
      [@yojson.option] [@key "shadowRoots"]
      shadowRoots: option(list(Node.t)), /* Shadow root list for given element host. */
      [@yojson.option] [@key "templateContent"]
      templateContent: option(Node.t), /* Content document fragment for template elements. */
      [@yojson.option] [@key "pseudoElements"]
      pseudoElements: option(list(Node.t)), /* Pseudo elements associated with this node. */
      [@yojson.option] [@key "importedDocument"]
      importedDocument: option(Node.t), /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
      [@yojson.option] [@key "distributedNodes"]
      distributedNodes: option(list(BackendNode.t)), /* Distributed nodes for given insertion point. */
      [@yojson.option] [@key "isSVG"]
      isSVG: option(bool), /* Whether the node is SVG. */
      [@yojson.option] [@key "compatibilityMode"]
      compatibilityMode: option(CompatibilityMode.t) /* No description provided */,
    };
  }
  and RGBA: {
    /* A structure holding an RGBA color. */
    [@deriving yojson]
    type t = {
      [@key "r"]
      r: float, /* The red component, in the [0-255] range. */
      [@key "g"]
      g: float, /* The green component, in the [0-255] range. */
      [@key "b"]
      b: float, /* The blue component, in the [0-255] range. */
      [@yojson.option] [@key "a"]
      a: option(float) /* The alpha component, in the [0-1] range (default: 1). */,
    };
  }
  and Quad: {
    /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
    [@deriving yojson]
    type t = list(float);
  }
  and BoxModel: {
    /* Box model. */
    [@deriving yojson]
    type t = {
      [@key "content"]
      content: Quad.t, /* Content box */
      [@key "padding"]
      padding: Quad.t, /* Padding box */
      [@key "border"]
      border: Quad.t, /* Border box */
      [@key "margin"]
      margin: Quad.t, /* Margin box */
      [@key "width"]
      width: float, /* Node width */
      [@key "height"]
      height: float, /* Node height */
      [@yojson.option] [@key "shapeOutside"]
      shapeOutside: option(ShapeOutsideInfo.t) /* Shape outside coordinates */,
    };
  }
  and ShapeOutsideInfo: {
    /* CSS Shape Outside details. */
    [@deriving yojson]
    type t = {
      [@key "bounds"]
      bounds: Quad.t, /* Shape bounds */
      [@key "shape"]
      shape: list(string), /* Shape coordinate details */
      [@key "marginShape"]
      marginShape: list(string) /* Margin shape bounds */,
    };
  }
  and Rect: {
    /* Rectangle. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X coordinate */
      [@key "y"]
      y: float, /* Y coordinate */
      [@key "width"]
      width: float, /* Rectangle width */
      [@key "height"]
      height: float /* Rectangle height */,
    };
  }
  and CSSComputedStyleProperty: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Computed style property name. */
      [@key "value"]
      value: string /* Computed style property value. */,
    };
  };
} = {
  module rec NodeId: {
    /* Unique DOM node identifier. */
    [@deriving yojson]
    type t = float;
  } = {
    /* Unique DOM node identifier. */
    [@deriving yojson]
    type t = float;
  }
  and BackendNodeId: {
    /* Unique DOM node identifier used to reference a node that may not have been pushed to the
       front-end. */
    [@deriving yojson]
    type t = float;
  } = {
    /* Unique DOM node identifier used to reference a node that may not have been pushed to the
       front-end. */
    [@deriving yojson]
    type t = float;
  }
  and BackendNode: {
    /* Backend node with a friendly name. */
    [@deriving yojson]
    type t = {
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "backendNodeId"]
      backendNodeId: BackendNodeId.t /* No description provided */,
    };
  } = {
    /* Backend node with a friendly name. */
    [@deriving yojson]
    type t = {
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "backendNodeId"]
      backendNodeId: BackendNodeId.t /* No description provided */,
    };
  }
  and PseudoType: {
    type _pseudotype = [
      | `first_line
      | `first_letter
      | `before
      | `after
      | `marker
      | `backdrop
      | `selection
      | `target_text
      | `spelling_error
      | `grammar_error
      | `highlight
      | `first_line_inherited
      | `scrollbar
      | `scrollbar_thumb
      | `scrollbar_button
      | `scrollbar_track
      | `scrollbar_track_piece
      | `scrollbar_corner
      | `resizer
      | `input_list_button
    ];
    let _pseudotype_of_yojson: Yojson.Basic.t => _pseudotype;
    let yojson_of__pseudotype: _pseudotype => Yojson.Basic.t;
    /* Pseudo element type. */
    [@deriving yojson]
    type t = _pseudotype;
  } = {
    type _pseudotype = [
      | `first_line
      | `first_letter
      | `before
      | `after
      | `marker
      | `backdrop
      | `selection
      | `target_text
      | `spelling_error
      | `grammar_error
      | `highlight
      | `first_line_inherited
      | `scrollbar
      | `scrollbar_thumb
      | `scrollbar_button
      | `scrollbar_track
      | `scrollbar_track_piece
      | `scrollbar_corner
      | `resizer
      | `input_list_button
    ];
    let _pseudotype_of_yojson =
      fun
      | `String("first-line") => `first_line
      | `String("first-letter") => `first_letter
      | `String("before") => `before
      | `String("after") => `after
      | `String("marker") => `marker
      | `String("backdrop") => `backdrop
      | `String("selection") => `selection
      | `String("target-text") => `target_text
      | `String("spelling-error") => `spelling_error
      | `String("grammar-error") => `grammar_error
      | `String("highlight") => `highlight
      | `String("first-line-inherited") => `first_line_inherited
      | `String("scrollbar") => `scrollbar
      | `String("scrollbar-thumb") => `scrollbar_thumb
      | `String("scrollbar-button") => `scrollbar_button
      | `String("scrollbar-track") => `scrollbar_track
      | `String("scrollbar-track-piece") => `scrollbar_track_piece
      | `String("scrollbar-corner") => `scrollbar_corner
      | `String("resizer") => `resizer
      | `String("input-list-button") => `input_list_button
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__pseudotype =
      fun
      | `first_line => `String("first-line")
      | `first_letter => `String("first-letter")
      | `before => `String("before")
      | `after => `String("after")
      | `marker => `String("marker")
      | `backdrop => `String("backdrop")
      | `selection => `String("selection")
      | `target_text => `String("target-text")
      | `spelling_error => `String("spelling-error")
      | `grammar_error => `String("grammar-error")
      | `highlight => `String("highlight")
      | `first_line_inherited => `String("first-line-inherited")
      | `scrollbar => `String("scrollbar")
      | `scrollbar_thumb => `String("scrollbar-thumb")
      | `scrollbar_button => `String("scrollbar-button")
      | `scrollbar_track => `String("scrollbar-track")
      | `scrollbar_track_piece => `String("scrollbar-track-piece")
      | `scrollbar_corner => `String("scrollbar-corner")
      | `resizer => `String("resizer")
      | `input_list_button => `String("input-list-button");
    /* Pseudo element type. */
    [@deriving yojson]
    type t = _pseudotype;
  }
  and ShadowRootType: {
    type _shadowroottype = [ | `user_agent | `open_ | `closed];
    let _shadowroottype_of_yojson: Yojson.Basic.t => _shadowroottype;
    let yojson_of__shadowroottype: _shadowroottype => Yojson.Basic.t;
    /* Shadow root type. */
    [@deriving yojson]
    type t = _shadowroottype;
  } = {
    type _shadowroottype = [ | `user_agent | `open_ | `closed];
    let _shadowroottype_of_yojson =
      fun
      | `String("user-agent") => `user_agent
      | `String("open") => `open_
      | `String("closed") => `closed
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__shadowroottype =
      fun
      | `user_agent => `String("user-agent")
      | `open_ => `String("open")
      | `closed => `String("closed");
    /* Shadow root type. */
    [@deriving yojson]
    type t = _shadowroottype;
  }
  and CompatibilityMode: {
    type _compatibilitymode = [
      | `QuirksMode
      | `LimitedQuirksMode
      | `NoQuirksMode
    ];
    let _compatibilitymode_of_yojson: Yojson.Basic.t => _compatibilitymode;
    let yojson_of__compatibilitymode: _compatibilitymode => Yojson.Basic.t;
    /* Document compatibility mode. */
    [@deriving yojson]
    type t = _compatibilitymode;
  } = {
    type _compatibilitymode = [
      | `QuirksMode
      | `LimitedQuirksMode
      | `NoQuirksMode
    ];
    let _compatibilitymode_of_yojson =
      fun
      | `String("QuirksMode") => `QuirksMode
      | `String("LimitedQuirksMode") => `LimitedQuirksMode
      | `String("NoQuirksMode") => `NoQuirksMode
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__compatibilitymode =
      fun
      | `QuirksMode => `String("QuirksMode")
      | `LimitedQuirksMode => `String("LimitedQuirksMode")
      | `NoQuirksMode => `String("NoQuirksMode");
    /* Document compatibility mode. */
    [@deriving yojson]
    type t = _compatibilitymode;
  }
  and Node: {
    /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
       DOMNode is a base node mirror type. */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
      [@yojson.option] [@key "parentId"]
      parentId: option(NodeId.t), /* The id of the parent node if any. */
      [@key "backendNodeId"]
      backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "localName"]
      localName: string, /* `Node`'s localName. */
      [@key "nodeValue"]
      nodeValue: string, /* `Node`'s nodeValue. */
      [@yojson.option] [@key "childNodeCount"]
      childNodeCount: option(float), /* Child count for `Container` nodes. */
      [@yojson.option] [@key "children"]
      children: option(list(Node.t)), /* Child nodes of this node when requested with children. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(string)), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
      [@yojson.option] [@key "documentURL"]
      documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@yojson.option] [@key "publicId"]
      publicId: option(string), /* `DocumentType`'s publicId. */
      [@yojson.option] [@key "systemId"]
      systemId: option(string), /* `DocumentType`'s systemId. */
      [@yojson.option] [@key "internalSubset"]
      internalSubset: option(string), /* `DocumentType`'s internalSubset. */
      [@yojson.option] [@key "xmlVersion"]
      xmlVersion: option(string), /* `Document`'s XML version in case of XML documents. */
      [@yojson.option] [@key "name"]
      name: option(string), /* `Attr`'s name. */
      [@yojson.option] [@key "value"]
      value: option(string), /* `Attr`'s value. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(PseudoType.t), /* Pseudo element type for this node. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(ShadowRootType.t), /* Shadow root type. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t), /* Frame ID for frame owner elements. */
      [@yojson.option] [@key "contentDocument"]
      contentDocument: option(Node.t), /* Content document for frame owner elements. */
      [@yojson.option] [@key "shadowRoots"]
      shadowRoots: option(list(Node.t)), /* Shadow root list for given element host. */
      [@yojson.option] [@key "templateContent"]
      templateContent: option(Node.t), /* Content document fragment for template elements. */
      [@yojson.option] [@key "pseudoElements"]
      pseudoElements: option(list(Node.t)), /* Pseudo elements associated with this node. */
      [@yojson.option] [@key "importedDocument"]
      importedDocument: option(Node.t), /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
      [@yojson.option] [@key "distributedNodes"]
      distributedNodes: option(list(BackendNode.t)), /* Distributed nodes for given insertion point. */
      [@yojson.option] [@key "isSVG"]
      isSVG: option(bool), /* Whether the node is SVG. */
      [@yojson.option] [@key "compatibilityMode"]
      compatibilityMode: option(CompatibilityMode.t) /* No description provided */,
    };
  } = {
    /* DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes.
       DOMNode is a base node mirror type. */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: NodeId.t, /* Node identifier that is passed into the rest of the DOM messages as the `nodeId`. Backend
will only push node with given `id` once. It is aware of all requested nodes and will only
fire DOM events for nodes known to the client. */
      [@yojson.option] [@key "parentId"]
      parentId: option(NodeId.t), /* The id of the parent node if any. */
      [@key "backendNodeId"]
      backendNodeId: BackendNodeId.t, /* The BackendNodeId for this node. */
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "localName"]
      localName: string, /* `Node`'s localName. */
      [@key "nodeValue"]
      nodeValue: string, /* `Node`'s nodeValue. */
      [@yojson.option] [@key "childNodeCount"]
      childNodeCount: option(float), /* Child count for `Container` nodes. */
      [@yojson.option] [@key "children"]
      children: option(list(Node.t)), /* Child nodes of this node when requested with children. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(string)), /* Attributes of the `Element` node in the form of flat array `[name1, value1, name2, value2]`. */
      [@yojson.option] [@key "documentURL"]
      documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@yojson.option] [@key "publicId"]
      publicId: option(string), /* `DocumentType`'s publicId. */
      [@yojson.option] [@key "systemId"]
      systemId: option(string), /* `DocumentType`'s systemId. */
      [@yojson.option] [@key "internalSubset"]
      internalSubset: option(string), /* `DocumentType`'s internalSubset. */
      [@yojson.option] [@key "xmlVersion"]
      xmlVersion: option(string), /* `Document`'s XML version in case of XML documents. */
      [@yojson.option] [@key "name"]
      name: option(string), /* `Attr`'s name. */
      [@yojson.option] [@key "value"]
      value: option(string), /* `Attr`'s value. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(PseudoType.t), /* Pseudo element type for this node. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(ShadowRootType.t), /* Shadow root type. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t), /* Frame ID for frame owner elements. */
      [@yojson.option] [@key "contentDocument"]
      contentDocument: option(Node.t), /* Content document for frame owner elements. */
      [@yojson.option] [@key "shadowRoots"]
      shadowRoots: option(list(Node.t)), /* Shadow root list for given element host. */
      [@yojson.option] [@key "templateContent"]
      templateContent: option(Node.t), /* Content document fragment for template elements. */
      [@yojson.option] [@key "pseudoElements"]
      pseudoElements: option(list(Node.t)), /* Pseudo elements associated with this node. */
      [@yojson.option] [@key "importedDocument"]
      importedDocument: option(Node.t), /* Deprecated, as the HTML Imports API has been removed (crbug.com/937746).
This property used to return the imported document for the HTMLImport links.
The property is always undefined now. */
      [@yojson.option] [@key "distributedNodes"]
      distributedNodes: option(list(BackendNode.t)), /* Distributed nodes for given insertion point. */
      [@yojson.option] [@key "isSVG"]
      isSVG: option(bool), /* Whether the node is SVG. */
      [@yojson.option] [@key "compatibilityMode"]
      compatibilityMode: option(CompatibilityMode.t) /* No description provided */,
    };
  }
  and RGBA: {
    /* A structure holding an RGBA color. */
    [@deriving yojson]
    type t = {
      [@key "r"]
      r: float, /* The red component, in the [0-255] range. */
      [@key "g"]
      g: float, /* The green component, in the [0-255] range. */
      [@key "b"]
      b: float, /* The blue component, in the [0-255] range. */
      [@yojson.option] [@key "a"]
      a: option(float) /* The alpha component, in the [0-1] range (default: 1). */,
    };
  } = {
    /* A structure holding an RGBA color. */
    [@deriving yojson]
    type t = {
      [@key "r"]
      r: float, /* The red component, in the [0-255] range. */
      [@key "g"]
      g: float, /* The green component, in the [0-255] range. */
      [@key "b"]
      b: float, /* The blue component, in the [0-255] range. */
      [@yojson.option] [@key "a"]
      a: option(float) /* The alpha component, in the [0-1] range (default: 1). */,
    };
  }
  and Quad: {
    /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
    [@deriving yojson]
    type t = list(float);
  } = {
    /* An array of quad vertices, x immediately followed by y for each point, points clock-wise. */
    [@deriving yojson]
    type t = list(float);
  }
  and BoxModel: {
    /* Box model. */
    [@deriving yojson]
    type t = {
      [@key "content"]
      content: Quad.t, /* Content box */
      [@key "padding"]
      padding: Quad.t, /* Padding box */
      [@key "border"]
      border: Quad.t, /* Border box */
      [@key "margin"]
      margin: Quad.t, /* Margin box */
      [@key "width"]
      width: float, /* Node width */
      [@key "height"]
      height: float, /* Node height */
      [@yojson.option] [@key "shapeOutside"]
      shapeOutside: option(ShapeOutsideInfo.t) /* Shape outside coordinates */,
    };
  } = {
    /* Box model. */
    [@deriving yojson]
    type t = {
      [@key "content"]
      content: Quad.t, /* Content box */
      [@key "padding"]
      padding: Quad.t, /* Padding box */
      [@key "border"]
      border: Quad.t, /* Border box */
      [@key "margin"]
      margin: Quad.t, /* Margin box */
      [@key "width"]
      width: float, /* Node width */
      [@key "height"]
      height: float, /* Node height */
      [@yojson.option] [@key "shapeOutside"]
      shapeOutside: option(ShapeOutsideInfo.t) /* Shape outside coordinates */,
    };
  }
  and ShapeOutsideInfo: {
    /* CSS Shape Outside details. */
    [@deriving yojson]
    type t = {
      [@key "bounds"]
      bounds: Quad.t, /* Shape bounds */
      [@key "shape"]
      shape: list(string), /* Shape coordinate details */
      [@key "marginShape"]
      marginShape: list(string) /* Margin shape bounds */,
    };
  } = {
    /* CSS Shape Outside details. */
    [@deriving yojson]
    type t = {
      [@key "bounds"]
      bounds: Quad.t, /* Shape bounds */
      [@key "shape"]
      shape: list(string), /* Shape coordinate details */
      [@key "marginShape"]
      marginShape: list(string) /* Margin shape bounds */,
    };
  }
  and Rect: {
    /* Rectangle. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X coordinate */
      [@key "y"]
      y: float, /* Y coordinate */
      [@key "width"]
      width: float, /* Rectangle width */
      [@key "height"]
      height: float /* Rectangle height */,
    };
  } = {
    /* Rectangle. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X coordinate */
      [@key "y"]
      y: float, /* Y coordinate */
      [@key "width"]
      width: float, /* Rectangle width */
      [@key "height"]
      height: float /* Rectangle height */,
    };
  }
  and CSSComputedStyleProperty: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Computed style property name. */
      [@key "value"]
      value: string /* Computed style property value. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Computed style property name. */
      [@key "value"]
      value: string /* Computed style property value. */,
    };
  };
}
and DOMDebugger: {
  module rec DOMBreakpointType: {
    type _dombreakpointtype = [
      | `subtree_modified
      | `attribute_modified
      | `node_removed
    ];
    let _dombreakpointtype_of_yojson: Yojson.Basic.t => _dombreakpointtype;
    let yojson_of__dombreakpointtype: _dombreakpointtype => Yojson.Basic.t;
    /* DOM breakpoint type. */
    [@deriving yojson]
    type t = _dombreakpointtype;
  }
  and CSPViolationType: {
    type _cspviolationtype = [
      | `trustedtype_sink_violation
      | `trustedtype_policy_violation
    ];
    let _cspviolationtype_of_yojson: Yojson.Basic.t => _cspviolationtype;
    let yojson_of__cspviolationtype: _cspviolationtype => Yojson.Basic.t;
    /* CSP Violation type. */
    [@deriving yojson]
    type t = _cspviolationtype;
  }
  and EventListener: {
    /* Object event listener. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: string, /* `EventListener`'s type. */
      [@key "useCapture"]
      useCapture: bool, /* `EventListener`'s useCapture. */
      [@key "passive"]
      passive: bool, /* `EventListener`'s passive flag. */
      [@key "once"]
      once: bool, /* `EventListener`'s once flag. */
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script id of the handler code. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@key "columnNumber"]
      columnNumber: float, /* Column number in the script (0-based). */
      [@yojson.option] [@key "handler"]
      handler: option(Runtime.RemoteObject.t), /* Event handler function value. */
      [@yojson.option] [@key "originalHandler"]
      originalHandler: option(Runtime.RemoteObject.t), /* Event original handler function value. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t) /* Node the listener is added to (if any). */,
    };
  };
} = {
  module rec DOMBreakpointType: {
    type _dombreakpointtype = [
      | `subtree_modified
      | `attribute_modified
      | `node_removed
    ];
    let _dombreakpointtype_of_yojson: Yojson.Basic.t => _dombreakpointtype;
    let yojson_of__dombreakpointtype: _dombreakpointtype => Yojson.Basic.t;
    /* DOM breakpoint type. */
    [@deriving yojson]
    type t = _dombreakpointtype;
  } = {
    type _dombreakpointtype = [
      | `subtree_modified
      | `attribute_modified
      | `node_removed
    ];
    let _dombreakpointtype_of_yojson =
      fun
      | `String("subtree-modified") => `subtree_modified
      | `String("attribute-modified") => `attribute_modified
      | `String("node-removed") => `node_removed
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__dombreakpointtype =
      fun
      | `subtree_modified => `String("subtree-modified")
      | `attribute_modified => `String("attribute-modified")
      | `node_removed => `String("node-removed");
    /* DOM breakpoint type. */
    [@deriving yojson]
    type t = _dombreakpointtype;
  }
  and CSPViolationType: {
    type _cspviolationtype = [
      | `trustedtype_sink_violation
      | `trustedtype_policy_violation
    ];
    let _cspviolationtype_of_yojson: Yojson.Basic.t => _cspviolationtype;
    let yojson_of__cspviolationtype: _cspviolationtype => Yojson.Basic.t;
    /* CSP Violation type. */
    [@deriving yojson]
    type t = _cspviolationtype;
  } = {
    type _cspviolationtype = [
      | `trustedtype_sink_violation
      | `trustedtype_policy_violation
    ];
    let _cspviolationtype_of_yojson =
      fun
      | `String("trustedtype-sink-violation") => `trustedtype_sink_violation
      | `String("trustedtype-policy-violation") => `trustedtype_policy_violation
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__cspviolationtype =
      fun
      | `trustedtype_sink_violation => `String("trustedtype-sink-violation")
      | `trustedtype_policy_violation =>
        `String("trustedtype-policy-violation");
    /* CSP Violation type. */
    [@deriving yojson]
    type t = _cspviolationtype;
  }
  and EventListener: {
    /* Object event listener. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: string, /* `EventListener`'s type. */
      [@key "useCapture"]
      useCapture: bool, /* `EventListener`'s useCapture. */
      [@key "passive"]
      passive: bool, /* `EventListener`'s passive flag. */
      [@key "once"]
      once: bool, /* `EventListener`'s once flag. */
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script id of the handler code. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@key "columnNumber"]
      columnNumber: float, /* Column number in the script (0-based). */
      [@yojson.option] [@key "handler"]
      handler: option(Runtime.RemoteObject.t), /* Event handler function value. */
      [@yojson.option] [@key "originalHandler"]
      originalHandler: option(Runtime.RemoteObject.t), /* Event original handler function value. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t) /* Node the listener is added to (if any). */,
    };
  } = {
    /* Object event listener. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: string, /* `EventListener`'s type. */
      [@key "useCapture"]
      useCapture: bool, /* `EventListener`'s useCapture. */
      [@key "passive"]
      passive: bool, /* `EventListener`'s passive flag. */
      [@key "once"]
      once: bool, /* `EventListener`'s once flag. */
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script id of the handler code. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@key "columnNumber"]
      columnNumber: float, /* Column number in the script (0-based). */
      [@yojson.option] [@key "handler"]
      handler: option(Runtime.RemoteObject.t), /* Event handler function value. */
      [@yojson.option] [@key "originalHandler"]
      originalHandler: option(Runtime.RemoteObject.t), /* Event original handler function value. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t) /* Node the listener is added to (if any). */,
    };
  };
}
and DOMSnapshot: {
  module rec DOMNode: {
    /* A Node in the DOM tree. */
    [@deriving yojson]
    type t = {
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "nodeValue"]
      nodeValue: string, /* `Node`'s nodeValue. */
      [@yojson.option] [@key "textValue"]
      textValue: option(string), /* Only set for textarea elements, contains the text value. */
      [@yojson.option] [@key "inputValue"]
      inputValue: option(string), /* Only set for input elements, contains the input's associated text value. */
      [@yojson.option] [@key "inputChecked"]
      inputChecked: option(bool), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
      [@yojson.option] [@key "optionSelected"]
      optionSelected: option(bool), /* Only set for option elements, indicates if the element has been selected */
      [@key "backendNodeId"]
      backendNodeId: DOM.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
      [@yojson.option] [@key "childNodeIndexes"]
      childNodeIndexes: option(list(float)), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(NameValue.t)), /* Attributes of an `Element` node. */
      [@yojson.option] [@key "pseudoElementIndexes"]
      pseudoElementIndexes: option(list(float)), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "layoutNodeIndex"]
      layoutNodeIndex: option(float), /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "documentURL"]
      documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@yojson.option] [@key "contentLanguage"]
      contentLanguage: option(string), /* Only set for documents, contains the document's content language. */
      [@yojson.option] [@key "documentEncoding"]
      documentEncoding: option(string), /* Only set for documents, contains the document's character set encoding. */
      [@yojson.option] [@key "publicId"]
      publicId: option(string), /* `DocumentType` node's publicId. */
      [@yojson.option] [@key "systemId"]
      systemId: option(string), /* `DocumentType` node's systemId. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t), /* Frame ID for frame owner elements and also for the document node. */
      [@yojson.option] [@key "contentDocumentIndex"]
      contentDocumentIndex: option(float), /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(DOM.PseudoType.t), /* Type of a pseudo element node. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(DOM.ShadowRootType.t), /* Shadow root type. */
      [@yojson.option] [@key "isClickable"]
      isClickable: option(bool), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
      [@yojson.option] [@key "eventListeners"]
      eventListeners: option(list(DOMDebugger.EventListener.t)), /* Details of the node's event listeners, if any. */
      [@yojson.option] [@key "currentSourceURL"]
      currentSourceURL: option(string), /* The selected url for nodes with a srcset attribute. */
      [@yojson.option] [@key "originURL"]
      originURL: option(string), /* The url of the script (if any) that generates this node. */
      [@yojson.option] [@key "scrollOffsetX"]
      scrollOffsetX: option(float), /* Scroll offsets, set when this node is a Document. */
      [@yojson.option] [@key "scrollOffsetY"]
      scrollOffsetY: option(float) /* No description provided */,
    };
  }
  and InlineTextBox: {
    /* Details of post layout rendered text positions. The exact layout should not be regarded as
       stable and may change between versions. */
    [@deriving yojson]
    type t = {
      [@key "boundingBox"]
      boundingBox: DOM.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
      [@key "startCharacterIndex"]
      startCharacterIndex: float, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
      [@key "numCharacters"]
      numCharacters: float /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
    };
  }
  and LayoutTreeNode: {
    /* Details of an element in the DOM tree with a LayoutObject. */
    [@deriving yojson]
    type t = {
      [@key "domNodeIndex"]
      domNodeIndex: float, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
      [@key "boundingBox"]
      boundingBox: DOM.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
      [@yojson.option] [@key "layoutText"]
      layoutText: option(string), /* Contents of the LayoutText, if any. */
      [@yojson.option] [@key "inlineTextNodes"]
      inlineTextNodes: option(list(InlineTextBox.t)), /* The post-layout inline text nodes, if any. */
      [@yojson.option] [@key "styleIndex"]
      styleIndex: option(float), /* Index into the `computedStyles` array returned by `getSnapshot`. */
      [@yojson.option] [@key "paintOrder"]
      paintOrder: option(float), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
      [@yojson.option] [@key "isStackingContext"]
      isStackingContext: option(bool) /* Set to true to indicate the element begins a new stacking context. */,
    };
  }
  and ComputedStyle: {
    /* A subset of the full ComputedStyle as defined by the request whitelist. */
    [@deriving yojson]
    type t = {
      [@key "properties"]
      properties: list(NameValue.t) /* Name/value pairs of computed style properties. */,
    };
  }
  and NameValue: {
    /* A name/value pair. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Attribute/property name. */
      [@key "value"]
      value: string /* Attribute/property value. */,
    };
  }
  and StringIndex: {
    /* Index of the string in the strings table. */
    [@deriving yojson]
    type t = float;
  }
  and ArrayOfStrings: {
    /* Index of the string in the strings table. */
    [@deriving yojson]
    type t = list(StringIndex.t);
  }
  and RareStringData: {
    /* Data that is only present on rare nodes. */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float), /* No description provided */
      [@key "value"]
      value: list(StringIndex.t) /* No description provided */,
    };
  }
  and RareBooleanData: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float) /* No description provided */,
    };
  }
  and RareIntegerData: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float), /* No description provided */
      [@key "value"]
      value: list(float) /* No description provided */,
    };
  }
  and Rectangle: {
    /* No description provided */
    [@deriving yojson]
    type t = list(float);
  }
  and DocumentSnapshot: {
    /* Document snapshot. */
    [@deriving yojson]
    type t = {
      [@key "documentURL"]
      documentURL: StringIndex.t, /* Document URL that `Document` or `FrameOwner` node points to. */
      [@key "title"]
      title: StringIndex.t, /* Document title. */
      [@key "baseURL"]
      baseURL: StringIndex.t, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@key "contentLanguage"]
      contentLanguage: StringIndex.t, /* Contains the document's content language. */
      [@key "encodingName"]
      encodingName: StringIndex.t, /* Contains the document's character set encoding. */
      [@key "publicId"]
      publicId: StringIndex.t, /* `DocumentType` node's publicId. */
      [@key "systemId"]
      systemId: StringIndex.t, /* `DocumentType` node's systemId. */
      [@key "frameId"]
      frameId: StringIndex.t, /* Frame ID for frame owner elements and also for the document node. */
      [@key "nodes"]
      nodes: NodeTreeSnapshot.t, /* A table with dom nodes. */
      [@key "layout"]
      layout: LayoutTreeSnapshot.t, /* The nodes in the layout tree. */
      [@key "textBoxes"]
      textBoxes: TextBoxSnapshot.t, /* The post-layout inline text nodes. */
      [@yojson.option] [@key "scrollOffsetX"]
      scrollOffsetX: option(float), /* Horizontal scroll offset. */
      [@yojson.option] [@key "scrollOffsetY"]
      scrollOffsetY: option(float), /* Vertical scroll offset. */
      [@yojson.option] [@key "contentWidth"]
      contentWidth: option(float), /* Document content width. */
      [@yojson.option] [@key "contentHeight"]
      contentHeight: option(float) /* Document content height. */,
    };
  }
  and NodeTreeSnapshot: {
    /* Table containing nodes. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "parentIndex"]
      parentIndex: option(list(float)), /* Parent node index. */
      [@yojson.option] [@key "nodeType"]
      nodeType: option(list(float)), /* `Node`'s nodeType. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(RareStringData.t), /* Type of the shadow root the `Node` is in. String values are equal to the `ShadowRootType` enum. */
      [@yojson.option] [@key "nodeName"]
      nodeName: option(list(StringIndex.t)), /* `Node`'s nodeName. */
      [@yojson.option] [@key "nodeValue"]
      nodeValue: option(list(StringIndex.t)), /* `Node`'s nodeValue. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(list(DOM.BackendNodeId.t)), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(ArrayOfStrings.t)), /* Attributes of an `Element` node. Flatten name, value pairs. */
      [@yojson.option] [@key "textValue"]
      textValue: option(RareStringData.t), /* Only set for textarea elements, contains the text value. */
      [@yojson.option] [@key "inputValue"]
      inputValue: option(RareStringData.t), /* Only set for input elements, contains the input's associated text value. */
      [@yojson.option] [@key "inputChecked"]
      inputChecked: option(RareBooleanData.t), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
      [@yojson.option] [@key "optionSelected"]
      optionSelected: option(RareBooleanData.t), /* Only set for option elements, indicates if the element has been selected */
      [@yojson.option] [@key "contentDocumentIndex"]
      contentDocumentIndex: option(RareIntegerData.t), /* The index of the document in the list of the snapshot documents. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(RareStringData.t), /* Type of a pseudo element node. */
      [@yojson.option] [@key "isClickable"]
      isClickable: option(RareBooleanData.t), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
      [@yojson.option] [@key "currentSourceURL"]
      currentSourceURL: option(RareStringData.t), /* The selected url for nodes with a srcset attribute. */
      [@yojson.option] [@key "originURL"]
      originURL: option(RareStringData.t) /* The url of the script (if any) that generates this node. */,
    };
  }
  and LayoutTreeSnapshot: {
    /* Table of details of an element in the DOM tree with a LayoutObject. */
    [@deriving yojson]
    type t = {
      [@key "nodeIndex"]
      nodeIndex: list(float), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
      [@key "styles"]
      styles: list(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
      [@key "bounds"]
      bounds: list(Rectangle.t), /* The absolute position bounding box. */
      [@key "text"]
      text: list(StringIndex.t), /* Contents of the LayoutText, if any. */
      [@key "stackingContexts"]
      stackingContexts: RareBooleanData.t, /* Stacking context information. */
      [@yojson.option] [@key "paintOrders"]
      paintOrders: option(list(float)), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
      [@yojson.option] [@key "offsetRects"]
      offsetRects: option(list(Rectangle.t)), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "scrollRects"]
      scrollRects: option(list(Rectangle.t)), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "clientRects"]
      clientRects: option(list(Rectangle.t)), /* The client rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "blendedBackgroundColors"]
      blendedBackgroundColors: option(list(StringIndex.t)), /* The list of background colors that are blended with colors of overlapping elements. */
      [@yojson.option] [@key "textColorOpacities"]
      textColorOpacities: option(list(float)) /* The list of computed text opacities. */,
    };
  }
  and TextBoxSnapshot: {
    /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
       stable and may change between versions. */
    [@deriving yojson]
    type t = {
      [@key "layoutIndex"]
      layoutIndex: list(float), /* Index of the layout tree node that owns this box collection. */
      [@key "bounds"]
      bounds: list(Rectangle.t), /* The absolute position bounding box. */
      [@key "start"]
      start: list(float), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
      [@key "length"]
      length: list(float) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
    };
  };
} = {
  module rec DOMNode: {
    /* A Node in the DOM tree. */
    [@deriving yojson]
    type t = {
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "nodeValue"]
      nodeValue: string, /* `Node`'s nodeValue. */
      [@yojson.option] [@key "textValue"]
      textValue: option(string), /* Only set for textarea elements, contains the text value. */
      [@yojson.option] [@key "inputValue"]
      inputValue: option(string), /* Only set for input elements, contains the input's associated text value. */
      [@yojson.option] [@key "inputChecked"]
      inputChecked: option(bool), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
      [@yojson.option] [@key "optionSelected"]
      optionSelected: option(bool), /* Only set for option elements, indicates if the element has been selected */
      [@key "backendNodeId"]
      backendNodeId: DOM.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
      [@yojson.option] [@key "childNodeIndexes"]
      childNodeIndexes: option(list(float)), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(NameValue.t)), /* Attributes of an `Element` node. */
      [@yojson.option] [@key "pseudoElementIndexes"]
      pseudoElementIndexes: option(list(float)), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "layoutNodeIndex"]
      layoutNodeIndex: option(float), /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "documentURL"]
      documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@yojson.option] [@key "contentLanguage"]
      contentLanguage: option(string), /* Only set for documents, contains the document's content language. */
      [@yojson.option] [@key "documentEncoding"]
      documentEncoding: option(string), /* Only set for documents, contains the document's character set encoding. */
      [@yojson.option] [@key "publicId"]
      publicId: option(string), /* `DocumentType` node's publicId. */
      [@yojson.option] [@key "systemId"]
      systemId: option(string), /* `DocumentType` node's systemId. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t), /* Frame ID for frame owner elements and also for the document node. */
      [@yojson.option] [@key "contentDocumentIndex"]
      contentDocumentIndex: option(float), /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(DOM.PseudoType.t), /* Type of a pseudo element node. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(DOM.ShadowRootType.t), /* Shadow root type. */
      [@yojson.option] [@key "isClickable"]
      isClickable: option(bool), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
      [@yojson.option] [@key "eventListeners"]
      eventListeners: option(list(DOMDebugger.EventListener.t)), /* Details of the node's event listeners, if any. */
      [@yojson.option] [@key "currentSourceURL"]
      currentSourceURL: option(string), /* The selected url for nodes with a srcset attribute. */
      [@yojson.option] [@key "originURL"]
      originURL: option(string), /* The url of the script (if any) that generates this node. */
      [@yojson.option] [@key "scrollOffsetX"]
      scrollOffsetX: option(float), /* Scroll offsets, set when this node is a Document. */
      [@yojson.option] [@key "scrollOffsetY"]
      scrollOffsetY: option(float) /* No description provided */,
    };
  } = {
    /* A Node in the DOM tree. */
    [@deriving yojson]
    type t = {
      [@key "nodeType"]
      nodeType: float, /* `Node`'s nodeType. */
      [@key "nodeName"]
      nodeName: string, /* `Node`'s nodeName. */
      [@key "nodeValue"]
      nodeValue: string, /* `Node`'s nodeValue. */
      [@yojson.option] [@key "textValue"]
      textValue: option(string), /* Only set for textarea elements, contains the text value. */
      [@yojson.option] [@key "inputValue"]
      inputValue: option(string), /* Only set for input elements, contains the input's associated text value. */
      [@yojson.option] [@key "inputChecked"]
      inputChecked: option(bool), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
      [@yojson.option] [@key "optionSelected"]
      optionSelected: option(bool), /* Only set for option elements, indicates if the element has been selected */
      [@key "backendNodeId"]
      backendNodeId: DOM.BackendNodeId.t, /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
      [@yojson.option] [@key "childNodeIndexes"]
      childNodeIndexes: option(list(float)), /* The indexes of the node's child nodes in the `domNodes` array returned by `getSnapshot`, if
any. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(NameValue.t)), /* Attributes of an `Element` node. */
      [@yojson.option] [@key "pseudoElementIndexes"]
      pseudoElementIndexes: option(list(float)), /* Indexes of pseudo elements associated with this node in the `domNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "layoutNodeIndex"]
      layoutNodeIndex: option(float), /* The index of the node's related layout tree node in the `layoutTreeNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "documentURL"]
      documentURL: option(string), /* Document URL that `Document` or `FrameOwner` node points to. */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string), /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@yojson.option] [@key "contentLanguage"]
      contentLanguage: option(string), /* Only set for documents, contains the document's content language. */
      [@yojson.option] [@key "documentEncoding"]
      documentEncoding: option(string), /* Only set for documents, contains the document's character set encoding. */
      [@yojson.option] [@key "publicId"]
      publicId: option(string), /* `DocumentType` node's publicId. */
      [@yojson.option] [@key "systemId"]
      systemId: option(string), /* `DocumentType` node's systemId. */
      [@yojson.option] [@key "frameId"]
      frameId: option(Page.FrameId.t), /* Frame ID for frame owner elements and also for the document node. */
      [@yojson.option] [@key "contentDocumentIndex"]
      contentDocumentIndex: option(float), /* The index of a frame owner element's content document in the `domNodes` array returned by
`getSnapshot`, if any. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(DOM.PseudoType.t), /* Type of a pseudo element node. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(DOM.ShadowRootType.t), /* Shadow root type. */
      [@yojson.option] [@key "isClickable"]
      isClickable: option(bool), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
      [@yojson.option] [@key "eventListeners"]
      eventListeners: option(list(DOMDebugger.EventListener.t)), /* Details of the node's event listeners, if any. */
      [@yojson.option] [@key "currentSourceURL"]
      currentSourceURL: option(string), /* The selected url for nodes with a srcset attribute. */
      [@yojson.option] [@key "originURL"]
      originURL: option(string), /* The url of the script (if any) that generates this node. */
      [@yojson.option] [@key "scrollOffsetX"]
      scrollOffsetX: option(float), /* Scroll offsets, set when this node is a Document. */
      [@yojson.option] [@key "scrollOffsetY"]
      scrollOffsetY: option(float) /* No description provided */,
    };
  }
  and InlineTextBox: {
    /* Details of post layout rendered text positions. The exact layout should not be regarded as
       stable and may change between versions. */
    [@deriving yojson]
    type t = {
      [@key "boundingBox"]
      boundingBox: DOM.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
      [@key "startCharacterIndex"]
      startCharacterIndex: float, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
      [@key "numCharacters"]
      numCharacters: float /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
    };
  } = {
    /* Details of post layout rendered text positions. The exact layout should not be regarded as
       stable and may change between versions. */
    [@deriving yojson]
    type t = {
      [@key "boundingBox"]
      boundingBox: DOM.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
      [@key "startCharacterIndex"]
      startCharacterIndex: float, /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
      [@key "numCharacters"]
      numCharacters: float /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
    };
  }
  and LayoutTreeNode: {
    /* Details of an element in the DOM tree with a LayoutObject. */
    [@deriving yojson]
    type t = {
      [@key "domNodeIndex"]
      domNodeIndex: float, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
      [@key "boundingBox"]
      boundingBox: DOM.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
      [@yojson.option] [@key "layoutText"]
      layoutText: option(string), /* Contents of the LayoutText, if any. */
      [@yojson.option] [@key "inlineTextNodes"]
      inlineTextNodes: option(list(InlineTextBox.t)), /* The post-layout inline text nodes, if any. */
      [@yojson.option] [@key "styleIndex"]
      styleIndex: option(float), /* Index into the `computedStyles` array returned by `getSnapshot`. */
      [@yojson.option] [@key "paintOrder"]
      paintOrder: option(float), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
      [@yojson.option] [@key "isStackingContext"]
      isStackingContext: option(bool) /* Set to true to indicate the element begins a new stacking context. */,
    };
  } = {
    /* Details of an element in the DOM tree with a LayoutObject. */
    [@deriving yojson]
    type t = {
      [@key "domNodeIndex"]
      domNodeIndex: float, /* The index of the related DOM node in the `domNodes` array returned by `getSnapshot`. */
      [@key "boundingBox"]
      boundingBox: DOM.Rect.t, /* The bounding box in document coordinates. Note that scroll offset of the document is ignored. */
      [@yojson.option] [@key "layoutText"]
      layoutText: option(string), /* Contents of the LayoutText, if any. */
      [@yojson.option] [@key "inlineTextNodes"]
      inlineTextNodes: option(list(InlineTextBox.t)), /* The post-layout inline text nodes, if any. */
      [@yojson.option] [@key "styleIndex"]
      styleIndex: option(float), /* Index into the `computedStyles` array returned by `getSnapshot`. */
      [@yojson.option] [@key "paintOrder"]
      paintOrder: option(float), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
getSnapshot was true. */
      [@yojson.option] [@key "isStackingContext"]
      isStackingContext: option(bool) /* Set to true to indicate the element begins a new stacking context. */,
    };
  }
  and ComputedStyle: {
    /* A subset of the full ComputedStyle as defined by the request whitelist. */
    [@deriving yojson]
    type t = {
      [@key "properties"]
      properties: list(NameValue.t) /* Name/value pairs of computed style properties. */,
    };
  } = {
    /* A subset of the full ComputedStyle as defined by the request whitelist. */
    [@deriving yojson]
    type t = {
      [@key "properties"]
      properties: list(NameValue.t) /* Name/value pairs of computed style properties. */,
    };
  }
  and NameValue: {
    /* A name/value pair. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Attribute/property name. */
      [@key "value"]
      value: string /* Attribute/property value. */,
    };
  } = {
    /* A name/value pair. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Attribute/property name. */
      [@key "value"]
      value: string /* Attribute/property value. */,
    };
  }
  and StringIndex: {
    /* Index of the string in the strings table. */
    [@deriving yojson]
    type t = float;
  } = {
    /* Index of the string in the strings table. */
    [@deriving yojson]
    type t = float;
  }
  and ArrayOfStrings: {
    /* Index of the string in the strings table. */
    [@deriving yojson]
    type t = list(StringIndex.t);
  } = {
    /* Index of the string in the strings table. */
    [@deriving yojson]
    type t = list(StringIndex.t);
  }
  and RareStringData: {
    /* Data that is only present on rare nodes. */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float), /* No description provided */
      [@key "value"]
      value: list(StringIndex.t) /* No description provided */,
    };
  } = {
    /* Data that is only present on rare nodes. */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float), /* No description provided */
      [@key "value"]
      value: list(StringIndex.t) /* No description provided */,
    };
  }
  and RareBooleanData: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float) /* No description provided */,
    };
  }
  and RareIntegerData: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float), /* No description provided */
      [@key "value"]
      value: list(float) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "index"]
      index: list(float), /* No description provided */
      [@key "value"]
      value: list(float) /* No description provided */,
    };
  }
  and Rectangle: {
    /* No description provided */
    [@deriving yojson]
    type t = list(float);
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = list(float);
  }
  and DocumentSnapshot: {
    /* Document snapshot. */
    [@deriving yojson]
    type t = {
      [@key "documentURL"]
      documentURL: StringIndex.t, /* Document URL that `Document` or `FrameOwner` node points to. */
      [@key "title"]
      title: StringIndex.t, /* Document title. */
      [@key "baseURL"]
      baseURL: StringIndex.t, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@key "contentLanguage"]
      contentLanguage: StringIndex.t, /* Contains the document's content language. */
      [@key "encodingName"]
      encodingName: StringIndex.t, /* Contains the document's character set encoding. */
      [@key "publicId"]
      publicId: StringIndex.t, /* `DocumentType` node's publicId. */
      [@key "systemId"]
      systemId: StringIndex.t, /* `DocumentType` node's systemId. */
      [@key "frameId"]
      frameId: StringIndex.t, /* Frame ID for frame owner elements and also for the document node. */
      [@key "nodes"]
      nodes: NodeTreeSnapshot.t, /* A table with dom nodes. */
      [@key "layout"]
      layout: LayoutTreeSnapshot.t, /* The nodes in the layout tree. */
      [@key "textBoxes"]
      textBoxes: TextBoxSnapshot.t, /* The post-layout inline text nodes. */
      [@yojson.option] [@key "scrollOffsetX"]
      scrollOffsetX: option(float), /* Horizontal scroll offset. */
      [@yojson.option] [@key "scrollOffsetY"]
      scrollOffsetY: option(float), /* Vertical scroll offset. */
      [@yojson.option] [@key "contentWidth"]
      contentWidth: option(float), /* Document content width. */
      [@yojson.option] [@key "contentHeight"]
      contentHeight: option(float) /* Document content height. */,
    };
  } = {
    /* Document snapshot. */
    [@deriving yojson]
    type t = {
      [@key "documentURL"]
      documentURL: StringIndex.t, /* Document URL that `Document` or `FrameOwner` node points to. */
      [@key "title"]
      title: StringIndex.t, /* Document title. */
      [@key "baseURL"]
      baseURL: StringIndex.t, /* Base URL that `Document` or `FrameOwner` node uses for URL completion. */
      [@key "contentLanguage"]
      contentLanguage: StringIndex.t, /* Contains the document's content language. */
      [@key "encodingName"]
      encodingName: StringIndex.t, /* Contains the document's character set encoding. */
      [@key "publicId"]
      publicId: StringIndex.t, /* `DocumentType` node's publicId. */
      [@key "systemId"]
      systemId: StringIndex.t, /* `DocumentType` node's systemId. */
      [@key "frameId"]
      frameId: StringIndex.t, /* Frame ID for frame owner elements and also for the document node. */
      [@key "nodes"]
      nodes: NodeTreeSnapshot.t, /* A table with dom nodes. */
      [@key "layout"]
      layout: LayoutTreeSnapshot.t, /* The nodes in the layout tree. */
      [@key "textBoxes"]
      textBoxes: TextBoxSnapshot.t, /* The post-layout inline text nodes. */
      [@yojson.option] [@key "scrollOffsetX"]
      scrollOffsetX: option(float), /* Horizontal scroll offset. */
      [@yojson.option] [@key "scrollOffsetY"]
      scrollOffsetY: option(float), /* Vertical scroll offset. */
      [@yojson.option] [@key "contentWidth"]
      contentWidth: option(float), /* Document content width. */
      [@yojson.option] [@key "contentHeight"]
      contentHeight: option(float) /* Document content height. */,
    };
  }
  and NodeTreeSnapshot: {
    /* Table containing nodes. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "parentIndex"]
      parentIndex: option(list(float)), /* Parent node index. */
      [@yojson.option] [@key "nodeType"]
      nodeType: option(list(float)), /* `Node`'s nodeType. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(RareStringData.t), /* Type of the shadow root the `Node` is in. String values are equal to the `ShadowRootType` enum. */
      [@yojson.option] [@key "nodeName"]
      nodeName: option(list(StringIndex.t)), /* `Node`'s nodeName. */
      [@yojson.option] [@key "nodeValue"]
      nodeValue: option(list(StringIndex.t)), /* `Node`'s nodeValue. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(list(DOM.BackendNodeId.t)), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(ArrayOfStrings.t)), /* Attributes of an `Element` node. Flatten name, value pairs. */
      [@yojson.option] [@key "textValue"]
      textValue: option(RareStringData.t), /* Only set for textarea elements, contains the text value. */
      [@yojson.option] [@key "inputValue"]
      inputValue: option(RareStringData.t), /* Only set for input elements, contains the input's associated text value. */
      [@yojson.option] [@key "inputChecked"]
      inputChecked: option(RareBooleanData.t), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
      [@yojson.option] [@key "optionSelected"]
      optionSelected: option(RareBooleanData.t), /* Only set for option elements, indicates if the element has been selected */
      [@yojson.option] [@key "contentDocumentIndex"]
      contentDocumentIndex: option(RareIntegerData.t), /* The index of the document in the list of the snapshot documents. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(RareStringData.t), /* Type of a pseudo element node. */
      [@yojson.option] [@key "isClickable"]
      isClickable: option(RareBooleanData.t), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
      [@yojson.option] [@key "currentSourceURL"]
      currentSourceURL: option(RareStringData.t), /* The selected url for nodes with a srcset attribute. */
      [@yojson.option] [@key "originURL"]
      originURL: option(RareStringData.t) /* The url of the script (if any) that generates this node. */,
    };
  } = {
    /* Table containing nodes. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "parentIndex"]
      parentIndex: option(list(float)), /* Parent node index. */
      [@yojson.option] [@key "nodeType"]
      nodeType: option(list(float)), /* `Node`'s nodeType. */
      [@yojson.option] [@key "shadowRootType"]
      shadowRootType: option(RareStringData.t), /* Type of the shadow root the `Node` is in. String values are equal to the `ShadowRootType` enum. */
      [@yojson.option] [@key "nodeName"]
      nodeName: option(list(StringIndex.t)), /* `Node`'s nodeName. */
      [@yojson.option] [@key "nodeValue"]
      nodeValue: option(list(StringIndex.t)), /* `Node`'s nodeValue. */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(list(DOM.BackendNodeId.t)), /* `Node`'s id, corresponds to DOM.Node.backendNodeId. */
      [@yojson.option] [@key "attributes"]
      attributes: option(list(ArrayOfStrings.t)), /* Attributes of an `Element` node. Flatten name, value pairs. */
      [@yojson.option] [@key "textValue"]
      textValue: option(RareStringData.t), /* Only set for textarea elements, contains the text value. */
      [@yojson.option] [@key "inputValue"]
      inputValue: option(RareStringData.t), /* Only set for input elements, contains the input's associated text value. */
      [@yojson.option] [@key "inputChecked"]
      inputChecked: option(RareBooleanData.t), /* Only set for radio and checkbox input elements, indicates if the element has been checked */
      [@yojson.option] [@key "optionSelected"]
      optionSelected: option(RareBooleanData.t), /* Only set for option elements, indicates if the element has been selected */
      [@yojson.option] [@key "contentDocumentIndex"]
      contentDocumentIndex: option(RareIntegerData.t), /* The index of the document in the list of the snapshot documents. */
      [@yojson.option] [@key "pseudoType"]
      pseudoType: option(RareStringData.t), /* Type of a pseudo element node. */
      [@yojson.option] [@key "isClickable"]
      isClickable: option(RareBooleanData.t), /* Whether this DOM node responds to mouse clicks. This includes nodes that have had click
event listeners attached via JavaScript as well as anchor tags that naturally navigate when
clicked. */
      [@yojson.option] [@key "currentSourceURL"]
      currentSourceURL: option(RareStringData.t), /* The selected url for nodes with a srcset attribute. */
      [@yojson.option] [@key "originURL"]
      originURL: option(RareStringData.t) /* The url of the script (if any) that generates this node. */,
    };
  }
  and LayoutTreeSnapshot: {
    /* Table of details of an element in the DOM tree with a LayoutObject. */
    [@deriving yojson]
    type t = {
      [@key "nodeIndex"]
      nodeIndex: list(float), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
      [@key "styles"]
      styles: list(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
      [@key "bounds"]
      bounds: list(Rectangle.t), /* The absolute position bounding box. */
      [@key "text"]
      text: list(StringIndex.t), /* Contents of the LayoutText, if any. */
      [@key "stackingContexts"]
      stackingContexts: RareBooleanData.t, /* Stacking context information. */
      [@yojson.option] [@key "paintOrders"]
      paintOrders: option(list(float)), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
      [@yojson.option] [@key "offsetRects"]
      offsetRects: option(list(Rectangle.t)), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "scrollRects"]
      scrollRects: option(list(Rectangle.t)), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "clientRects"]
      clientRects: option(list(Rectangle.t)), /* The client rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "blendedBackgroundColors"]
      blendedBackgroundColors: option(list(StringIndex.t)), /* The list of background colors that are blended with colors of overlapping elements. */
      [@yojson.option] [@key "textColorOpacities"]
      textColorOpacities: option(list(float)) /* The list of computed text opacities. */,
    };
  } = {
    /* Table of details of an element in the DOM tree with a LayoutObject. */
    [@deriving yojson]
    type t = {
      [@key "nodeIndex"]
      nodeIndex: list(float), /* Index of the corresponding node in the `NodeTreeSnapshot` array returned by `captureSnapshot`. */
      [@key "styles"]
      styles: list(ArrayOfStrings.t), /* Array of indexes specifying computed style strings, filtered according to the `computedStyles` parameter passed to `captureSnapshot`. */
      [@key "bounds"]
      bounds: list(Rectangle.t), /* The absolute position bounding box. */
      [@key "text"]
      text: list(StringIndex.t), /* Contents of the LayoutText, if any. */
      [@key "stackingContexts"]
      stackingContexts: RareBooleanData.t, /* Stacking context information. */
      [@yojson.option] [@key "paintOrders"]
      paintOrders: option(list(float)), /* Global paint order index, which is determined by the stacking order of the nodes. Nodes
that are painted together will have the same index. Only provided if includePaintOrder in
captureSnapshot was true. */
      [@yojson.option] [@key "offsetRects"]
      offsetRects: option(list(Rectangle.t)), /* The offset rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "scrollRects"]
      scrollRects: option(list(Rectangle.t)), /* The scroll rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "clientRects"]
      clientRects: option(list(Rectangle.t)), /* The client rect of nodes. Only available when includeDOMRects is set to true */
      [@yojson.option] [@key "blendedBackgroundColors"]
      blendedBackgroundColors: option(list(StringIndex.t)), /* The list of background colors that are blended with colors of overlapping elements. */
      [@yojson.option] [@key "textColorOpacities"]
      textColorOpacities: option(list(float)) /* The list of computed text opacities. */,
    };
  }
  and TextBoxSnapshot: {
    /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
       stable and may change between versions. */
    [@deriving yojson]
    type t = {
      [@key "layoutIndex"]
      layoutIndex: list(float), /* Index of the layout tree node that owns this box collection. */
      [@key "bounds"]
      bounds: list(Rectangle.t), /* The absolute position bounding box. */
      [@key "start"]
      start: list(float), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
      [@key "length"]
      length: list(float) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
    };
  } = {
    /* Table of details of the post layout rendered text positions. The exact layout should not be regarded as
       stable and may change between versions. */
    [@deriving yojson]
    type t = {
      [@key "layoutIndex"]
      layoutIndex: list(float), /* Index of the layout tree node that owns this box collection. */
      [@key "bounds"]
      bounds: list(Rectangle.t), /* The absolute position bounding box. */
      [@key "start"]
      start: list(float), /* The starting index in characters, for this post layout textbox substring. Characters that
would be represented as a surrogate pair in UTF-16 have length 2. */
      [@key "length"]
      length: list(float) /* The number of characters in this post layout textbox substring. Characters that would be
represented as a surrogate pair in UTF-16 have length 2. */,
    };
  };
}
and DOMStorage: {
  module rec StorageId: {
    /* DOM Storage identifier. */
    [@deriving yojson]
    type t = {
      [@key "securityOrigin"]
      securityOrigin: string, /* Security origin for the storage. */
      [@key "isLocalStorage"]
      isLocalStorage: bool /* Whether the storage is local storage (not session storage). */,
    };
  }
  and Item: {
    /* DOM Storage item. */
    [@deriving yojson]
    type t = list(string);
  };
} = {
  module rec StorageId: {
    /* DOM Storage identifier. */
    [@deriving yojson]
    type t = {
      [@key "securityOrigin"]
      securityOrigin: string, /* Security origin for the storage. */
      [@key "isLocalStorage"]
      isLocalStorage: bool /* Whether the storage is local storage (not session storage). */,
    };
  } = {
    /* DOM Storage identifier. */
    [@deriving yojson]
    type t = {
      [@key "securityOrigin"]
      securityOrigin: string, /* Security origin for the storage. */
      [@key "isLocalStorage"]
      isLocalStorage: bool /* Whether the storage is local storage (not session storage). */,
    };
  }
  and Item: {
    /* DOM Storage item. */
    [@deriving yojson]
    type t = list(string);
  } = {
    /* DOM Storage item. */
    [@deriving yojson]
    type t = list(string);
  };
}
and Database: {
  module rec DatabaseId: {
    /* Unique identifier of Database object. */
    [@deriving yojson]
    type t = string;
  }
  and Database: {
    /* Database object. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: DatabaseId.t, /* Database ID. */
      [@key "domain"]
      domain: string, /* Database domain. */
      [@key "name"]
      name: string, /* Database name. */
      [@key "version"]
      version: string /* Database version. */,
    };
  }
  and Error: {
    /* Database error. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@key "code"]
      code: float /* Error code. */,
    };
  };
} = {
  module rec DatabaseId: {
    /* Unique identifier of Database object. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique identifier of Database object. */
    [@deriving yojson]
    type t = string;
  }
  and Database: {
    /* Database object. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: DatabaseId.t, /* Database ID. */
      [@key "domain"]
      domain: string, /* Database domain. */
      [@key "name"]
      name: string, /* Database name. */
      [@key "version"]
      version: string /* Database version. */,
    };
  } = {
    /* Database object. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: DatabaseId.t, /* Database ID. */
      [@key "domain"]
      domain: string, /* Database domain. */
      [@key "name"]
      name: string, /* Database name. */
      [@key "version"]
      version: string /* Database version. */,
    };
  }
  and Error: {
    /* Database error. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@key "code"]
      code: float /* Error code. */,
    };
  } = {
    /* Database error. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@key "code"]
      code: float /* Error code. */,
    };
  };
}
and Emulation: {
  module rec ScreenOrientation: {
    type _screenorientation_type = [
      | `portraitPrimary
      | `portraitSecondary
      | `landscapePrimary
      | `landscapeSecondary
    ];
    let _screenorientation_type_of_yojson:
      Yojson.Basic.t => _screenorientation_type;
    let yojson_of__screenorientation_type:
      _screenorientation_type => Yojson.Basic.t;
    /* Screen orientation. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _screenorientation_type, /* Orientation type. */
      [@key "angle"]
      angle: float /* Orientation angle. */,
    };
  }
  and DisplayFeature: {
    type _displayfeature_orientation = [ | `vertical | `horizontal];
    let _displayfeature_orientation_of_yojson:
      Yojson.Basic.t => _displayfeature_orientation;
    let yojson_of__displayfeature_orientation:
      _displayfeature_orientation => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "orientation"]
      orientation: _displayfeature_orientation, /* Orientation of a display feature in relation to screen */
      [@key "offset"]
      offset: float, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
      [@key "maskLength"]
      maskLength: float /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
    };
  }
  and MediaFeature: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and VirtualTimePolicy: {
    type _virtualtimepolicy = [
      | `advance
      | `pause
      | `pauseIfNetworkFetchesPending
    ];
    let _virtualtimepolicy_of_yojson: Yojson.Basic.t => _virtualtimepolicy;
    let yojson_of__virtualtimepolicy: _virtualtimepolicy => Yojson.Basic.t;
    /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
       allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
       pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
       resource fetches. */
    [@deriving yojson]
    type t = _virtualtimepolicy;
  }
  and UserAgentBrandVersion: {
    /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
    [@deriving yojson]
    type t = {
      [@key "brand"]
      brand: string, /* No description provided */
      [@key "version"]
      version: string /* No description provided */,
    };
  }
  and UserAgentMetadata: {
    /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
       Missing optional values will be filled in by the target with what it would normally use. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "brands"]
      brands: option(list(UserAgentBrandVersion.t)), /* No description provided */
      [@yojson.option] [@key "fullVersionList"]
      fullVersionList: option(list(UserAgentBrandVersion.t)), /* No description provided */
      [@yojson.option] [@key "fullVersion"]
      fullVersion: option(string), /* No description provided */
      [@key "platform"]
      platform: string, /* No description provided */
      [@key "platformVersion"]
      platformVersion: string, /* No description provided */
      [@key "architecture"]
      architecture: string, /* No description provided */
      [@key "model"]
      model: string, /* No description provided */
      [@key "mobile"]
      mobile: bool /* No description provided */,
    };
  }
  and DisabledImageType: {
    type _disabledimagetype = [ | `avif | `jxl | `webp];
    let _disabledimagetype_of_yojson: Yojson.Basic.t => _disabledimagetype;
    let yojson_of__disabledimagetype: _disabledimagetype => Yojson.Basic.t;
    /* Enum of image types that can be disabled. */
    [@deriving yojson]
    type t = _disabledimagetype;
  };
} = {
  module rec ScreenOrientation: {
    type _screenorientation_type = [
      | `portraitPrimary
      | `portraitSecondary
      | `landscapePrimary
      | `landscapeSecondary
    ];
    let _screenorientation_type_of_yojson:
      Yojson.Basic.t => _screenorientation_type;
    let yojson_of__screenorientation_type:
      _screenorientation_type => Yojson.Basic.t;
    /* Screen orientation. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _screenorientation_type, /* Orientation type. */
      [@key "angle"]
      angle: float /* Orientation angle. */,
    };
  } = {
    type _screenorientation_type = [
      | `portraitPrimary
      | `portraitSecondary
      | `landscapePrimary
      | `landscapeSecondary
    ];
    let _screenorientation_type_of_yojson =
      fun
      | `String("portraitPrimary") => `portraitPrimary
      | `String("portraitSecondary") => `portraitSecondary
      | `String("landscapePrimary") => `landscapePrimary
      | `String("landscapeSecondary") => `landscapeSecondary
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__screenorientation_type =
      fun
      | `portraitPrimary => `String("portraitPrimary")
      | `portraitSecondary => `String("portraitSecondary")
      | `landscapePrimary => `String("landscapePrimary")
      | `landscapeSecondary => `String("landscapeSecondary");
    /* Screen orientation. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _screenorientation_type, /* Orientation type. */
      [@key "angle"]
      angle: float /* Orientation angle. */,
    };
  }
  and DisplayFeature: {
    type _displayfeature_orientation = [ | `vertical | `horizontal];
    let _displayfeature_orientation_of_yojson:
      Yojson.Basic.t => _displayfeature_orientation;
    let yojson_of__displayfeature_orientation:
      _displayfeature_orientation => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "orientation"]
      orientation: _displayfeature_orientation, /* Orientation of a display feature in relation to screen */
      [@key "offset"]
      offset: float, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
      [@key "maskLength"]
      maskLength: float /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
    };
  } = {
    type _displayfeature_orientation = [ | `vertical | `horizontal];
    let _displayfeature_orientation_of_yojson =
      fun
      | `String("vertical") => `vertical
      | `String("horizontal") => `horizontal
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__displayfeature_orientation =
      fun
      | `vertical => `String("vertical")
      | `horizontal => `String("horizontal");
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "orientation"]
      orientation: _displayfeature_orientation, /* Orientation of a display feature in relation to screen */
      [@key "offset"]
      offset: float, /* The offset from the screen origin in either the x (for vertical
orientation) or y (for horizontal orientation) direction. */
      [@key "maskLength"]
      maskLength: float /* A display feature may mask content such that it is not physically
displayed - this length along with the offset describes this area.
A display feature that only splits content will have a 0 mask_length. */,
    };
  }
  and MediaFeature: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and VirtualTimePolicy: {
    type _virtualtimepolicy = [
      | `advance
      | `pause
      | `pauseIfNetworkFetchesPending
    ];
    let _virtualtimepolicy_of_yojson: Yojson.Basic.t => _virtualtimepolicy;
    let yojson_of__virtualtimepolicy: _virtualtimepolicy => Yojson.Basic.t;
    /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
       allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
       pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
       resource fetches. */
    [@deriving yojson]
    type t = _virtualtimepolicy;
  } = {
    type _virtualtimepolicy = [
      | `advance
      | `pause
      | `pauseIfNetworkFetchesPending
    ];
    let _virtualtimepolicy_of_yojson =
      fun
      | `String("advance") => `advance
      | `String("pause") => `pause
      | `String("pauseIfNetworkFetchesPending") => `pauseIfNetworkFetchesPending
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__virtualtimepolicy =
      fun
      | `advance => `String("advance")
      | `pause => `String("pause")
      | `pauseIfNetworkFetchesPending =>
        `String("pauseIfNetworkFetchesPending");
    /* advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to
       allow the next delayed task (if any) to run; pause: The virtual time base may not advance;
       pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending
       resource fetches. */
    [@deriving yojson]
    type t = _virtualtimepolicy;
  }
  and UserAgentBrandVersion: {
    /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
    [@deriving yojson]
    type t = {
      [@key "brand"]
      brand: string, /* No description provided */
      [@key "version"]
      version: string /* No description provided */,
    };
  } = {
    /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints */
    [@deriving yojson]
    type t = {
      [@key "brand"]
      brand: string, /* No description provided */
      [@key "version"]
      version: string /* No description provided */,
    };
  }
  and UserAgentMetadata: {
    /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
       Missing optional values will be filled in by the target with what it would normally use. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "brands"]
      brands: option(list(UserAgentBrandVersion.t)), /* No description provided */
      [@yojson.option] [@key "fullVersionList"]
      fullVersionList: option(list(UserAgentBrandVersion.t)), /* No description provided */
      [@yojson.option] [@key "fullVersion"]
      fullVersion: option(string), /* No description provided */
      [@key "platform"]
      platform: string, /* No description provided */
      [@key "platformVersion"]
      platformVersion: string, /* No description provided */
      [@key "architecture"]
      architecture: string, /* No description provided */
      [@key "model"]
      model: string, /* No description provided */
      [@key "mobile"]
      mobile: bool /* No description provided */,
    };
  } = {
    /* Used to specify User Agent Cient Hints to emulate. See https://wicg.github.io/ua-client-hints
       Missing optional values will be filled in by the target with what it would normally use. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "brands"]
      brands: option(list(UserAgentBrandVersion.t)), /* No description provided */
      [@yojson.option] [@key "fullVersionList"]
      fullVersionList: option(list(UserAgentBrandVersion.t)), /* No description provided */
      [@yojson.option] [@key "fullVersion"]
      fullVersion: option(string), /* No description provided */
      [@key "platform"]
      platform: string, /* No description provided */
      [@key "platformVersion"]
      platformVersion: string, /* No description provided */
      [@key "architecture"]
      architecture: string, /* No description provided */
      [@key "model"]
      model: string, /* No description provided */
      [@key "mobile"]
      mobile: bool /* No description provided */,
    };
  }
  and DisabledImageType: {
    type _disabledimagetype = [ | `avif | `jxl | `webp];
    let _disabledimagetype_of_yojson: Yojson.Basic.t => _disabledimagetype;
    let yojson_of__disabledimagetype: _disabledimagetype => Yojson.Basic.t;
    /* Enum of image types that can be disabled. */
    [@deriving yojson]
    type t = _disabledimagetype;
  } = {
    type _disabledimagetype = [ | `avif | `jxl | `webp];
    let _disabledimagetype_of_yojson =
      fun
      | `String("avif") => `avif
      | `String("jxl") => `jxl
      | `String("webp") => `webp
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__disabledimagetype =
      fun
      | `avif => `String("avif")
      | `jxl => `String("jxl")
      | `webp => `String("webp");
    /* Enum of image types that can be disabled. */
    [@deriving yojson]
    type t = _disabledimagetype;
  };
}
and HeadlessExperimental: {
  module rec ScreenshotParams: {
    type _screenshotparams_format = [ | `jpeg | `png];
    let _screenshotparams_format_of_yojson:
      Yojson.Basic.t => _screenshotparams_format;
    let yojson_of__screenshotparams_format:
      _screenshotparams_format => Yojson.Basic.t;
    /* Encoding options for a screenshot. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "format"]
      format: option(_screenshotparams_format), /* Image compression format (defaults to png). */
      [@yojson.option] [@key "quality"]
      quality: option(float) /* Compression quality from range [0..100] (jpeg only). */,
    };
  };
} = {
  module rec ScreenshotParams: {
    type _screenshotparams_format = [ | `jpeg | `png];
    let _screenshotparams_format_of_yojson:
      Yojson.Basic.t => _screenshotparams_format;
    let yojson_of__screenshotparams_format:
      _screenshotparams_format => Yojson.Basic.t;
    /* Encoding options for a screenshot. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "format"]
      format: option(_screenshotparams_format), /* Image compression format (defaults to png). */
      [@yojson.option] [@key "quality"]
      quality: option(float) /* Compression quality from range [0..100] (jpeg only). */,
    };
  } = {
    type _screenshotparams_format = [ | `jpeg | `png];
    let _screenshotparams_format_of_yojson =
      fun
      | `String("jpeg") => `jpeg
      | `String("png") => `png
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__screenshotparams_format =
      fun
      | `jpeg => `String("jpeg")
      | `png => `String("png");
    /* Encoding options for a screenshot. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "format"]
      format: option(_screenshotparams_format), /* Image compression format (defaults to png). */
      [@yojson.option] [@key "quality"]
      quality: option(float) /* Compression quality from range [0..100] (jpeg only). */,
    };
  };
}
and IO: {
  module rec StreamHandle: {
    /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
       `&lt;uuid&gt` is an UUID of a Blob. */
    [@deriving yojson]
    type t = string;
  };
} = {
  module rec StreamHandle: {
    /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
       `&lt;uuid&gt` is an UUID of a Blob. */
    [@deriving yojson]
    type t = string;
  } = {
    /* This is either obtained from another method or specified as `blob:&lt;uuid&gt;` where
       `&lt;uuid&gt` is an UUID of a Blob. */
    [@deriving yojson]
    type t = string;
  };
}
and IndexedDB: {
  module rec DatabaseWithObjectStores: {
    /* Database with an array of object stores. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Database name. */
      [@key "version"]
      version: float, /* Database version (type is not 'integer', as the standard
requires the version number to be 'unsigned long long') */
      [@key "objectStores"]
      objectStores: list(ObjectStore.t) /* Object stores in this database. */,
    };
  }
  and ObjectStore: {
    /* Object store. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Object store name. */
      [@key "keyPath"]
      keyPath: KeyPath.t, /* Object store key path. */
      [@key "autoIncrement"]
      autoIncrement: bool, /* If true, object store has auto increment flag set. */
      [@key "indexes"]
      indexes: list(ObjectStoreIndex.t) /* Indexes in this object store. */,
    };
  }
  and ObjectStoreIndex: {
    /* Object store index. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Index name. */
      [@key "keyPath"]
      keyPath: KeyPath.t, /* Index key path. */
      [@key "unique"]
      unique: bool, /* If true, index is unique. */
      [@key "multiEntry"]
      multiEntry: bool /* If true, index allows multiple entries for a key. */,
    };
  }
  and Key: {
    type _key_type = [ | `number | `string | `date | `array];
    let _key_type_of_yojson: Yojson.Basic.t => _key_type;
    let yojson_of__key_type: _key_type => Yojson.Basic.t;
    /* Key. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _key_type, /* Key type. */
      [@yojson.option] [@key "number"]
      number: option(float), /* Number value. */
      [@yojson.option] [@key "string"]
      string: option(string), /* String value. */
      [@yojson.option] [@key "date"]
      date: option(float), /* Date value. */
      [@yojson.option] [@key "array"]
      array: option(list(Key.t)) /* Array value. */,
    };
  }
  and KeyRange: {
    /* Key range. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "lower"]
      lower: option(Key.t), /* Lower bound. */
      [@yojson.option] [@key "upper"]
      upper: option(Key.t), /* Upper bound. */
      [@key "lowerOpen"]
      lowerOpen: bool, /* If true lower bound is open. */
      [@key "upperOpen"]
      upperOpen: bool /* If true upper bound is open. */,
    };
  }
  and DataEntry: {
    /* Data entry. */
    [@deriving yojson]
    type t = {
      [@key "key"]
      key: Runtime.RemoteObject.t, /* Key object. */
      [@key "primaryKey"]
      primaryKey: Runtime.RemoteObject.t, /* Primary key object. */
      [@key "value"]
      value: Runtime.RemoteObject.t /* Value object. */,
    };
  }
  and KeyPath: {
    type _keypath_type = [ | `null | `string | `array];
    let _keypath_type_of_yojson: Yojson.Basic.t => _keypath_type;
    let yojson_of__keypath_type: _keypath_type => Yojson.Basic.t;
    /* Key path. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _keypath_type, /* Key path type. */
      [@yojson.option] [@key "string"]
      string: option(string), /* String value. */
      [@yojson.option] [@key "array"]
      array: option(list(string)) /* Array value. */,
    };
  };
} = {
  module rec DatabaseWithObjectStores: {
    /* Database with an array of object stores. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Database name. */
      [@key "version"]
      version: float, /* Database version (type is not 'integer', as the standard
requires the version number to be 'unsigned long long') */
      [@key "objectStores"]
      objectStores: list(ObjectStore.t) /* Object stores in this database. */,
    };
  } = {
    /* Database with an array of object stores. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Database name. */
      [@key "version"]
      version: float, /* Database version (type is not 'integer', as the standard
requires the version number to be 'unsigned long long') */
      [@key "objectStores"]
      objectStores: list(ObjectStore.t) /* Object stores in this database. */,
    };
  }
  and ObjectStore: {
    /* Object store. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Object store name. */
      [@key "keyPath"]
      keyPath: KeyPath.t, /* Object store key path. */
      [@key "autoIncrement"]
      autoIncrement: bool, /* If true, object store has auto increment flag set. */
      [@key "indexes"]
      indexes: list(ObjectStoreIndex.t) /* Indexes in this object store. */,
    };
  } = {
    /* Object store. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Object store name. */
      [@key "keyPath"]
      keyPath: KeyPath.t, /* Object store key path. */
      [@key "autoIncrement"]
      autoIncrement: bool, /* If true, object store has auto increment flag set. */
      [@key "indexes"]
      indexes: list(ObjectStoreIndex.t) /* Indexes in this object store. */,
    };
  }
  and ObjectStoreIndex: {
    /* Object store index. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Index name. */
      [@key "keyPath"]
      keyPath: KeyPath.t, /* Index key path. */
      [@key "unique"]
      unique: bool, /* If true, index is unique. */
      [@key "multiEntry"]
      multiEntry: bool /* If true, index allows multiple entries for a key. */,
    };
  } = {
    /* Object store index. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Index name. */
      [@key "keyPath"]
      keyPath: KeyPath.t, /* Index key path. */
      [@key "unique"]
      unique: bool, /* If true, index is unique. */
      [@key "multiEntry"]
      multiEntry: bool /* If true, index allows multiple entries for a key. */,
    };
  }
  and Key: {
    type _key_type = [ | `number | `string | `date | `array];
    let _key_type_of_yojson: Yojson.Basic.t => _key_type;
    let yojson_of__key_type: _key_type => Yojson.Basic.t;
    /* Key. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _key_type, /* Key type. */
      [@yojson.option] [@key "number"]
      number: option(float), /* Number value. */
      [@yojson.option] [@key "string"]
      string: option(string), /* String value. */
      [@yojson.option] [@key "date"]
      date: option(float), /* Date value. */
      [@yojson.option] [@key "array"]
      array: option(list(Key.t)) /* Array value. */,
    };
  } = {
    type _key_type = [ | `number | `string | `date | `array];
    let _key_type_of_yojson =
      fun
      | `String("number") => `number
      | `String("string") => `string
      | `String("date") => `date
      | `String("array") => `array
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__key_type =
      fun
      | `number => `String("number")
      | `string => `String("string")
      | `date => `String("date")
      | `array => `String("array");
    /* Key. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _key_type, /* Key type. */
      [@yojson.option] [@key "number"]
      number: option(float), /* Number value. */
      [@yojson.option] [@key "string"]
      string: option(string), /* String value. */
      [@yojson.option] [@key "date"]
      date: option(float), /* Date value. */
      [@yojson.option] [@key "array"]
      array: option(list(Key.t)) /* Array value. */,
    };
  }
  and KeyRange: {
    /* Key range. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "lower"]
      lower: option(Key.t), /* Lower bound. */
      [@yojson.option] [@key "upper"]
      upper: option(Key.t), /* Upper bound. */
      [@key "lowerOpen"]
      lowerOpen: bool, /* If true lower bound is open. */
      [@key "upperOpen"]
      upperOpen: bool /* If true upper bound is open. */,
    };
  } = {
    /* Key range. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "lower"]
      lower: option(Key.t), /* Lower bound. */
      [@yojson.option] [@key "upper"]
      upper: option(Key.t), /* Upper bound. */
      [@key "lowerOpen"]
      lowerOpen: bool, /* If true lower bound is open. */
      [@key "upperOpen"]
      upperOpen: bool /* If true upper bound is open. */,
    };
  }
  and DataEntry: {
    /* Data entry. */
    [@deriving yojson]
    type t = {
      [@key "key"]
      key: Runtime.RemoteObject.t, /* Key object. */
      [@key "primaryKey"]
      primaryKey: Runtime.RemoteObject.t, /* Primary key object. */
      [@key "value"]
      value: Runtime.RemoteObject.t /* Value object. */,
    };
  } = {
    /* Data entry. */
    [@deriving yojson]
    type t = {
      [@key "key"]
      key: Runtime.RemoteObject.t, /* Key object. */
      [@key "primaryKey"]
      primaryKey: Runtime.RemoteObject.t, /* Primary key object. */
      [@key "value"]
      value: Runtime.RemoteObject.t /* Value object. */,
    };
  }
  and KeyPath: {
    type _keypath_type = [ | `null | `string | `array];
    let _keypath_type_of_yojson: Yojson.Basic.t => _keypath_type;
    let yojson_of__keypath_type: _keypath_type => Yojson.Basic.t;
    /* Key path. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _keypath_type, /* Key path type. */
      [@yojson.option] [@key "string"]
      string: option(string), /* String value. */
      [@yojson.option] [@key "array"]
      array: option(list(string)) /* Array value. */,
    };
  } = {
    type _keypath_type = [ | `null | `string | `array];
    let _keypath_type_of_yojson =
      fun
      | `String("null") => `null
      | `String("string") => `string
      | `String("array") => `array
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__keypath_type =
      fun
      | `null => `String("null")
      | `string => `String("string")
      | `array => `String("array");
    /* Key path. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _keypath_type, /* Key path type. */
      [@yojson.option] [@key "string"]
      string: option(string), /* String value. */
      [@yojson.option] [@key "array"]
      array: option(list(string)) /* Array value. */,
    };
  };
}
and Input: {
  module rec TouchPoint: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
      [@key "y"]
      y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
      [@yojson.option] [@key "radiusX"]
      radiusX: option(float), /* X radius of the touch area (default: 1.0). */
      [@yojson.option] [@key "radiusY"]
      radiusY: option(float), /* Y radius of the touch area (default: 1.0). */
      [@yojson.option] [@key "rotationAngle"]
      rotationAngle: option(float), /* Rotation angle (default: 0.0). */
      [@yojson.option] [@key "force"]
      force: option(float), /* Force (default: 1.0). */
      [@yojson.option] [@key "tangentialPressure"]
      tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
      [@yojson.option] [@key "tiltX"]
      tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
      [@yojson.option] [@key "tiltY"]
      tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
      [@yojson.option] [@key "twist"]
      twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
      [@yojson.option] [@key "id"]
      id: option(float) /* Identifier used to track touch sources between events, must be unique within an event. */,
    };
  }
  and GestureSourceType: {
    type _gesturesourcetype = [ | `default | `touch | `mouse];
    let _gesturesourcetype_of_yojson: Yojson.Basic.t => _gesturesourcetype;
    let yojson_of__gesturesourcetype: _gesturesourcetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _gesturesourcetype;
  }
  and MouseButton: {
    type _mousebutton = [
      | `none
      | `left
      | `middle
      | `right
      | `back
      | `forward
    ];
    let _mousebutton_of_yojson: Yojson.Basic.t => _mousebutton;
    let yojson_of__mousebutton: _mousebutton => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _mousebutton;
  }
  and TimeSinceEpoch: {
    /* UTC time in seconds, counted from January 1, 1970. */
    [@deriving yojson]
    type t = float;
  }
  and DragDataItem: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "mimeType"]
      mimeType: string, /* Mime type of the dragged data. */
      [@key "data"]
      data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
      [@yojson.option] [@key "title"]
      title: option(string), /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string) /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
    };
  }
  and DragData: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "items"]
      items: list(DragDataItem.t), /* No description provided */
      [@yojson.option] [@key "files"]
      files: option(list(string)), /* List of filenames that should be included when dropping */
      [@key "dragOperationsMask"]
      dragOperationsMask: float /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
    };
  };
} = {
  module rec TouchPoint: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
      [@key "y"]
      y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
      [@yojson.option] [@key "radiusX"]
      radiusX: option(float), /* X radius of the touch area (default: 1.0). */
      [@yojson.option] [@key "radiusY"]
      radiusY: option(float), /* Y radius of the touch area (default: 1.0). */
      [@yojson.option] [@key "rotationAngle"]
      rotationAngle: option(float), /* Rotation angle (default: 0.0). */
      [@yojson.option] [@key "force"]
      force: option(float), /* Force (default: 1.0). */
      [@yojson.option] [@key "tangentialPressure"]
      tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
      [@yojson.option] [@key "tiltX"]
      tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
      [@yojson.option] [@key "tiltY"]
      tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
      [@yojson.option] [@key "twist"]
      twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
      [@yojson.option] [@key "id"]
      id: option(float) /* Identifier used to track touch sources between events, must be unique within an event. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X coordinate of the event relative to the main frame's viewport in CSS pixels. */
      [@key "y"]
      y: float, /* Y coordinate of the event relative to the main frame's viewport in CSS pixels. 0 refers to
the top of the viewport and Y increases as it proceeds towards the bottom of the viewport. */
      [@yojson.option] [@key "radiusX"]
      radiusX: option(float), /* X radius of the touch area (default: 1.0). */
      [@yojson.option] [@key "radiusY"]
      radiusY: option(float), /* Y radius of the touch area (default: 1.0). */
      [@yojson.option] [@key "rotationAngle"]
      rotationAngle: option(float), /* Rotation angle (default: 0.0). */
      [@yojson.option] [@key "force"]
      force: option(float), /* Force (default: 1.0). */
      [@yojson.option] [@key "tangentialPressure"]
      tangentialPressure: option(float), /* The normalized tangential pressure, which has a range of [-1,1] (default: 0). */
      [@yojson.option] [@key "tiltX"]
      tiltX: option(float), /* The plane angle between the Y-Z plane and the plane containing both the stylus axis and the Y axis, in degrees of the range [-90,90], a positive tiltX is to the right (default: 0) */
      [@yojson.option] [@key "tiltY"]
      tiltY: option(float), /* The plane angle between the X-Z plane and the plane containing both the stylus axis and the X axis, in degrees of the range [-90,90], a positive tiltY is towards the user (default: 0). */
      [@yojson.option] [@key "twist"]
      twist: option(float), /* The clockwise rotation of a pen stylus around its own major axis, in degrees in the range [0,359] (default: 0). */
      [@yojson.option] [@key "id"]
      id: option(float) /* Identifier used to track touch sources between events, must be unique within an event. */,
    };
  }
  and GestureSourceType: {
    type _gesturesourcetype = [ | `default | `touch | `mouse];
    let _gesturesourcetype_of_yojson: Yojson.Basic.t => _gesturesourcetype;
    let yojson_of__gesturesourcetype: _gesturesourcetype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _gesturesourcetype;
  } = {
    type _gesturesourcetype = [ | `default | `touch | `mouse];
    let _gesturesourcetype_of_yojson =
      fun
      | `String("default") => `default
      | `String("touch") => `touch
      | `String("mouse") => `mouse
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__gesturesourcetype =
      fun
      | `default => `String("default")
      | `touch => `String("touch")
      | `mouse => `String("mouse");
    /* No description provided */
    [@deriving yojson]
    type t = _gesturesourcetype;
  }
  and MouseButton: {
    type _mousebutton = [
      | `none
      | `left
      | `middle
      | `right
      | `back
      | `forward
    ];
    let _mousebutton_of_yojson: Yojson.Basic.t => _mousebutton;
    let yojson_of__mousebutton: _mousebutton => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _mousebutton;
  } = {
    type _mousebutton = [
      | `none
      | `left
      | `middle
      | `right
      | `back
      | `forward
    ];
    let _mousebutton_of_yojson =
      fun
      | `String("none") => `none
      | `String("left") => `left
      | `String("middle") => `middle
      | `String("right") => `right
      | `String("back") => `back
      | `String("forward") => `forward
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__mousebutton =
      fun
      | `none => `String("none")
      | `left => `String("left")
      | `middle => `String("middle")
      | `right => `String("right")
      | `back => `String("back")
      | `forward => `String("forward");
    /* No description provided */
    [@deriving yojson]
    type t = _mousebutton;
  }
  and TimeSinceEpoch: {
    /* UTC time in seconds, counted from January 1, 1970. */
    [@deriving yojson]
    type t = float;
  } = {
    /* UTC time in seconds, counted from January 1, 1970. */
    [@deriving yojson]
    type t = float;
  }
  and DragDataItem: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "mimeType"]
      mimeType: string, /* Mime type of the dragged data. */
      [@key "data"]
      data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
      [@yojson.option] [@key "title"]
      title: option(string), /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string) /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "mimeType"]
      mimeType: string, /* Mime type of the dragged data. */
      [@key "data"]
      data: string, /* Depending of the value of `mimeType`, it contains the dragged link,
text, HTML markup or any other data. */
      [@yojson.option] [@key "title"]
      title: option(string), /* Title associated with a link. Only valid when `mimeType` == "text/uri-list". */
      [@yojson.option] [@key "baseURL"]
      baseURL: option(string) /* Stores the base URL for the contained markup. Only valid when `mimeType`
== "text/html". */,
    };
  }
  and DragData: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "items"]
      items: list(DragDataItem.t), /* No description provided */
      [@yojson.option] [@key "files"]
      files: option(list(string)), /* List of filenames that should be included when dropping */
      [@key "dragOperationsMask"]
      dragOperationsMask: float /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "items"]
      items: list(DragDataItem.t), /* No description provided */
      [@yojson.option] [@key "files"]
      files: option(list(string)), /* List of filenames that should be included when dropping */
      [@key "dragOperationsMask"]
      dragOperationsMask: float /* Bit field representing allowed drag operations. Copy = 1, Link = 2, Move = 16 */,
    };
  };
}
and LayerTree: {
  module rec LayerId: {
    /* Unique Layer identifier. */
    [@deriving yojson]
    type t = string;
  }
  and SnapshotId: {
    /* Unique snapshot identifier. */
    [@deriving yojson]
    type t = string;
  }
  and ScrollRect: {
    type _scrollrect_type = [
      | `RepaintsOnScroll
      | `TouchEventHandler
      | `WheelEventHandler
    ];
    let _scrollrect_type_of_yojson: Yojson.Basic.t => _scrollrect_type;
    let yojson_of__scrollrect_type: _scrollrect_type => Yojson.Basic.t;
    /* Rectangle where scrolling happens on the main thread. */
    [@deriving yojson]
    type t = {
      [@key "rect"]
      rect: DOM.Rect.t, /* Rectangle itself. */
      [@key "type"]
      type_: _scrollrect_type /* Reason for rectangle to force scrolling on the main thread */,
    };
  }
  and StickyPositionConstraint: {
    /* Sticky position constraints. */
    [@deriving yojson]
    type t = {
      [@key "stickyBoxRect"]
      stickyBoxRect: DOM.Rect.t, /* Layout rectangle of the sticky element before being shifted */
      [@key "containingBlockRect"]
      containingBlockRect: DOM.Rect.t, /* Layout rectangle of the containing block of the sticky element */
      [@yojson.option] [@key "nearestLayerShiftingStickyBox"]
      nearestLayerShiftingStickyBox: option(LayerId.t), /* The nearest sticky layer that shifts the sticky box */
      [@yojson.option] [@key "nearestLayerShiftingContainingBlock"]
      nearestLayerShiftingContainingBlock: option(LayerId.t) /* The nearest sticky layer that shifts the containing block */,
    };
  }
  and PictureTile: {
    /* Serialized fragment of layer picture along with its offset within the layer. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* Offset from owning layer left boundary */
      [@key "y"]
      y: float, /* Offset from owning layer top boundary */
      [@key "picture"]
      picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
    };
  }
  and Layer: {
    /* Information about a compositing layer. */
    [@deriving yojson]
    type t = {
      [@key "layerId"]
      layerId: LayerId.t, /* The unique id for this layer. */
      [@yojson.option] [@key "parentLayerId"]
      parentLayerId: option(LayerId.t), /* The id of parent (not present for root). */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t), /* The backend id for the node associated with this layer. */
      [@key "offsetX"]
      offsetX: float, /* Offset from parent layer, X coordinate. */
      [@key "offsetY"]
      offsetY: float, /* Offset from parent layer, Y coordinate. */
      [@key "width"]
      width: float, /* Layer width. */
      [@key "height"]
      height: float, /* Layer height. */
      [@yojson.option] [@key "transform"]
      transform: option(list(float)), /* Transformation matrix for layer, default is identity matrix */
      [@yojson.option] [@key "anchorX"]
      anchorX: option(float), /* Transform anchor point X, absent if no transform specified */
      [@yojson.option] [@key "anchorY"]
      anchorY: option(float), /* Transform anchor point Y, absent if no transform specified */
      [@yojson.option] [@key "anchorZ"]
      anchorZ: option(float), /* Transform anchor point Z, absent if no transform specified */
      [@key "paintCount"]
      paintCount: float, /* Indicates how many time this layer has painted. */
      [@key "drawsContent"]
      drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
      [@yojson.option] [@key "invisible"]
      invisible: option(bool), /* Set if layer is not visible. */
      [@yojson.option] [@key "scrollRects"]
      scrollRects: option(list(ScrollRect.t)), /* Rectangles scrolling on main thread only. */
      [@yojson.option] [@key "stickyPositionConstraint"]
      stickyPositionConstraint: option(StickyPositionConstraint.t) /* Sticky position constraint information */,
    };
  }
  and PaintProfile: {
    /* Array of timings, one per paint step. */
    [@deriving yojson]
    type t = list(float);
  };
} = {
  module rec LayerId: {
    /* Unique Layer identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique Layer identifier. */
    [@deriving yojson]
    type t = string;
  }
  and SnapshotId: {
    /* Unique snapshot identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique snapshot identifier. */
    [@deriving yojson]
    type t = string;
  }
  and ScrollRect: {
    type _scrollrect_type = [
      | `RepaintsOnScroll
      | `TouchEventHandler
      | `WheelEventHandler
    ];
    let _scrollrect_type_of_yojson: Yojson.Basic.t => _scrollrect_type;
    let yojson_of__scrollrect_type: _scrollrect_type => Yojson.Basic.t;
    /* Rectangle where scrolling happens on the main thread. */
    [@deriving yojson]
    type t = {
      [@key "rect"]
      rect: DOM.Rect.t, /* Rectangle itself. */
      [@key "type"]
      type_: _scrollrect_type /* Reason for rectangle to force scrolling on the main thread */,
    };
  } = {
    type _scrollrect_type = [
      | `RepaintsOnScroll
      | `TouchEventHandler
      | `WheelEventHandler
    ];
    let _scrollrect_type_of_yojson =
      fun
      | `String("RepaintsOnScroll") => `RepaintsOnScroll
      | `String("TouchEventHandler") => `TouchEventHandler
      | `String("WheelEventHandler") => `WheelEventHandler
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__scrollrect_type =
      fun
      | `RepaintsOnScroll => `String("RepaintsOnScroll")
      | `TouchEventHandler => `String("TouchEventHandler")
      | `WheelEventHandler => `String("WheelEventHandler");
    /* Rectangle where scrolling happens on the main thread. */
    [@deriving yojson]
    type t = {
      [@key "rect"]
      rect: DOM.Rect.t, /* Rectangle itself. */
      [@key "type"]
      type_: _scrollrect_type /* Reason for rectangle to force scrolling on the main thread */,
    };
  }
  and StickyPositionConstraint: {
    /* Sticky position constraints. */
    [@deriving yojson]
    type t = {
      [@key "stickyBoxRect"]
      stickyBoxRect: DOM.Rect.t, /* Layout rectangle of the sticky element before being shifted */
      [@key "containingBlockRect"]
      containingBlockRect: DOM.Rect.t, /* Layout rectangle of the containing block of the sticky element */
      [@yojson.option] [@key "nearestLayerShiftingStickyBox"]
      nearestLayerShiftingStickyBox: option(LayerId.t), /* The nearest sticky layer that shifts the sticky box */
      [@yojson.option] [@key "nearestLayerShiftingContainingBlock"]
      nearestLayerShiftingContainingBlock: option(LayerId.t) /* The nearest sticky layer that shifts the containing block */,
    };
  } = {
    /* Sticky position constraints. */
    [@deriving yojson]
    type t = {
      [@key "stickyBoxRect"]
      stickyBoxRect: DOM.Rect.t, /* Layout rectangle of the sticky element before being shifted */
      [@key "containingBlockRect"]
      containingBlockRect: DOM.Rect.t, /* Layout rectangle of the containing block of the sticky element */
      [@yojson.option] [@key "nearestLayerShiftingStickyBox"]
      nearestLayerShiftingStickyBox: option(LayerId.t), /* The nearest sticky layer that shifts the sticky box */
      [@yojson.option] [@key "nearestLayerShiftingContainingBlock"]
      nearestLayerShiftingContainingBlock: option(LayerId.t) /* The nearest sticky layer that shifts the containing block */,
    };
  }
  and PictureTile: {
    /* Serialized fragment of layer picture along with its offset within the layer. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* Offset from owning layer left boundary */
      [@key "y"]
      y: float, /* Offset from owning layer top boundary */
      [@key "picture"]
      picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
    };
  } = {
    /* Serialized fragment of layer picture along with its offset within the layer. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* Offset from owning layer left boundary */
      [@key "y"]
      y: float, /* Offset from owning layer top boundary */
      [@key "picture"]
      picture: string /* Base64-encoded snapshot data. (Encoded as a base64 string when passed over JSON) */,
    };
  }
  and Layer: {
    /* Information about a compositing layer. */
    [@deriving yojson]
    type t = {
      [@key "layerId"]
      layerId: LayerId.t, /* The unique id for this layer. */
      [@yojson.option] [@key "parentLayerId"]
      parentLayerId: option(LayerId.t), /* The id of parent (not present for root). */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t), /* The backend id for the node associated with this layer. */
      [@key "offsetX"]
      offsetX: float, /* Offset from parent layer, X coordinate. */
      [@key "offsetY"]
      offsetY: float, /* Offset from parent layer, Y coordinate. */
      [@key "width"]
      width: float, /* Layer width. */
      [@key "height"]
      height: float, /* Layer height. */
      [@yojson.option] [@key "transform"]
      transform: option(list(float)), /* Transformation matrix for layer, default is identity matrix */
      [@yojson.option] [@key "anchorX"]
      anchorX: option(float), /* Transform anchor point X, absent if no transform specified */
      [@yojson.option] [@key "anchorY"]
      anchorY: option(float), /* Transform anchor point Y, absent if no transform specified */
      [@yojson.option] [@key "anchorZ"]
      anchorZ: option(float), /* Transform anchor point Z, absent if no transform specified */
      [@key "paintCount"]
      paintCount: float, /* Indicates how many time this layer has painted. */
      [@key "drawsContent"]
      drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
      [@yojson.option] [@key "invisible"]
      invisible: option(bool), /* Set if layer is not visible. */
      [@yojson.option] [@key "scrollRects"]
      scrollRects: option(list(ScrollRect.t)), /* Rectangles scrolling on main thread only. */
      [@yojson.option] [@key "stickyPositionConstraint"]
      stickyPositionConstraint: option(StickyPositionConstraint.t) /* Sticky position constraint information */,
    };
  } = {
    /* Information about a compositing layer. */
    [@deriving yojson]
    type t = {
      [@key "layerId"]
      layerId: LayerId.t, /* The unique id for this layer. */
      [@yojson.option] [@key "parentLayerId"]
      parentLayerId: option(LayerId.t), /* The id of parent (not present for root). */
      [@yojson.option] [@key "backendNodeId"]
      backendNodeId: option(DOM.BackendNodeId.t), /* The backend id for the node associated with this layer. */
      [@key "offsetX"]
      offsetX: float, /* Offset from parent layer, X coordinate. */
      [@key "offsetY"]
      offsetY: float, /* Offset from parent layer, Y coordinate. */
      [@key "width"]
      width: float, /* Layer width. */
      [@key "height"]
      height: float, /* Layer height. */
      [@yojson.option] [@key "transform"]
      transform: option(list(float)), /* Transformation matrix for layer, default is identity matrix */
      [@yojson.option] [@key "anchorX"]
      anchorX: option(float), /* Transform anchor point X, absent if no transform specified */
      [@yojson.option] [@key "anchorY"]
      anchorY: option(float), /* Transform anchor point Y, absent if no transform specified */
      [@yojson.option] [@key "anchorZ"]
      anchorZ: option(float), /* Transform anchor point Z, absent if no transform specified */
      [@key "paintCount"]
      paintCount: float, /* Indicates how many time this layer has painted. */
      [@key "drawsContent"]
      drawsContent: bool, /* Indicates whether this layer hosts any content, rather than being used for
transform/scrolling purposes only. */
      [@yojson.option] [@key "invisible"]
      invisible: option(bool), /* Set if layer is not visible. */
      [@yojson.option] [@key "scrollRects"]
      scrollRects: option(list(ScrollRect.t)), /* Rectangles scrolling on main thread only. */
      [@yojson.option] [@key "stickyPositionConstraint"]
      stickyPositionConstraint: option(StickyPositionConstraint.t) /* Sticky position constraint information */,
    };
  }
  and PaintProfile: {
    /* Array of timings, one per paint step. */
    [@deriving yojson]
    type t = list(float);
  } = {
    /* Array of timings, one per paint step. */
    [@deriving yojson]
    type t = list(float);
  };
}
and Log: {
  module rec LogEntry: {
    type _logentry_source = [
      | `xml
      | `javascript
      | `network
      | `storage
      | `appcache
      | `rendering
      | `security
      | `deprecation
      | `worker
      | `violation
      | `intervention
      | `recommendation
      | `other
    ];
    let _logentry_source_of_yojson: Yojson.Basic.t => _logentry_source;
    let yojson_of__logentry_source: _logentry_source => Yojson.Basic.t;
    type _logentry_level = [ | `verbose | `info | `warning | `error];
    let _logentry_level_of_yojson: Yojson.Basic.t => _logentry_level;
    let yojson_of__logentry_level: _logentry_level => Yojson.Basic.t;
    type _logentry_category = [ | `cors];
    let _logentry_category_of_yojson: Yojson.Basic.t => _logentry_category;
    let yojson_of__logentry_category: _logentry_category => Yojson.Basic.t;
    /* Log entry. */
    [@deriving yojson]
    type t = {
      [@key "source"]
      source: _logentry_source, /* Log entry source. */
      [@key "level"]
      level: _logentry_level, /* Log entry severity. */
      [@key "text"]
      text: string, /* Logged text. */
      [@yojson.option] [@key "category"]
      category: option(_logentry_category), /* No description provided */
      [@key "timestamp"]
      timestamp: Runtime.Timestamp.t, /* Timestamp when this entry was added. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the resource if known. */
      [@yojson.option] [@key "lineNumber"]
      lineNumber: option(float), /* Line number in the resource. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(Runtime.StackTrace.t), /* JavaScript stack trace. */
      [@yojson.option] [@key "networkRequestId"]
      networkRequestId: option(Network.RequestId.t), /* Identifier of the network request associated with this entry. */
      [@yojson.option] [@key "workerId"]
      workerId: option(string), /* Identifier of the worker associated with this entry. */
      [@yojson.option] [@key "args"]
      args: option(list(Runtime.RemoteObject.t)) /* Call arguments. */,
    };
  }
  and ViolationSetting: {
    type _violationsetting_name = [
      | `longTask
      | `longLayout
      | `blockedEvent
      | `blockedParser
      | `discouragedAPIUse
      | `handler
      | `recurringHandler
    ];
    let _violationsetting_name_of_yojson:
      Yojson.Basic.t => _violationsetting_name;
    let yojson_of__violationsetting_name:
      _violationsetting_name => Yojson.Basic.t;
    /* Violation configuration setting. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: _violationsetting_name, /* Violation type. */
      [@key "threshold"]
      threshold: float /* Time threshold to trigger upon. */,
    };
  };
} = {
  module rec LogEntry: {
    type _logentry_source = [
      | `xml
      | `javascript
      | `network
      | `storage
      | `appcache
      | `rendering
      | `security
      | `deprecation
      | `worker
      | `violation
      | `intervention
      | `recommendation
      | `other
    ];
    let _logentry_source_of_yojson: Yojson.Basic.t => _logentry_source;
    let yojson_of__logentry_source: _logentry_source => Yojson.Basic.t;
    type _logentry_level = [ | `verbose | `info | `warning | `error];
    let _logentry_level_of_yojson: Yojson.Basic.t => _logentry_level;
    let yojson_of__logentry_level: _logentry_level => Yojson.Basic.t;
    type _logentry_category = [ | `cors];
    let _logentry_category_of_yojson: Yojson.Basic.t => _logentry_category;
    let yojson_of__logentry_category: _logentry_category => Yojson.Basic.t;
    /* Log entry. */
    [@deriving yojson]
    type t = {
      [@key "source"]
      source: _logentry_source, /* Log entry source. */
      [@key "level"]
      level: _logentry_level, /* Log entry severity. */
      [@key "text"]
      text: string, /* Logged text. */
      [@yojson.option] [@key "category"]
      category: option(_logentry_category), /* No description provided */
      [@key "timestamp"]
      timestamp: Runtime.Timestamp.t, /* Timestamp when this entry was added. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the resource if known. */
      [@yojson.option] [@key "lineNumber"]
      lineNumber: option(float), /* Line number in the resource. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(Runtime.StackTrace.t), /* JavaScript stack trace. */
      [@yojson.option] [@key "networkRequestId"]
      networkRequestId: option(Network.RequestId.t), /* Identifier of the network request associated with this entry. */
      [@yojson.option] [@key "workerId"]
      workerId: option(string), /* Identifier of the worker associated with this entry. */
      [@yojson.option] [@key "args"]
      args: option(list(Runtime.RemoteObject.t)) /* Call arguments. */,
    };
  } = {
    type _logentry_source = [
      | `xml
      | `javascript
      | `network
      | `storage
      | `appcache
      | `rendering
      | `security
      | `deprecation
      | `worker
      | `violation
      | `intervention
      | `recommendation
      | `other
    ];
    let _logentry_source_of_yojson =
      fun
      | `String("xml") => `xml
      | `String("javascript") => `javascript
      | `String("network") => `network
      | `String("storage") => `storage
      | `String("appcache") => `appcache
      | `String("rendering") => `rendering
      | `String("security") => `security
      | `String("deprecation") => `deprecation
      | `String("worker") => `worker
      | `String("violation") => `violation
      | `String("intervention") => `intervention
      | `String("recommendation") => `recommendation
      | `String("other") => `other
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__logentry_source =
      fun
      | `xml => `String("xml")
      | `javascript => `String("javascript")
      | `network => `String("network")
      | `storage => `String("storage")
      | `appcache => `String("appcache")
      | `rendering => `String("rendering")
      | `security => `String("security")
      | `deprecation => `String("deprecation")
      | `worker => `String("worker")
      | `violation => `String("violation")
      | `intervention => `String("intervention")
      | `recommendation => `String("recommendation")
      | `other => `String("other");
    type _logentry_level = [ | `verbose | `info | `warning | `error];
    let _logentry_level_of_yojson =
      fun
      | `String("verbose") => `verbose
      | `String("info") => `info
      | `String("warning") => `warning
      | `String("error") => `error
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__logentry_level =
      fun
      | `verbose => `String("verbose")
      | `info => `String("info")
      | `warning => `String("warning")
      | `error => `String("error");
    type _logentry_category = [ | `cors];
    let _logentry_category_of_yojson =
      fun
      | `String("cors") => `cors
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__logentry_category =
      fun
      | `cors => `String("cors");
    /* Log entry. */
    [@deriving yojson]
    type t = {
      [@key "source"]
      source: _logentry_source, /* Log entry source. */
      [@key "level"]
      level: _logentry_level, /* Log entry severity. */
      [@key "text"]
      text: string, /* Logged text. */
      [@yojson.option] [@key "category"]
      category: option(_logentry_category), /* No description provided */
      [@key "timestamp"]
      timestamp: Runtime.Timestamp.t, /* Timestamp when this entry was added. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the resource if known. */
      [@yojson.option] [@key "lineNumber"]
      lineNumber: option(float), /* Line number in the resource. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(Runtime.StackTrace.t), /* JavaScript stack trace. */
      [@yojson.option] [@key "networkRequestId"]
      networkRequestId: option(Network.RequestId.t), /* Identifier of the network request associated with this entry. */
      [@yojson.option] [@key "workerId"]
      workerId: option(string), /* Identifier of the worker associated with this entry. */
      [@yojson.option] [@key "args"]
      args: option(list(Runtime.RemoteObject.t)) /* Call arguments. */,
    };
  }
  and ViolationSetting: {
    type _violationsetting_name = [
      | `longTask
      | `longLayout
      | `blockedEvent
      | `blockedParser
      | `discouragedAPIUse
      | `handler
      | `recurringHandler
    ];
    let _violationsetting_name_of_yojson:
      Yojson.Basic.t => _violationsetting_name;
    let yojson_of__violationsetting_name:
      _violationsetting_name => Yojson.Basic.t;
    /* Violation configuration setting. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: _violationsetting_name, /* Violation type. */
      [@key "threshold"]
      threshold: float /* Time threshold to trigger upon. */,
    };
  } = {
    type _violationsetting_name = [
      | `longTask
      | `longLayout
      | `blockedEvent
      | `blockedParser
      | `discouragedAPIUse
      | `handler
      | `recurringHandler
    ];
    let _violationsetting_name_of_yojson =
      fun
      | `String("longTask") => `longTask
      | `String("longLayout") => `longLayout
      | `String("blockedEvent") => `blockedEvent
      | `String("blockedParser") => `blockedParser
      | `String("discouragedAPIUse") => `discouragedAPIUse
      | `String("handler") => `handler
      | `String("recurringHandler") => `recurringHandler
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__violationsetting_name =
      fun
      | `longTask => `String("longTask")
      | `longLayout => `String("longLayout")
      | `blockedEvent => `String("blockedEvent")
      | `blockedParser => `String("blockedParser")
      | `discouragedAPIUse => `String("discouragedAPIUse")
      | `handler => `String("handler")
      | `recurringHandler => `String("recurringHandler");
    /* Violation configuration setting. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: _violationsetting_name, /* Violation type. */
      [@key "threshold"]
      threshold: float /* Time threshold to trigger upon. */,
    };
  };
}
and Memory: {
  module rec PressureLevel: {
    type _pressurelevel = [ | `moderate | `critical];
    let _pressurelevel_of_yojson: Yojson.Basic.t => _pressurelevel;
    let yojson_of__pressurelevel: _pressurelevel => Yojson.Basic.t;
    /* Memory pressure level. */
    [@deriving yojson]
    type t = _pressurelevel;
  }
  and SamplingProfileNode: {
    /* Heap profile sample. */
    [@deriving yojson]
    type t = {
      [@key "size"]
      size: float, /* Size of the sampled allocation. */
      [@key "total"]
      total: float, /* Total bytes attributed to this sample. */
      [@key "stack"]
      stack: list(string) /* Execution stack at the point of allocation. */,
    };
  }
  and SamplingProfile: {
    /* Array of heap profile samples. */
    [@deriving yojson]
    type t = {
      [@key "samples"]
      samples: list(SamplingProfileNode.t), /* No description provided */
      [@key "modules"]
      modules: list(Module.t) /* No description provided */,
    };
  }
  and Module: {
    /* Executable module information */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name of the module. */
      [@key "uuid"]
      uuid: string, /* UUID of the module. */
      [@key "baseAddress"]
      baseAddress: string, /* Base address where the module is loaded into memory. Encoded as a decimal
or hexadecimal (0x prefixed) string. */
      [@key "size"]
      size: float /* Size of the module in bytes. */,
    };
  };
} = {
  module rec PressureLevel: {
    type _pressurelevel = [ | `moderate | `critical];
    let _pressurelevel_of_yojson: Yojson.Basic.t => _pressurelevel;
    let yojson_of__pressurelevel: _pressurelevel => Yojson.Basic.t;
    /* Memory pressure level. */
    [@deriving yojson]
    type t = _pressurelevel;
  } = {
    type _pressurelevel = [ | `moderate | `critical];
    let _pressurelevel_of_yojson =
      fun
      | `String("moderate") => `moderate
      | `String("critical") => `critical
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__pressurelevel =
      fun
      | `moderate => `String("moderate")
      | `critical => `String("critical");
    /* Memory pressure level. */
    [@deriving yojson]
    type t = _pressurelevel;
  }
  and SamplingProfileNode: {
    /* Heap profile sample. */
    [@deriving yojson]
    type t = {
      [@key "size"]
      size: float, /* Size of the sampled allocation. */
      [@key "total"]
      total: float, /* Total bytes attributed to this sample. */
      [@key "stack"]
      stack: list(string) /* Execution stack at the point of allocation. */,
    };
  } = {
    /* Heap profile sample. */
    [@deriving yojson]
    type t = {
      [@key "size"]
      size: float, /* Size of the sampled allocation. */
      [@key "total"]
      total: float, /* Total bytes attributed to this sample. */
      [@key "stack"]
      stack: list(string) /* Execution stack at the point of allocation. */,
    };
  }
  and SamplingProfile: {
    /* Array of heap profile samples. */
    [@deriving yojson]
    type t = {
      [@key "samples"]
      samples: list(SamplingProfileNode.t), /* No description provided */
      [@key "modules"]
      modules: list(Module.t) /* No description provided */,
    };
  } = {
    /* Array of heap profile samples. */
    [@deriving yojson]
    type t = {
      [@key "samples"]
      samples: list(SamplingProfileNode.t), /* No description provided */
      [@key "modules"]
      modules: list(Module.t) /* No description provided */,
    };
  }
  and Module: {
    /* Executable module information */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name of the module. */
      [@key "uuid"]
      uuid: string, /* UUID of the module. */
      [@key "baseAddress"]
      baseAddress: string, /* Base address where the module is loaded into memory. Encoded as a decimal
or hexadecimal (0x prefixed) string. */
      [@key "size"]
      size: float /* Size of the module in bytes. */,
    };
  } = {
    /* Executable module information */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Name of the module. */
      [@key "uuid"]
      uuid: string, /* UUID of the module. */
      [@key "baseAddress"]
      baseAddress: string, /* Base address where the module is loaded into memory. Encoded as a decimal
or hexadecimal (0x prefixed) string. */
      [@key "size"]
      size: float /* Size of the module in bytes. */,
    };
  };
}
and Network: {
  module rec ResourceType: {
    type _resourcetype = [
      | `Document
      | `Stylesheet
      | `Image
      | `Media
      | `Font
      | `Script
      | `TextTrack
      | `XHR
      | `Fetch
      | `EventSource
      | `WebSocket
      | `Manifest
      | `SignedExchange
      | `Ping
      | `CSPViolationReport
      | `Preflight
      | `Other
    ];
    let _resourcetype_of_yojson: Yojson.Basic.t => _resourcetype;
    let yojson_of__resourcetype: _resourcetype => Yojson.Basic.t;
    /* Resource type as it was perceived by the rendering engine. */
    [@deriving yojson]
    type t = _resourcetype;
  }
  and LoaderId: {
    /* Unique loader identifier. */
    [@deriving yojson]
    type t = string;
  }
  and RequestId: {
    /* Unique request identifier. */
    [@deriving yojson]
    type t = string;
  }
  and InterceptionId: {
    /* Unique intercepted request identifier. */
    [@deriving yojson]
    type t = string;
  }
  and ErrorReason: {
    type _errorreason = [
      | `Failed
      | `Aborted
      | `TimedOut
      | `AccessDenied
      | `ConnectionClosed
      | `ConnectionReset
      | `ConnectionRefused
      | `ConnectionAborted
      | `ConnectionFailed
      | `NameNotResolved
      | `InternetDisconnected
      | `AddressUnreachable
      | `BlockedByClient
      | `BlockedByResponse
    ];
    let _errorreason_of_yojson: Yojson.Basic.t => _errorreason;
    let yojson_of__errorreason: _errorreason => Yojson.Basic.t;
    /* Network level fetch failure reason. */
    [@deriving yojson]
    type t = _errorreason;
  }
  and TimeSinceEpoch: {
    /* UTC time in seconds, counted from January 1, 1970. */
    [@deriving yojson]
    type t = float;
  }
  and MonotonicTime: {
    /* Monotonically increasing time in seconds since an arbitrary point in the past. */
    [@deriving yojson]
    type t = float;
  }
  and Headers: {
    /* Request / response headers as keys / values of JSON object. */
    [@deriving yojson]
    type t = assoc;
  }
  and ConnectionType: {
    type _connectiontype = [
      | `none
      | `cellular2g
      | `cellular3g
      | `cellular4g
      | `bluetooth
      | `ethernet
      | `wifi
      | `wimax
      | `other
    ];
    let _connectiontype_of_yojson: Yojson.Basic.t => _connectiontype;
    let yojson_of__connectiontype: _connectiontype => Yojson.Basic.t;
    /* The underlying connection technology that the browser is supposedly using. */
    [@deriving yojson]
    type t = _connectiontype;
  }
  and CookieSameSite: {
    type _cookiesamesite = [ | `Strict | `Lax | `None];
    let _cookiesamesite_of_yojson: Yojson.Basic.t => _cookiesamesite;
    let yojson_of__cookiesamesite: _cookiesamesite => Yojson.Basic.t;
    /* Represents the cookie's 'SameSite' status:
       https://tools.ietf.org/html/draft-west-first-party-cookies */
    [@deriving yojson]
    type t = _cookiesamesite;
  }
  and CookiePriority: {
    type _cookiepriority = [ | `Low | `Medium | `High];
    let _cookiepriority_of_yojson: Yojson.Basic.t => _cookiepriority;
    let yojson_of__cookiepriority: _cookiepriority => Yojson.Basic.t;
    /* Represents the cookie's 'Priority' status:
       https://tools.ietf.org/html/draft-west-cookie-priority-00 */
    [@deriving yojson]
    type t = _cookiepriority;
  }
  and CookieSourceScheme: {
    type _cookiesourcescheme = [ | `Unset | `NonSecure | `Secure];
    let _cookiesourcescheme_of_yojson: Yojson.Basic.t => _cookiesourcescheme;
    let yojson_of__cookiesourcescheme: _cookiesourcescheme => Yojson.Basic.t;
    /* Represents the source scheme of the origin that originally set the cookie.
       A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
       This is a temporary ability and it will be removed in the future. */
    [@deriving yojson]
    type t = _cookiesourcescheme;
  }
  and ResourceTiming: {
    /* Timing information for the request. */
    [@deriving yojson]
    type t = {
      [@key "requestTime"]
      requestTime: float, /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. */
      [@key "proxyStart"]
      proxyStart: float, /* Started resolving proxy. */
      [@key "proxyEnd"]
      proxyEnd: float, /* Finished resolving proxy. */
      [@key "dnsStart"]
      dnsStart: float, /* Started DNS address resolve. */
      [@key "dnsEnd"]
      dnsEnd: float, /* Finished DNS address resolve. */
      [@key "connectStart"]
      connectStart: float, /* Started connecting to the remote host. */
      [@key "connectEnd"]
      connectEnd: float, /* Connected to the remote host. */
      [@key "sslStart"]
      sslStart: float, /* Started SSL handshake. */
      [@key "sslEnd"]
      sslEnd: float, /* Finished SSL handshake. */
      [@key "workerStart"]
      workerStart: float, /* Started running ServiceWorker. */
      [@key "workerReady"]
      workerReady: float, /* Finished Starting ServiceWorker. */
      [@key "workerFetchStart"]
      workerFetchStart: float, /* Started fetch event. */
      [@key "workerRespondWithSettled"]
      workerRespondWithSettled: float, /* Settled fetch event respondWith promise. */
      [@key "sendStart"]
      sendStart: float, /* Started sending request. */
      [@key "sendEnd"]
      sendEnd: float, /* Finished sending request. */
      [@key "pushStart"]
      pushStart: float, /* Time the server started pushing request. */
      [@key "pushEnd"]
      pushEnd: float, /* Time the server finished pushing request. */
      [@key "receiveHeadersEnd"]
      receiveHeadersEnd: float /* Finished receiving response headers. */,
    };
  }
  and ResourcePriority: {
    type _resourcepriority = [
      | `VeryLow
      | `Low
      | `Medium
      | `High
      | `VeryHigh
    ];
    let _resourcepriority_of_yojson: Yojson.Basic.t => _resourcepriority;
    let yojson_of__resourcepriority: _resourcepriority => Yojson.Basic.t;
    /* Loading priority of a resource request. */
    [@deriving yojson]
    type t = _resourcepriority;
  }
  and PostDataEntry: {
    /* Post data entry for HTTP request */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "bytes"]
      bytes: option(string) /* No description provided */,
    };
  }
  and Request: {
    type _request_referrerpolicy = [
      | `unsafe_url
      | `no_referrer_when_downgrade
      | `no_referrer
      | `origin
      | `origin_when_cross_origin
      | `same_origin
      | `strict_origin
      | `strict_origin_when_cross_origin
    ];
    let _request_referrerpolicy_of_yojson:
      Yojson.Basic.t => _request_referrerpolicy;
    let yojson_of__request_referrerpolicy:
      _request_referrerpolicy => Yojson.Basic.t;
    /* HTTP request data. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Request URL (without fragment). */
      [@yojson.option] [@key "urlFragment"]
      urlFragment: option(string), /* Fragment of the requested URL starting with hash, if present. */
      [@key "method"]
      method: string, /* HTTP request method. */
      [@key "headers"]
      headers: Headers.t, /* HTTP request headers. */
      [@yojson.option] [@key "postData"]
      postData: option(string), /* HTTP POST request data. */
      [@yojson.option] [@key "hasPostData"]
      hasPostData: option(bool), /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
      [@yojson.option] [@key "postDataEntries"]
      postDataEntries: option(list(PostDataEntry.t)), /* Request body elements. This will be converted from base64 to binary */
      [@yojson.option] [@key "mixedContentType"]
      mixedContentType: option(Security.MixedContentType.t), /* The mixed content type of the request. */
      [@key "initialPriority"]
      initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
      [@key "referrerPolicy"]
      referrerPolicy: _request_referrerpolicy, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
      [@yojson.option] [@key "isLinkPreload"]
      isLinkPreload: option(bool), /* Whether is loaded via link preload. */
      [@yojson.option] [@key "trustTokenParams"]
      trustTokenParams: option(TrustTokenParams.t), /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */
      [@yojson.option] [@key "isSameSite"]
      isSameSite: option(bool) /* True if this resource request is considered to be the 'same site' as the
request correspondinfg to the main frame. */,
    };
  }
  and SignedCertificateTimestamp: {
    /* Details of a signed certificate timestamp (SCT). */
    [@deriving yojson]
    type t = {
      [@key "status"]
      status: string, /* Validation status. */
      [@key "origin"]
      origin: string, /* Origin. */
      [@key "logDescription"]
      logDescription: string, /* Log name / description. */
      [@key "logId"]
      logId: string, /* Log ID. */
      [@key "timestamp"]
      timestamp: float, /* Issuance date. Unlike TimeSinceEpoch, this contains the number of
milliseconds since January 1, 1970, UTC, not the number of seconds. */
      [@key "hashAlgorithm"]
      hashAlgorithm: string, /* Hash algorithm. */
      [@key "signatureAlgorithm"]
      signatureAlgorithm: string, /* Signature algorithm. */
      [@key "signatureData"]
      signatureData: string /* Signature data. */,
    };
  }
  and SecurityDetails: {
    /* Security details about a request. */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
      [@key "keyExchange"]
      keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
      [@yojson.option] [@key "keyExchangeGroup"]
      keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
      [@key "cipher"]
      cipher: string, /* Cipher name. */
      [@yojson.option] [@key "mac"]
      mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
      [@key "certificateId"]
      certificateId: Security.CertificateId.t, /* Certificate ID value. */
      [@key "subjectName"]
      subjectName: string, /* Certificate subject name. */
      [@key "sanList"]
      sanList: list(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
      [@key "issuer"]
      issuer: string, /* Name of the issuing CA. */
      [@key "validFrom"]
      validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
      [@key "validTo"]
      validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
      [@key "signedCertificateTimestampList"]
      signedCertificateTimestampList: list(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
      [@key "certificateTransparencyCompliance"]
      certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
    };
  }
  and CertificateTransparencyCompliance: {
    type _certificatetransparencycompliance = [
      | `unknown
      | `not_compliant
      | `compliant
    ];
    let _certificatetransparencycompliance_of_yojson:
      Yojson.Basic.t => _certificatetransparencycompliance;
    let yojson_of__certificatetransparencycompliance:
      _certificatetransparencycompliance => Yojson.Basic.t;
    /* Whether the request complied with Certificate Transparency policy. */
    [@deriving yojson]
    type t = _certificatetransparencycompliance;
  }
  and BlockedReason: {
    type _blockedreason = [
      | `other
      | `csp
      | `mixed_content
      | `origin
      | `inspector
      | `subresource_filter
      | `content_type
      | `coep_frame_resource_needs_coep_header
      | `coop_sandboxed_iframe_cannot_navigate_to_coop_page
      | `corp_not_same_origin
      | `corp_not_same_origin_after_defaulted_to_same_origin_by_coep
      | `corp_not_same_site
    ];
    let _blockedreason_of_yojson: Yojson.Basic.t => _blockedreason;
    let yojson_of__blockedreason: _blockedreason => Yojson.Basic.t;
    /* The reason why request was blocked. */
    [@deriving yojson]
    type t = _blockedreason;
  }
  and CorsError: {
    type _corserror = [
      | `DisallowedByMode
      | `InvalidResponse
      | `WildcardOriginNotAllowed
      | `MissingAllowOriginHeader
      | `MultipleAllowOriginValues
      | `InvalidAllowOriginValue
      | `AllowOriginMismatch
      | `InvalidAllowCredentials
      | `CorsDisabledScheme
      | `PreflightInvalidStatus
      | `PreflightDisallowedRedirect
      | `PreflightWildcardOriginNotAllowed
      | `PreflightMissingAllowOriginHeader
      | `PreflightMultipleAllowOriginValues
      | `PreflightInvalidAllowOriginValue
      | `PreflightAllowOriginMismatch
      | `PreflightInvalidAllowCredentials
      | `PreflightMissingAllowExternal
      | `PreflightInvalidAllowExternal
      | `InvalidAllowMethodsPreflightResponse
      | `InvalidAllowHeadersPreflightResponse
      | `MethodDisallowedByPreflightResponse
      | `HeaderDisallowedByPreflightResponse
      | `RedirectContainsCredentials
      | `InsecurePrivateNetwork
      | `InvalidPrivateNetworkAccess
      | `UnexpectedPrivateNetworkAccess
      | `NoCorsRedirectModeNotFollow
    ];
    let _corserror_of_yojson: Yojson.Basic.t => _corserror;
    let yojson_of__corserror: _corserror => Yojson.Basic.t;
    /* The reason why request was blocked. */
    [@deriving yojson]
    type t = _corserror;
  }
  and CorsErrorStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "corsError"]
      corsError: CorsError.t, /* No description provided */
      [@key "failedParameter"]
      failedParameter: string /* No description provided */,
    };
  }
  and ServiceWorkerResponseSource: {
    type _serviceworkerresponsesource = [
      | `cache_storage
      | `http_cache
      | `fallback_code
      | `network
    ];
    let _serviceworkerresponsesource_of_yojson:
      Yojson.Basic.t => _serviceworkerresponsesource;
    let yojson_of__serviceworkerresponsesource:
      _serviceworkerresponsesource => Yojson.Basic.t;
    /* Source of serviceworker response. */
    [@deriving yojson]
    type t = _serviceworkerresponsesource;
  }
  and TrustTokenParams: {
    type _trusttokenparams_refreshpolicy = [ | `UseCached | `Refresh];
    let _trusttokenparams_refreshpolicy_of_yojson:
      Yojson.Basic.t => _trusttokenparams_refreshpolicy;
    let yojson_of__trusttokenparams_refreshpolicy:
      _trusttokenparams_refreshpolicy => Yojson.Basic.t;
    /* Determines what type of Trust Token operation is executed and
       depending on the type, some additional parameters. The values
       are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: TrustTokenOperationType.t, /* No description provided */
      [@key "refreshPolicy"]
      refreshPolicy: _trusttokenparams_refreshpolicy, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
      [@yojson.option] [@key "issuers"]
      issuers: option(list(string)) /* Origins of issuers from whom to request tokens or redemption
records. */,
    };
  }
  and TrustTokenOperationType: {
    type _trusttokenoperationtype = [ | `Issuance | `Redemption | `Signing];
    let _trusttokenoperationtype_of_yojson:
      Yojson.Basic.t => _trusttokenoperationtype;
    let yojson_of__trusttokenoperationtype:
      _trusttokenoperationtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _trusttokenoperationtype;
  }
  and Response: {
    /* HTTP response data. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
      [@key "status"]
      status: float, /* HTTP response status code. */
      [@key "statusText"]
      statusText: string, /* HTTP response status text. */
      [@key "headers"]
      headers: Headers.t, /* HTTP response headers. */
      [@yojson.option] [@key "headersText"]
      headersText: option(string), /* HTTP response headers text. This has been replaced by the headers in Network.responseReceivedExtraInfo. */
      [@key "mimeType"]
      mimeType: string, /* Resource mimeType as determined by the browser. */
      [@yojson.option] [@key "requestHeaders"]
      requestHeaders: option(Headers.t), /* Refined HTTP request headers that were actually transmitted over the network. */
      [@yojson.option] [@key "requestHeadersText"]
      requestHeadersText: option(string), /* HTTP request headers text. This has been replaced by the headers in Network.requestWillBeSentExtraInfo. */
      [@key "connectionReused"]
      connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
      [@key "connectionId"]
      connectionId: float, /* Physical connection id that was actually used for this request. */
      [@yojson.option] [@key "remoteIPAddress"]
      remoteIPAddress: option(string), /* Remote IP address. */
      [@yojson.option] [@key "remotePort"]
      remotePort: option(float), /* Remote port. */
      [@yojson.option] [@key "fromDiskCache"]
      fromDiskCache: option(bool), /* Specifies that the request was served from the disk cache. */
      [@yojson.option] [@key "fromServiceWorker"]
      fromServiceWorker: option(bool), /* Specifies that the request was served from the ServiceWorker. */
      [@yojson.option] [@key "fromPrefetchCache"]
      fromPrefetchCache: option(bool), /* Specifies that the request was served from the prefetch cache. */
      [@key "encodedDataLength"]
      encodedDataLength: float, /* Total number of bytes received for this request so far. */
      [@yojson.option] [@key "timing"]
      timing: option(ResourceTiming.t), /* Timing information for the given request. */
      [@yojson.option] [@key "serviceWorkerResponseSource"]
      serviceWorkerResponseSource: option(ServiceWorkerResponseSource.t), /* Response source of response from ServiceWorker. */
      [@yojson.option] [@key "responseTime"]
      responseTime: option(TimeSinceEpoch.t), /* The time at which the returned response was generated. */
      [@yojson.option] [@key "cacheStorageCacheName"]
      cacheStorageCacheName: option(string), /* Cache Storage Cache Name. */
      [@yojson.option] [@key "protocol"]
      protocol: option(string), /* Protocol used to fetch this request. */
      [@key "securityState"]
      securityState: Security.SecurityState.t, /* Security state of the request resource. */
      [@yojson.option] [@key "securityDetails"]
      securityDetails: option(SecurityDetails.t) /* Security details for the request. */,
    };
  }
  and WebSocketRequest: {
    /* WebSocket request data. */
    [@deriving yojson]
    type t = {
      [@key "headers"]
      headers: Headers.t /* HTTP request headers. */,
    };
  }
  and WebSocketResponse: {
    /* WebSocket response data. */
    [@deriving yojson]
    type t = {
      [@key "status"]
      status: float, /* HTTP response status code. */
      [@key "statusText"]
      statusText: string, /* HTTP response status text. */
      [@key "headers"]
      headers: Headers.t, /* HTTP response headers. */
      [@yojson.option] [@key "headersText"]
      headersText: option(string), /* HTTP response headers text. */
      [@yojson.option] [@key "requestHeaders"]
      requestHeaders: option(Headers.t), /* HTTP request headers. */
      [@yojson.option] [@key "requestHeadersText"]
      requestHeadersText: option(string) /* HTTP request headers text. */,
    };
  }
  and WebSocketFrame: {
    /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
    [@deriving yojson]
    type t = {
      [@key "opcode"]
      opcode: float, /* WebSocket message opcode. */
      [@key "mask"]
      mask: bool, /* WebSocket message mask. */
      [@key "payloadData"]
      payloadData: string /* WebSocket message payload data.
If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data. */,
    };
  }
  and CachedResource: {
    /* Information about the cached resource. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Resource URL. This is the url of the original network request. */
      [@key "type"]
      type_: ResourceType.t, /* Type of this resource. */
      [@yojson.option] [@key "response"]
      response: option(Response.t), /* Cached response data. */
      [@key "bodySize"]
      bodySize: float /* Cached response body size. */,
    };
  }
  and Initiator: {
    type _initiator_type = [
      | `parser
      | `script
      | `preload
      | `SignedExchange
      | `preflight
      | `other
    ];
    let _initiator_type_of_yojson: Yojson.Basic.t => _initiator_type;
    let yojson_of__initiator_type: _initiator_type => Yojson.Basic.t;
    /* Information about the request initiator. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _initiator_type, /* Type of this initiator. */
      [@yojson.option] [@key "stack"]
      stack: option(Runtime.StackTrace.t), /* Initiator JavaScript stack trace, set for Script only. */
      [@yojson.option] [@key "url"]
      url: option(string), /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
      [@yojson.option] [@key "lineNumber"]
      lineNumber: option(float), /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float), /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
      [@yojson.option] [@key "requestId"]
      requestId: option(RequestId.t) /* Set if another request triggered this request (e.g. preflight). */,
    };
  }
  and Cookie: {
    /* Cookie object */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Cookie name. */
      [@key "value"]
      value: string, /* Cookie value. */
      [@key "domain"]
      domain: string, /* Cookie domain. */
      [@key "path"]
      path: string, /* Cookie path. */
      [@key "expires"]
      expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
      [@key "size"]
      size: float, /* Cookie size. */
      [@key "httpOnly"]
      httpOnly: bool, /* True if cookie is http-only. */
      [@key "secure"]
      secure: bool, /* True if cookie is secure. */
      [@key "session"]
      session: bool, /* True in case of session cookie. */
      [@yojson.option] [@key "sameSite"]
      sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
      [@key "priority"]
      priority: CookiePriority.t, /* Cookie Priority */
      [@key "sameParty"]
      sameParty: bool, /* True if cookie is SameParty. */
      [@key "sourceScheme"]
      sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
      [@key "sourcePort"]
      sourcePort: float, /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */
      [@yojson.option] [@key "partitionKey"]
      partitionKey: option(string), /* Cookie partition key. The site of the top-level URL the browser was visiting at the start
of the request to the endpoint that set the cookie. */
      [@yojson.option] [@key "partitionKeyOpaque"]
      partitionKeyOpaque: option(bool) /* True if cookie partition key is opaque. */,
    };
  }
  and SetCookieBlockedReason: {
    type _setcookieblockedreason = [
      | `SecureOnly
      | `SameSiteStrict
      | `SameSiteLax
      | `SameSiteUnspecifiedTreatedAsLax
      | `SameSiteNoneInsecure
      | `UserPreferences
      | `SyntaxError
      | `SchemeNotSupported
      | `OverwriteSecure
      | `InvalidDomain
      | `InvalidPrefix
      | `UnknownError
      | `SchemefulSameSiteStrict
      | `SchemefulSameSiteLax
      | `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `SamePartyFromCrossPartyContext
      | `SamePartyConflictsWithOtherAttributes
      | `NameValuePairExceedsMaxSize
    ];
    let _setcookieblockedreason_of_yojson:
      Yojson.Basic.t => _setcookieblockedreason;
    let yojson_of__setcookieblockedreason:
      _setcookieblockedreason => Yojson.Basic.t;
    /* Types of reasons why a cookie may not be stored from a response. */
    [@deriving yojson]
    type t = _setcookieblockedreason;
  }
  and CookieBlockedReason: {
    type _cookieblockedreason = [
      | `SecureOnly
      | `NotOnPath
      | `DomainMismatch
      | `SameSiteStrict
      | `SameSiteLax
      | `SameSiteUnspecifiedTreatedAsLax
      | `SameSiteNoneInsecure
      | `UserPreferences
      | `UnknownError
      | `SchemefulSameSiteStrict
      | `SchemefulSameSiteLax
      | `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `SamePartyFromCrossPartyContext
      | `NameValuePairExceedsMaxSize
    ];
    let _cookieblockedreason_of_yojson: Yojson.Basic.t => _cookieblockedreason;
    let yojson_of__cookieblockedreason: _cookieblockedreason => Yojson.Basic.t;
    /* Types of reasons why a cookie may not be sent with a request. */
    [@deriving yojson]
    type t = _cookieblockedreason;
  }
  and BlockedSetCookieWithReason: {
    /* A cookie which was not stored from a response with the corresponding reason. */
    [@deriving yojson]
    type t = {
      [@key "blockedReasons"]
      blockedReasons: list(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
      [@key "cookieLine"]
      cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
      [@yojson.option] [@key "cookie"]
      cookie: option(Cookie.t) /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
    };
  }
  and BlockedCookieWithReason: {
    /* A cookie with was not sent with a request with the corresponding reason. */
    [@deriving yojson]
    type t = {
      [@key "blockedReasons"]
      blockedReasons: list(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
      [@key "cookie"]
      cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
    };
  }
  and CookieParam: {
    /* Cookie parameter object */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Cookie name. */
      [@key "value"]
      value: string, /* Cookie value. */
      [@yojson.option] [@key "url"]
      url: option(string), /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
      [@yojson.option] [@key "domain"]
      domain: option(string), /* Cookie domain. */
      [@yojson.option] [@key "path"]
      path: option(string), /* Cookie path. */
      [@yojson.option] [@key "secure"]
      secure: option(bool), /* True if cookie is secure. */
      [@yojson.option] [@key "httpOnly"]
      httpOnly: option(bool), /* True if cookie is http-only. */
      [@yojson.option] [@key "sameSite"]
      sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
      [@yojson.option] [@key "expires"]
      expires: option(TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
      [@yojson.option] [@key "priority"]
      priority: option(CookiePriority.t), /* Cookie Priority. */
      [@yojson.option] [@key "sameParty"]
      sameParty: option(bool), /* True if cookie is SameParty. */
      [@yojson.option] [@key "sourceScheme"]
      sourceScheme: option(CookieSourceScheme.t), /* Cookie source scheme type. */
      [@yojson.option] [@key "sourcePort"]
      sourcePort: option(float), /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */
      [@yojson.option] [@key "partitionKey"]
      partitionKey: option(string) /* Cookie partition key. The site of the top-level URL the browser was visiting at the start
of the request to the endpoint that set the cookie.
If not set, the cookie will be set as not partitioned. */,
    };
  }
  and AuthChallenge: {
    type _authchallenge_source = [ | `Server | `Proxy];
    let _authchallenge_source_of_yojson:
      Yojson.Basic.t => _authchallenge_source;
    let yojson_of__authchallenge_source:
      _authchallenge_source => Yojson.Basic.t;
    /* Authorization challenge for HTTP status code 401 or 407. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "source"]
      source: option(_authchallenge_source), /* Source of the authentication challenge. */
      [@key "origin"]
      origin: string, /* Origin of the challenger. */
      [@key "scheme"]
      scheme: string, /* The authentication scheme used, such as basic or digest */
      [@key "realm"]
      realm: string /* The realm of the challenge. May be empty. */,
    };
  }
  and AuthChallengeResponse: {
    type _authchallengeresponse_response = [
      | `Default
      | `CancelAuth
      | `ProvideCredentials
    ];
    let _authchallengeresponse_response_of_yojson:
      Yojson.Basic.t => _authchallengeresponse_response;
    let yojson_of__authchallengeresponse_response:
      _authchallengeresponse_response => Yojson.Basic.t;
    /* Response to an AuthChallenge. */
    [@deriving yojson]
    type t = {
      [@key "response"]
      response: _authchallengeresponse_response, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
      [@yojson.option] [@key "username"]
      username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
      [@yojson.option] [@key "password"]
      password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
    };
  }
  and InterceptionStage: {
    type _interceptionstage = [ | `Request | `HeadersReceived];
    let _interceptionstage_of_yojson: Yojson.Basic.t => _interceptionstage;
    let yojson_of__interceptionstage: _interceptionstage => Yojson.Basic.t;
    /* Stages of the interception to begin intercepting. Request will intercept before the request is
       sent. Response will intercept after the response is received. */
    [@deriving yojson]
    type t = _interceptionstage;
  }
  and RequestPattern: {
    /* Request pattern for interception. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "urlPattern"]
      urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
      [@yojson.option] [@key "resourceType"]
      resourceType: option(ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
      [@yojson.option] [@key "interceptionStage"]
      interceptionStage: option(InterceptionStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
    };
  }
  and SignedExchangeSignature: {
    /* Information about a signed exchange signature.
       https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
    [@deriving yojson]
    type t = {
      [@key "label"]
      label: string, /* Signed exchange signature label. */
      [@key "signature"]
      signature: string, /* The hex string of signed exchange signature. */
      [@key "integrity"]
      integrity: string, /* Signed exchange signature integrity. */
      [@yojson.option] [@key "certUrl"]
      certUrl: option(string), /* Signed exchange signature cert Url. */
      [@yojson.option] [@key "certSha256"]
      certSha256: option(string), /* The hex string of signed exchange signature cert sha256. */
      [@key "validityUrl"]
      validityUrl: string, /* Signed exchange signature validity Url. */
      [@key "date"]
      date: float, /* Signed exchange signature date. */
      [@key "expires"]
      expires: float, /* Signed exchange signature expires. */
      [@yojson.option] [@key "certificates"]
      certificates: option(list(string)) /* The encoded certificates. */,
    };
  }
  and SignedExchangeHeader: {
    /* Information about a signed exchange header.
       https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
    [@deriving yojson]
    type t = {
      [@key "requestUrl"]
      requestUrl: string, /* Signed exchange request URL. */
      [@key "responseCode"]
      responseCode: float, /* Signed exchange response code. */
      [@key "responseHeaders"]
      responseHeaders: Headers.t, /* Signed exchange response headers. */
      [@key "signatures"]
      signatures: list(SignedExchangeSignature.t), /* Signed exchange response signature. */
      [@key "headerIntegrity"]
      headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
    };
  }
  and SignedExchangeErrorField: {
    type _signedexchangeerrorfield = [
      | `signatureSig
      | `signatureIntegrity
      | `signatureCertUrl
      | `signatureCertSha256
      | `signatureValidityUrl
      | `signatureTimestamps
    ];
    let _signedexchangeerrorfield_of_yojson:
      Yojson.Basic.t => _signedexchangeerrorfield;
    let yojson_of__signedexchangeerrorfield:
      _signedexchangeerrorfield => Yojson.Basic.t;
    /* Field type for a signed exchange related error. */
    [@deriving yojson]
    type t = _signedexchangeerrorfield;
  }
  and SignedExchangeError: {
    /* Information about a signed exchange response. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@yojson.option] [@key "signatureIndex"]
      signatureIndex: option(float), /* The index of the signature which caused the error. */
      [@yojson.option] [@key "errorField"]
      errorField: option(SignedExchangeErrorField.t) /* The field which caused the error. */,
    };
  }
  and SignedExchangeInfo: {
    /* Information about a signed exchange response. */
    [@deriving yojson]
    type t = {
      [@key "outerResponse"]
      outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
      [@yojson.option] [@key "header"]
      header: option(SignedExchangeHeader.t), /* Information about the signed exchange header. */
      [@yojson.option] [@key "securityDetails"]
      securityDetails: option(SecurityDetails.t), /* Security details for the signed exchange header. */
      [@yojson.option] [@key "errors"]
      errors: option(list(SignedExchangeError.t)) /* Errors occurred while handling the signed exchagne. */,
    };
  }
  and ContentEncoding: {
    type _contentencoding = [ | `deflate | `gzip | `br];
    let _contentencoding_of_yojson: Yojson.Basic.t => _contentencoding;
    let yojson_of__contentencoding: _contentencoding => Yojson.Basic.t;
    /* List of content encodings supported by the backend. */
    [@deriving yojson]
    type t = _contentencoding;
  }
  and PrivateNetworkRequestPolicy: {
    type _privatenetworkrequestpolicy = [
      | `Allow
      | `BlockFromInsecureToMorePrivate
      | `WarnFromInsecureToMorePrivate
      | `PreflightBlock
      | `PreflightWarn
    ];
    let _privatenetworkrequestpolicy_of_yojson:
      Yojson.Basic.t => _privatenetworkrequestpolicy;
    let yojson_of__privatenetworkrequestpolicy:
      _privatenetworkrequestpolicy => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _privatenetworkrequestpolicy;
  }
  and IPAddressSpace: {
    type _ipaddressspace = [ | `Local | `Private | `Public | `Unknown];
    let _ipaddressspace_of_yojson: Yojson.Basic.t => _ipaddressspace;
    let yojson_of__ipaddressspace: _ipaddressspace => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _ipaddressspace;
  }
  and ConnectTiming: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "requestTime"]
      requestTime: float /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. Matches ResourceTiming's requestTime for
the same request (but not for redirected requests). */,
    };
  }
  and ClientSecurityState: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "initiatorIsSecureContext"]
      initiatorIsSecureContext: bool, /* No description provided */
      [@key "initiatorIPAddressSpace"]
      initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
      [@key "privateNetworkRequestPolicy"]
      privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
    };
  }
  and CrossOriginOpenerPolicyValue: {
    type _crossoriginopenerpolicyvalue = [
      | `SameOrigin
      | `SameOriginAllowPopups
      | `UnsafeNone
      | `SameOriginPlusCoep
    ];
    let _crossoriginopenerpolicyvalue_of_yojson:
      Yojson.Basic.t => _crossoriginopenerpolicyvalue;
    let yojson_of__crossoriginopenerpolicyvalue:
      _crossoriginopenerpolicyvalue => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _crossoriginopenerpolicyvalue;
  }
  and CrossOriginOpenerPolicyStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: CrossOriginOpenerPolicyValue.t, /* No description provided */
      [@key "reportOnlyValue"]
      reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
      [@yojson.option] [@key "reportingEndpoint"]
      reportingEndpoint: option(string), /* No description provided */
      [@yojson.option] [@key "reportOnlyReportingEndpoint"]
      reportOnlyReportingEndpoint: option(string) /* No description provided */,
    };
  }
  and CrossOriginEmbedderPolicyValue: {
    type _crossoriginembedderpolicyvalue = [
      | `None
      | `Credentialless
      | `RequireCorp
    ];
    let _crossoriginembedderpolicyvalue_of_yojson:
      Yojson.Basic.t => _crossoriginembedderpolicyvalue;
    let yojson_of__crossoriginembedderpolicyvalue:
      _crossoriginembedderpolicyvalue => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _crossoriginembedderpolicyvalue;
  }
  and CrossOriginEmbedderPolicyStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
      [@key "reportOnlyValue"]
      reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
      [@yojson.option] [@key "reportingEndpoint"]
      reportingEndpoint: option(string), /* No description provided */
      [@yojson.option] [@key "reportOnlyReportingEndpoint"]
      reportOnlyReportingEndpoint: option(string) /* No description provided */,
    };
  }
  and SecurityIsolationStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "coop"]
      coop: option(CrossOriginOpenerPolicyStatus.t), /* No description provided */
      [@yojson.option] [@key "coep"]
      coep: option(CrossOriginEmbedderPolicyStatus.t) /* No description provided */,
    };
  }
  and ReportStatus: {
    type _reportstatus = [
      | `Queued
      | `Pending
      | `MarkedForRemoval
      | `Success
    ];
    let _reportstatus_of_yojson: Yojson.Basic.t => _reportstatus;
    let yojson_of__reportstatus: _reportstatus => Yojson.Basic.t;
    /* The status of a Reporting API report. */
    [@deriving yojson]
    type t = _reportstatus;
  }
  and ReportId: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and ReportingApiReport: {
    /* An object representing a report generated by the Reporting API. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: ReportId.t, /* No description provided */
      [@key "initiatorUrl"]
      initiatorUrl: string, /* The URL of the document that triggered the report. */
      [@key "destination"]
      destination: string, /* The name of the endpoint group that should be used to deliver the report. */
      [@key "type"]
      type_: string, /* The type of the report (specifies the set of data that is contained in the report body). */
      [@key "timestamp"]
      timestamp: Network.TimeSinceEpoch.t, /* When the report was generated. */
      [@key "depth"]
      depth: float, /* How many uploads deep the related request was. */
      [@key "completedAttempts"]
      completedAttempts: float, /* The number of delivery attempts made so far, not including an active attempt. */
      [@key "body"]
      body: assoc, /* No description provided */
      [@key "status"]
      status: ReportStatus.t /* No description provided */,
    };
  }
  and ReportingApiEndpoint: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The URL of the endpoint to which reports may be delivered. */
      [@key "groupName"]
      groupName: string /* Name of the endpoint group. */,
    };
  }
  and LoadNetworkResourcePageResult: {
    /* An object providing the result of a network resource load. */
    [@deriving yojson]
    type t = {
      [@key "success"]
      success: bool, /* No description provided */
      [@yojson.option] [@key "netError"]
      netError: option(float), /* Optional values used for error reporting. */
      [@yojson.option] [@key "netErrorName"]
      netErrorName: option(string), /* No description provided */
      [@yojson.option] [@key "httpStatusCode"]
      httpStatusCode: option(float), /* No description provided */
      [@yojson.option] [@key "stream"]
      stream: option(IO.StreamHandle.t), /* If successful, one of the following two fields holds the result. */
      [@yojson.option] [@key "headers"]
      headers: option(Network.Headers.t) /* Response headers. */,
    };
  }
  and LoadNetworkResourceOptions: {
    /* An options object that may be extended later to better support CORS,
       CORB and streaming. */
    [@deriving yojson]
    type t = {
      [@key "disableCache"]
      disableCache: bool, /* No description provided */
      [@key "includeCredentials"]
      includeCredentials: bool /* No description provided */,
    };
  };
} = {
  module rec ResourceType: {
    type _resourcetype = [
      | `Document
      | `Stylesheet
      | `Image
      | `Media
      | `Font
      | `Script
      | `TextTrack
      | `XHR
      | `Fetch
      | `EventSource
      | `WebSocket
      | `Manifest
      | `SignedExchange
      | `Ping
      | `CSPViolationReport
      | `Preflight
      | `Other
    ];
    let _resourcetype_of_yojson: Yojson.Basic.t => _resourcetype;
    let yojson_of__resourcetype: _resourcetype => Yojson.Basic.t;
    /* Resource type as it was perceived by the rendering engine. */
    [@deriving yojson]
    type t = _resourcetype;
  } = {
    type _resourcetype = [
      | `Document
      | `Stylesheet
      | `Image
      | `Media
      | `Font
      | `Script
      | `TextTrack
      | `XHR
      | `Fetch
      | `EventSource
      | `WebSocket
      | `Manifest
      | `SignedExchange
      | `Ping
      | `CSPViolationReport
      | `Preflight
      | `Other
    ];
    let _resourcetype_of_yojson =
      fun
      | `String("Document") => `Document
      | `String("Stylesheet") => `Stylesheet
      | `String("Image") => `Image
      | `String("Media") => `Media
      | `String("Font") => `Font
      | `String("Script") => `Script
      | `String("TextTrack") => `TextTrack
      | `String("XHR") => `XHR
      | `String("Fetch") => `Fetch
      | `String("EventSource") => `EventSource
      | `String("WebSocket") => `WebSocket
      | `String("Manifest") => `Manifest
      | `String("SignedExchange") => `SignedExchange
      | `String("Ping") => `Ping
      | `String("CSPViolationReport") => `CSPViolationReport
      | `String("Preflight") => `Preflight
      | `String("Other") => `Other
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__resourcetype =
      fun
      | `Document => `String("Document")
      | `Stylesheet => `String("Stylesheet")
      | `Image => `String("Image")
      | `Media => `String("Media")
      | `Font => `String("Font")
      | `Script => `String("Script")
      | `TextTrack => `String("TextTrack")
      | `XHR => `String("XHR")
      | `Fetch => `String("Fetch")
      | `EventSource => `String("EventSource")
      | `WebSocket => `String("WebSocket")
      | `Manifest => `String("Manifest")
      | `SignedExchange => `String("SignedExchange")
      | `Ping => `String("Ping")
      | `CSPViolationReport => `String("CSPViolationReport")
      | `Preflight => `String("Preflight")
      | `Other => `String("Other");
    /* Resource type as it was perceived by the rendering engine. */
    [@deriving yojson]
    type t = _resourcetype;
  }
  and LoaderId: {
    /* Unique loader identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique loader identifier. */
    [@deriving yojson]
    type t = string;
  }
  and RequestId: {
    /* Unique request identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique request identifier. */
    [@deriving yojson]
    type t = string;
  }
  and InterceptionId: {
    /* Unique intercepted request identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique intercepted request identifier. */
    [@deriving yojson]
    type t = string;
  }
  and ErrorReason: {
    type _errorreason = [
      | `Failed
      | `Aborted
      | `TimedOut
      | `AccessDenied
      | `ConnectionClosed
      | `ConnectionReset
      | `ConnectionRefused
      | `ConnectionAborted
      | `ConnectionFailed
      | `NameNotResolved
      | `InternetDisconnected
      | `AddressUnreachable
      | `BlockedByClient
      | `BlockedByResponse
    ];
    let _errorreason_of_yojson: Yojson.Basic.t => _errorreason;
    let yojson_of__errorreason: _errorreason => Yojson.Basic.t;
    /* Network level fetch failure reason. */
    [@deriving yojson]
    type t = _errorreason;
  } = {
    type _errorreason = [
      | `Failed
      | `Aborted
      | `TimedOut
      | `AccessDenied
      | `ConnectionClosed
      | `ConnectionReset
      | `ConnectionRefused
      | `ConnectionAborted
      | `ConnectionFailed
      | `NameNotResolved
      | `InternetDisconnected
      | `AddressUnreachable
      | `BlockedByClient
      | `BlockedByResponse
    ];
    let _errorreason_of_yojson =
      fun
      | `String("Failed") => `Failed
      | `String("Aborted") => `Aborted
      | `String("TimedOut") => `TimedOut
      | `String("AccessDenied") => `AccessDenied
      | `String("ConnectionClosed") => `ConnectionClosed
      | `String("ConnectionReset") => `ConnectionReset
      | `String("ConnectionRefused") => `ConnectionRefused
      | `String("ConnectionAborted") => `ConnectionAborted
      | `String("ConnectionFailed") => `ConnectionFailed
      | `String("NameNotResolved") => `NameNotResolved
      | `String("InternetDisconnected") => `InternetDisconnected
      | `String("AddressUnreachable") => `AddressUnreachable
      | `String("BlockedByClient") => `BlockedByClient
      | `String("BlockedByResponse") => `BlockedByResponse
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__errorreason =
      fun
      | `Failed => `String("Failed")
      | `Aborted => `String("Aborted")
      | `TimedOut => `String("TimedOut")
      | `AccessDenied => `String("AccessDenied")
      | `ConnectionClosed => `String("ConnectionClosed")
      | `ConnectionReset => `String("ConnectionReset")
      | `ConnectionRefused => `String("ConnectionRefused")
      | `ConnectionAborted => `String("ConnectionAborted")
      | `ConnectionFailed => `String("ConnectionFailed")
      | `NameNotResolved => `String("NameNotResolved")
      | `InternetDisconnected => `String("InternetDisconnected")
      | `AddressUnreachable => `String("AddressUnreachable")
      | `BlockedByClient => `String("BlockedByClient")
      | `BlockedByResponse => `String("BlockedByResponse");
    /* Network level fetch failure reason. */
    [@deriving yojson]
    type t = _errorreason;
  }
  and TimeSinceEpoch: {
    /* UTC time in seconds, counted from January 1, 1970. */
    [@deriving yojson]
    type t = float;
  } = {
    /* UTC time in seconds, counted from January 1, 1970. */
    [@deriving yojson]
    type t = float;
  }
  and MonotonicTime: {
    /* Monotonically increasing time in seconds since an arbitrary point in the past. */
    [@deriving yojson]
    type t = float;
  } = {
    /* Monotonically increasing time in seconds since an arbitrary point in the past. */
    [@deriving yojson]
    type t = float;
  }
  and Headers: {
    /* Request / response headers as keys / values of JSON object. */
    [@deriving yojson]
    type t = assoc;
  } = {
    /* Request / response headers as keys / values of JSON object. */
    [@deriving yojson]
    type t = assoc;
  }
  and ConnectionType: {
    type _connectiontype = [
      | `none
      | `cellular2g
      | `cellular3g
      | `cellular4g
      | `bluetooth
      | `ethernet
      | `wifi
      | `wimax
      | `other
    ];
    let _connectiontype_of_yojson: Yojson.Basic.t => _connectiontype;
    let yojson_of__connectiontype: _connectiontype => Yojson.Basic.t;
    /* The underlying connection technology that the browser is supposedly using. */
    [@deriving yojson]
    type t = _connectiontype;
  } = {
    type _connectiontype = [
      | `none
      | `cellular2g
      | `cellular3g
      | `cellular4g
      | `bluetooth
      | `ethernet
      | `wifi
      | `wimax
      | `other
    ];
    let _connectiontype_of_yojson =
      fun
      | `String("none") => `none
      | `String("cellular2g") => `cellular2g
      | `String("cellular3g") => `cellular3g
      | `String("cellular4g") => `cellular4g
      | `String("bluetooth") => `bluetooth
      | `String("ethernet") => `ethernet
      | `String("wifi") => `wifi
      | `String("wimax") => `wimax
      | `String("other") => `other
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__connectiontype =
      fun
      | `none => `String("none")
      | `cellular2g => `String("cellular2g")
      | `cellular3g => `String("cellular3g")
      | `cellular4g => `String("cellular4g")
      | `bluetooth => `String("bluetooth")
      | `ethernet => `String("ethernet")
      | `wifi => `String("wifi")
      | `wimax => `String("wimax")
      | `other => `String("other");
    /* The underlying connection technology that the browser is supposedly using. */
    [@deriving yojson]
    type t = _connectiontype;
  }
  and CookieSameSite: {
    type _cookiesamesite = [ | `Strict | `Lax | `None];
    let _cookiesamesite_of_yojson: Yojson.Basic.t => _cookiesamesite;
    let yojson_of__cookiesamesite: _cookiesamesite => Yojson.Basic.t;
    /* Represents the cookie's 'SameSite' status:
       https://tools.ietf.org/html/draft-west-first-party-cookies */
    [@deriving yojson]
    type t = _cookiesamesite;
  } = {
    type _cookiesamesite = [ | `Strict | `Lax | `None];
    let _cookiesamesite_of_yojson =
      fun
      | `String("Strict") => `Strict
      | `String("Lax") => `Lax
      | `String("None") => `None
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__cookiesamesite =
      fun
      | `Strict => `String("Strict")
      | `Lax => `String("Lax")
      | `None => `String("None");
    /* Represents the cookie's 'SameSite' status:
       https://tools.ietf.org/html/draft-west-first-party-cookies */
    [@deriving yojson]
    type t = _cookiesamesite;
  }
  and CookiePriority: {
    type _cookiepriority = [ | `Low | `Medium | `High];
    let _cookiepriority_of_yojson: Yojson.Basic.t => _cookiepriority;
    let yojson_of__cookiepriority: _cookiepriority => Yojson.Basic.t;
    /* Represents the cookie's 'Priority' status:
       https://tools.ietf.org/html/draft-west-cookie-priority-00 */
    [@deriving yojson]
    type t = _cookiepriority;
  } = {
    type _cookiepriority = [ | `Low | `Medium | `High];
    let _cookiepriority_of_yojson =
      fun
      | `String("Low") => `Low
      | `String("Medium") => `Medium
      | `String("High") => `High
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__cookiepriority =
      fun
      | `Low => `String("Low")
      | `Medium => `String("Medium")
      | `High => `String("High");
    /* Represents the cookie's 'Priority' status:
       https://tools.ietf.org/html/draft-west-cookie-priority-00 */
    [@deriving yojson]
    type t = _cookiepriority;
  }
  and CookieSourceScheme: {
    type _cookiesourcescheme = [ | `Unset | `NonSecure | `Secure];
    let _cookiesourcescheme_of_yojson: Yojson.Basic.t => _cookiesourcescheme;
    let yojson_of__cookiesourcescheme: _cookiesourcescheme => Yojson.Basic.t;
    /* Represents the source scheme of the origin that originally set the cookie.
       A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
       This is a temporary ability and it will be removed in the future. */
    [@deriving yojson]
    type t = _cookiesourcescheme;
  } = {
    type _cookiesourcescheme = [ | `Unset | `NonSecure | `Secure];
    let _cookiesourcescheme_of_yojson =
      fun
      | `String("Unset") => `Unset
      | `String("NonSecure") => `NonSecure
      | `String("Secure") => `Secure
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__cookiesourcescheme =
      fun
      | `Unset => `String("Unset")
      | `NonSecure => `String("NonSecure")
      | `Secure => `String("Secure");
    /* Represents the source scheme of the origin that originally set the cookie.
       A value of "Unset" allows protocol clients to emulate legacy cookie scope for the scheme.
       This is a temporary ability and it will be removed in the future. */
    [@deriving yojson]
    type t = _cookiesourcescheme;
  }
  and ResourceTiming: {
    /* Timing information for the request. */
    [@deriving yojson]
    type t = {
      [@key "requestTime"]
      requestTime: float, /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. */
      [@key "proxyStart"]
      proxyStart: float, /* Started resolving proxy. */
      [@key "proxyEnd"]
      proxyEnd: float, /* Finished resolving proxy. */
      [@key "dnsStart"]
      dnsStart: float, /* Started DNS address resolve. */
      [@key "dnsEnd"]
      dnsEnd: float, /* Finished DNS address resolve. */
      [@key "connectStart"]
      connectStart: float, /* Started connecting to the remote host. */
      [@key "connectEnd"]
      connectEnd: float, /* Connected to the remote host. */
      [@key "sslStart"]
      sslStart: float, /* Started SSL handshake. */
      [@key "sslEnd"]
      sslEnd: float, /* Finished SSL handshake. */
      [@key "workerStart"]
      workerStart: float, /* Started running ServiceWorker. */
      [@key "workerReady"]
      workerReady: float, /* Finished Starting ServiceWorker. */
      [@key "workerFetchStart"]
      workerFetchStart: float, /* Started fetch event. */
      [@key "workerRespondWithSettled"]
      workerRespondWithSettled: float, /* Settled fetch event respondWith promise. */
      [@key "sendStart"]
      sendStart: float, /* Started sending request. */
      [@key "sendEnd"]
      sendEnd: float, /* Finished sending request. */
      [@key "pushStart"]
      pushStart: float, /* Time the server started pushing request. */
      [@key "pushEnd"]
      pushEnd: float, /* Time the server finished pushing request. */
      [@key "receiveHeadersEnd"]
      receiveHeadersEnd: float /* Finished receiving response headers. */,
    };
  } = {
    /* Timing information for the request. */
    [@deriving yojson]
    type t = {
      [@key "requestTime"]
      requestTime: float, /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. */
      [@key "proxyStart"]
      proxyStart: float, /* Started resolving proxy. */
      [@key "proxyEnd"]
      proxyEnd: float, /* Finished resolving proxy. */
      [@key "dnsStart"]
      dnsStart: float, /* Started DNS address resolve. */
      [@key "dnsEnd"]
      dnsEnd: float, /* Finished DNS address resolve. */
      [@key "connectStart"]
      connectStart: float, /* Started connecting to the remote host. */
      [@key "connectEnd"]
      connectEnd: float, /* Connected to the remote host. */
      [@key "sslStart"]
      sslStart: float, /* Started SSL handshake. */
      [@key "sslEnd"]
      sslEnd: float, /* Finished SSL handshake. */
      [@key "workerStart"]
      workerStart: float, /* Started running ServiceWorker. */
      [@key "workerReady"]
      workerReady: float, /* Finished Starting ServiceWorker. */
      [@key "workerFetchStart"]
      workerFetchStart: float, /* Started fetch event. */
      [@key "workerRespondWithSettled"]
      workerRespondWithSettled: float, /* Settled fetch event respondWith promise. */
      [@key "sendStart"]
      sendStart: float, /* Started sending request. */
      [@key "sendEnd"]
      sendEnd: float, /* Finished sending request. */
      [@key "pushStart"]
      pushStart: float, /* Time the server started pushing request. */
      [@key "pushEnd"]
      pushEnd: float, /* Time the server finished pushing request. */
      [@key "receiveHeadersEnd"]
      receiveHeadersEnd: float /* Finished receiving response headers. */,
    };
  }
  and ResourcePriority: {
    type _resourcepriority = [
      | `VeryLow
      | `Low
      | `Medium
      | `High
      | `VeryHigh
    ];
    let _resourcepriority_of_yojson: Yojson.Basic.t => _resourcepriority;
    let yojson_of__resourcepriority: _resourcepriority => Yojson.Basic.t;
    /* Loading priority of a resource request. */
    [@deriving yojson]
    type t = _resourcepriority;
  } = {
    type _resourcepriority = [
      | `VeryLow
      | `Low
      | `Medium
      | `High
      | `VeryHigh
    ];
    let _resourcepriority_of_yojson =
      fun
      | `String("VeryLow") => `VeryLow
      | `String("Low") => `Low
      | `String("Medium") => `Medium
      | `String("High") => `High
      | `String("VeryHigh") => `VeryHigh
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__resourcepriority =
      fun
      | `VeryLow => `String("VeryLow")
      | `Low => `String("Low")
      | `Medium => `String("Medium")
      | `High => `String("High")
      | `VeryHigh => `String("VeryHigh");
    /* Loading priority of a resource request. */
    [@deriving yojson]
    type t = _resourcepriority;
  }
  and PostDataEntry: {
    /* Post data entry for HTTP request */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "bytes"]
      bytes: option(string) /* No description provided */,
    };
  } = {
    /* Post data entry for HTTP request */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "bytes"]
      bytes: option(string) /* No description provided */,
    };
  }
  and Request: {
    type _request_referrerpolicy = [
      | `unsafe_url
      | `no_referrer_when_downgrade
      | `no_referrer
      | `origin
      | `origin_when_cross_origin
      | `same_origin
      | `strict_origin
      | `strict_origin_when_cross_origin
    ];
    let _request_referrerpolicy_of_yojson:
      Yojson.Basic.t => _request_referrerpolicy;
    let yojson_of__request_referrerpolicy:
      _request_referrerpolicy => Yojson.Basic.t;
    /* HTTP request data. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Request URL (without fragment). */
      [@yojson.option] [@key "urlFragment"]
      urlFragment: option(string), /* Fragment of the requested URL starting with hash, if present. */
      [@key "method"]
      method: string, /* HTTP request method. */
      [@key "headers"]
      headers: Headers.t, /* HTTP request headers. */
      [@yojson.option] [@key "postData"]
      postData: option(string), /* HTTP POST request data. */
      [@yojson.option] [@key "hasPostData"]
      hasPostData: option(bool), /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
      [@yojson.option] [@key "postDataEntries"]
      postDataEntries: option(list(PostDataEntry.t)), /* Request body elements. This will be converted from base64 to binary */
      [@yojson.option] [@key "mixedContentType"]
      mixedContentType: option(Security.MixedContentType.t), /* The mixed content type of the request. */
      [@key "initialPriority"]
      initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
      [@key "referrerPolicy"]
      referrerPolicy: _request_referrerpolicy, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
      [@yojson.option] [@key "isLinkPreload"]
      isLinkPreload: option(bool), /* Whether is loaded via link preload. */
      [@yojson.option] [@key "trustTokenParams"]
      trustTokenParams: option(TrustTokenParams.t), /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */
      [@yojson.option] [@key "isSameSite"]
      isSameSite: option(bool) /* True if this resource request is considered to be the 'same site' as the
request correspondinfg to the main frame. */,
    };
  } = {
    type _request_referrerpolicy = [
      | `unsafe_url
      | `no_referrer_when_downgrade
      | `no_referrer
      | `origin
      | `origin_when_cross_origin
      | `same_origin
      | `strict_origin
      | `strict_origin_when_cross_origin
    ];
    let _request_referrerpolicy_of_yojson =
      fun
      | `String("unsafe-url") => `unsafe_url
      | `String("no-referrer-when-downgrade") => `no_referrer_when_downgrade
      | `String("no-referrer") => `no_referrer
      | `String("origin") => `origin
      | `String("origin-when-cross-origin") => `origin_when_cross_origin
      | `String("same-origin") => `same_origin
      | `String("strict-origin") => `strict_origin
      | `String("strict-origin-when-cross-origin") => `strict_origin_when_cross_origin
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__request_referrerpolicy =
      fun
      | `unsafe_url => `String("unsafe-url")
      | `no_referrer_when_downgrade => `String("no-referrer-when-downgrade")
      | `no_referrer => `String("no-referrer")
      | `origin => `String("origin")
      | `origin_when_cross_origin => `String("origin-when-cross-origin")
      | `same_origin => `String("same-origin")
      | `strict_origin => `String("strict-origin")
      | `strict_origin_when_cross_origin =>
        `String("strict-origin-when-cross-origin");
    /* HTTP request data. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Request URL (without fragment). */
      [@yojson.option] [@key "urlFragment"]
      urlFragment: option(string), /* Fragment of the requested URL starting with hash, if present. */
      [@key "method"]
      method: string, /* HTTP request method. */
      [@key "headers"]
      headers: Headers.t, /* HTTP request headers. */
      [@yojson.option] [@key "postData"]
      postData: option(string), /* HTTP POST request data. */
      [@yojson.option] [@key "hasPostData"]
      hasPostData: option(bool), /* True when the request has POST data. Note that postData might still be omitted when this flag is true when the data is too long. */
      [@yojson.option] [@key "postDataEntries"]
      postDataEntries: option(list(PostDataEntry.t)), /* Request body elements. This will be converted from base64 to binary */
      [@yojson.option] [@key "mixedContentType"]
      mixedContentType: option(Security.MixedContentType.t), /* The mixed content type of the request. */
      [@key "initialPriority"]
      initialPriority: ResourcePriority.t, /* Priority of the resource request at the time request is sent. */
      [@key "referrerPolicy"]
      referrerPolicy: _request_referrerpolicy, /* The referrer policy of the request, as defined in https://www.w3.org/TR/referrer-policy/ */
      [@yojson.option] [@key "isLinkPreload"]
      isLinkPreload: option(bool), /* Whether is loaded via link preload. */
      [@yojson.option] [@key "trustTokenParams"]
      trustTokenParams: option(TrustTokenParams.t), /* Set for requests when the TrustToken API is used. Contains the parameters
passed by the developer (e.g. via "fetch") as understood by the backend. */
      [@yojson.option] [@key "isSameSite"]
      isSameSite: option(bool) /* True if this resource request is considered to be the 'same site' as the
request correspondinfg to the main frame. */,
    };
  }
  and SignedCertificateTimestamp: {
    /* Details of a signed certificate timestamp (SCT). */
    [@deriving yojson]
    type t = {
      [@key "status"]
      status: string, /* Validation status. */
      [@key "origin"]
      origin: string, /* Origin. */
      [@key "logDescription"]
      logDescription: string, /* Log name / description. */
      [@key "logId"]
      logId: string, /* Log ID. */
      [@key "timestamp"]
      timestamp: float, /* Issuance date. Unlike TimeSinceEpoch, this contains the number of
milliseconds since January 1, 1970, UTC, not the number of seconds. */
      [@key "hashAlgorithm"]
      hashAlgorithm: string, /* Hash algorithm. */
      [@key "signatureAlgorithm"]
      signatureAlgorithm: string, /* Signature algorithm. */
      [@key "signatureData"]
      signatureData: string /* Signature data. */,
    };
  } = {
    /* Details of a signed certificate timestamp (SCT). */
    [@deriving yojson]
    type t = {
      [@key "status"]
      status: string, /* Validation status. */
      [@key "origin"]
      origin: string, /* Origin. */
      [@key "logDescription"]
      logDescription: string, /* Log name / description. */
      [@key "logId"]
      logId: string, /* Log ID. */
      [@key "timestamp"]
      timestamp: float, /* Issuance date. Unlike TimeSinceEpoch, this contains the number of
milliseconds since January 1, 1970, UTC, not the number of seconds. */
      [@key "hashAlgorithm"]
      hashAlgorithm: string, /* Hash algorithm. */
      [@key "signatureAlgorithm"]
      signatureAlgorithm: string, /* Signature algorithm. */
      [@key "signatureData"]
      signatureData: string /* Signature data. */,
    };
  }
  and SecurityDetails: {
    /* Security details about a request. */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
      [@key "keyExchange"]
      keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
      [@yojson.option] [@key "keyExchangeGroup"]
      keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
      [@key "cipher"]
      cipher: string, /* Cipher name. */
      [@yojson.option] [@key "mac"]
      mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
      [@key "certificateId"]
      certificateId: Security.CertificateId.t, /* Certificate ID value. */
      [@key "subjectName"]
      subjectName: string, /* Certificate subject name. */
      [@key "sanList"]
      sanList: list(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
      [@key "issuer"]
      issuer: string, /* Name of the issuing CA. */
      [@key "validFrom"]
      validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
      [@key "validTo"]
      validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
      [@key "signedCertificateTimestampList"]
      signedCertificateTimestampList: list(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
      [@key "certificateTransparencyCompliance"]
      certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
    };
  } = {
    /* Security details about a request. */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
      [@key "keyExchange"]
      keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
      [@yojson.option] [@key "keyExchangeGroup"]
      keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
      [@key "cipher"]
      cipher: string, /* Cipher name. */
      [@yojson.option] [@key "mac"]
      mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
      [@key "certificateId"]
      certificateId: Security.CertificateId.t, /* Certificate ID value. */
      [@key "subjectName"]
      subjectName: string, /* Certificate subject name. */
      [@key "sanList"]
      sanList: list(string), /* Subject Alternative Name (SAN) DNS names and IP addresses. */
      [@key "issuer"]
      issuer: string, /* Name of the issuing CA. */
      [@key "validFrom"]
      validFrom: TimeSinceEpoch.t, /* Certificate valid from date. */
      [@key "validTo"]
      validTo: TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
      [@key "signedCertificateTimestampList"]
      signedCertificateTimestampList: list(SignedCertificateTimestamp.t), /* List of signed certificate timestamps (SCTs). */
      [@key "certificateTransparencyCompliance"]
      certificateTransparencyCompliance: CertificateTransparencyCompliance.t /* Whether the request complied with Certificate Transparency policy */,
    };
  }
  and CertificateTransparencyCompliance: {
    type _certificatetransparencycompliance = [
      | `unknown
      | `not_compliant
      | `compliant
    ];
    let _certificatetransparencycompliance_of_yojson:
      Yojson.Basic.t => _certificatetransparencycompliance;
    let yojson_of__certificatetransparencycompliance:
      _certificatetransparencycompliance => Yojson.Basic.t;
    /* Whether the request complied with Certificate Transparency policy. */
    [@deriving yojson]
    type t = _certificatetransparencycompliance;
  } = {
    type _certificatetransparencycompliance = [
      | `unknown
      | `not_compliant
      | `compliant
    ];
    let _certificatetransparencycompliance_of_yojson =
      fun
      | `String("unknown") => `unknown
      | `String("not-compliant") => `not_compliant
      | `String("compliant") => `compliant
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__certificatetransparencycompliance =
      fun
      | `unknown => `String("unknown")
      | `not_compliant => `String("not-compliant")
      | `compliant => `String("compliant");
    /* Whether the request complied with Certificate Transparency policy. */
    [@deriving yojson]
    type t = _certificatetransparencycompliance;
  }
  and BlockedReason: {
    type _blockedreason = [
      | `other
      | `csp
      | `mixed_content
      | `origin
      | `inspector
      | `subresource_filter
      | `content_type
      | `coep_frame_resource_needs_coep_header
      | `coop_sandboxed_iframe_cannot_navigate_to_coop_page
      | `corp_not_same_origin
      | `corp_not_same_origin_after_defaulted_to_same_origin_by_coep
      | `corp_not_same_site
    ];
    let _blockedreason_of_yojson: Yojson.Basic.t => _blockedreason;
    let yojson_of__blockedreason: _blockedreason => Yojson.Basic.t;
    /* The reason why request was blocked. */
    [@deriving yojson]
    type t = _blockedreason;
  } = {
    type _blockedreason = [
      | `other
      | `csp
      | `mixed_content
      | `origin
      | `inspector
      | `subresource_filter
      | `content_type
      | `coep_frame_resource_needs_coep_header
      | `coop_sandboxed_iframe_cannot_navigate_to_coop_page
      | `corp_not_same_origin
      | `corp_not_same_origin_after_defaulted_to_same_origin_by_coep
      | `corp_not_same_site
    ];
    let _blockedreason_of_yojson =
      fun
      | `String("other") => `other
      | `String("csp") => `csp
      | `String("mixed-content") => `mixed_content
      | `String("origin") => `origin
      | `String("inspector") => `inspector
      | `String("subresource-filter") => `subresource_filter
      | `String("content-type") => `content_type
      | `String("coep-frame-resource-needs-coep-header") => `coep_frame_resource_needs_coep_header
      | `String("coop-sandboxed-iframe-cannot-navigate-to-coop-page") => `coop_sandboxed_iframe_cannot_navigate_to_coop_page
      | `String("corp-not-same-origin") => `corp_not_same_origin
      | `String("corp-not-same-origin-after-defaulted-to-same-origin-by-coep") => `corp_not_same_origin_after_defaulted_to_same_origin_by_coep
      | `String("corp-not-same-site") => `corp_not_same_site
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__blockedreason =
      fun
      | `other => `String("other")
      | `csp => `String("csp")
      | `mixed_content => `String("mixed-content")
      | `origin => `String("origin")
      | `inspector => `String("inspector")
      | `subresource_filter => `String("subresource-filter")
      | `content_type => `String("content-type")
      | `coep_frame_resource_needs_coep_header =>
        `String("coep-frame-resource-needs-coep-header")
      | `coop_sandboxed_iframe_cannot_navigate_to_coop_page =>
        `String("coop-sandboxed-iframe-cannot-navigate-to-coop-page")
      | `corp_not_same_origin => `String("corp-not-same-origin")
      | `corp_not_same_origin_after_defaulted_to_same_origin_by_coep =>
        `String("corp-not-same-origin-after-defaulted-to-same-origin-by-coep")
      | `corp_not_same_site => `String("corp-not-same-site");
    /* The reason why request was blocked. */
    [@deriving yojson]
    type t = _blockedreason;
  }
  and CorsError: {
    type _corserror = [
      | `DisallowedByMode
      | `InvalidResponse
      | `WildcardOriginNotAllowed
      | `MissingAllowOriginHeader
      | `MultipleAllowOriginValues
      | `InvalidAllowOriginValue
      | `AllowOriginMismatch
      | `InvalidAllowCredentials
      | `CorsDisabledScheme
      | `PreflightInvalidStatus
      | `PreflightDisallowedRedirect
      | `PreflightWildcardOriginNotAllowed
      | `PreflightMissingAllowOriginHeader
      | `PreflightMultipleAllowOriginValues
      | `PreflightInvalidAllowOriginValue
      | `PreflightAllowOriginMismatch
      | `PreflightInvalidAllowCredentials
      | `PreflightMissingAllowExternal
      | `PreflightInvalidAllowExternal
      | `InvalidAllowMethodsPreflightResponse
      | `InvalidAllowHeadersPreflightResponse
      | `MethodDisallowedByPreflightResponse
      | `HeaderDisallowedByPreflightResponse
      | `RedirectContainsCredentials
      | `InsecurePrivateNetwork
      | `InvalidPrivateNetworkAccess
      | `UnexpectedPrivateNetworkAccess
      | `NoCorsRedirectModeNotFollow
    ];
    let _corserror_of_yojson: Yojson.Basic.t => _corserror;
    let yojson_of__corserror: _corserror => Yojson.Basic.t;
    /* The reason why request was blocked. */
    [@deriving yojson]
    type t = _corserror;
  } = {
    type _corserror = [
      | `DisallowedByMode
      | `InvalidResponse
      | `WildcardOriginNotAllowed
      | `MissingAllowOriginHeader
      | `MultipleAllowOriginValues
      | `InvalidAllowOriginValue
      | `AllowOriginMismatch
      | `InvalidAllowCredentials
      | `CorsDisabledScheme
      | `PreflightInvalidStatus
      | `PreflightDisallowedRedirect
      | `PreflightWildcardOriginNotAllowed
      | `PreflightMissingAllowOriginHeader
      | `PreflightMultipleAllowOriginValues
      | `PreflightInvalidAllowOriginValue
      | `PreflightAllowOriginMismatch
      | `PreflightInvalidAllowCredentials
      | `PreflightMissingAllowExternal
      | `PreflightInvalidAllowExternal
      | `InvalidAllowMethodsPreflightResponse
      | `InvalidAllowHeadersPreflightResponse
      | `MethodDisallowedByPreflightResponse
      | `HeaderDisallowedByPreflightResponse
      | `RedirectContainsCredentials
      | `InsecurePrivateNetwork
      | `InvalidPrivateNetworkAccess
      | `UnexpectedPrivateNetworkAccess
      | `NoCorsRedirectModeNotFollow
    ];
    let _corserror_of_yojson =
      fun
      | `String("DisallowedByMode") => `DisallowedByMode
      | `String("InvalidResponse") => `InvalidResponse
      | `String("WildcardOriginNotAllowed") => `WildcardOriginNotAllowed
      | `String("MissingAllowOriginHeader") => `MissingAllowOriginHeader
      | `String("MultipleAllowOriginValues") => `MultipleAllowOriginValues
      | `String("InvalidAllowOriginValue") => `InvalidAllowOriginValue
      | `String("AllowOriginMismatch") => `AllowOriginMismatch
      | `String("InvalidAllowCredentials") => `InvalidAllowCredentials
      | `String("CorsDisabledScheme") => `CorsDisabledScheme
      | `String("PreflightInvalidStatus") => `PreflightInvalidStatus
      | `String("PreflightDisallowedRedirect") => `PreflightDisallowedRedirect
      | `String("PreflightWildcardOriginNotAllowed") => `PreflightWildcardOriginNotAllowed
      | `String("PreflightMissingAllowOriginHeader") => `PreflightMissingAllowOriginHeader
      | `String("PreflightMultipleAllowOriginValues") => `PreflightMultipleAllowOriginValues
      | `String("PreflightInvalidAllowOriginValue") => `PreflightInvalidAllowOriginValue
      | `String("PreflightAllowOriginMismatch") => `PreflightAllowOriginMismatch
      | `String("PreflightInvalidAllowCredentials") => `PreflightInvalidAllowCredentials
      | `String("PreflightMissingAllowExternal") => `PreflightMissingAllowExternal
      | `String("PreflightInvalidAllowExternal") => `PreflightInvalidAllowExternal
      | `String("InvalidAllowMethodsPreflightResponse") => `InvalidAllowMethodsPreflightResponse
      | `String("InvalidAllowHeadersPreflightResponse") => `InvalidAllowHeadersPreflightResponse
      | `String("MethodDisallowedByPreflightResponse") => `MethodDisallowedByPreflightResponse
      | `String("HeaderDisallowedByPreflightResponse") => `HeaderDisallowedByPreflightResponse
      | `String("RedirectContainsCredentials") => `RedirectContainsCredentials
      | `String("InsecurePrivateNetwork") => `InsecurePrivateNetwork
      | `String("InvalidPrivateNetworkAccess") => `InvalidPrivateNetworkAccess
      | `String("UnexpectedPrivateNetworkAccess") => `UnexpectedPrivateNetworkAccess
      | `String("NoCorsRedirectModeNotFollow") => `NoCorsRedirectModeNotFollow
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__corserror =
      fun
      | `DisallowedByMode => `String("DisallowedByMode")
      | `InvalidResponse => `String("InvalidResponse")
      | `WildcardOriginNotAllowed => `String("WildcardOriginNotAllowed")
      | `MissingAllowOriginHeader => `String("MissingAllowOriginHeader")
      | `MultipleAllowOriginValues => `String("MultipleAllowOriginValues")
      | `InvalidAllowOriginValue => `String("InvalidAllowOriginValue")
      | `AllowOriginMismatch => `String("AllowOriginMismatch")
      | `InvalidAllowCredentials => `String("InvalidAllowCredentials")
      | `CorsDisabledScheme => `String("CorsDisabledScheme")
      | `PreflightInvalidStatus => `String("PreflightInvalidStatus")
      | `PreflightDisallowedRedirect => `String("PreflightDisallowedRedirect")
      | `PreflightWildcardOriginNotAllowed =>
        `String("PreflightWildcardOriginNotAllowed")
      | `PreflightMissingAllowOriginHeader =>
        `String("PreflightMissingAllowOriginHeader")
      | `PreflightMultipleAllowOriginValues =>
        `String("PreflightMultipleAllowOriginValues")
      | `PreflightInvalidAllowOriginValue =>
        `String("PreflightInvalidAllowOriginValue")
      | `PreflightAllowOriginMismatch =>
        `String("PreflightAllowOriginMismatch")
      | `PreflightInvalidAllowCredentials =>
        `String("PreflightInvalidAllowCredentials")
      | `PreflightMissingAllowExternal =>
        `String("PreflightMissingAllowExternal")
      | `PreflightInvalidAllowExternal =>
        `String("PreflightInvalidAllowExternal")
      | `InvalidAllowMethodsPreflightResponse =>
        `String("InvalidAllowMethodsPreflightResponse")
      | `InvalidAllowHeadersPreflightResponse =>
        `String("InvalidAllowHeadersPreflightResponse")
      | `MethodDisallowedByPreflightResponse =>
        `String("MethodDisallowedByPreflightResponse")
      | `HeaderDisallowedByPreflightResponse =>
        `String("HeaderDisallowedByPreflightResponse")
      | `RedirectContainsCredentials => `String("RedirectContainsCredentials")
      | `InsecurePrivateNetwork => `String("InsecurePrivateNetwork")
      | `InvalidPrivateNetworkAccess => `String("InvalidPrivateNetworkAccess")
      | `UnexpectedPrivateNetworkAccess =>
        `String("UnexpectedPrivateNetworkAccess")
      | `NoCorsRedirectModeNotFollow =>
        `String("NoCorsRedirectModeNotFollow");
    /* The reason why request was blocked. */
    [@deriving yojson]
    type t = _corserror;
  }
  and CorsErrorStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "corsError"]
      corsError: CorsError.t, /* No description provided */
      [@key "failedParameter"]
      failedParameter: string /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "corsError"]
      corsError: CorsError.t, /* No description provided */
      [@key "failedParameter"]
      failedParameter: string /* No description provided */,
    };
  }
  and ServiceWorkerResponseSource: {
    type _serviceworkerresponsesource = [
      | `cache_storage
      | `http_cache
      | `fallback_code
      | `network
    ];
    let _serviceworkerresponsesource_of_yojson:
      Yojson.Basic.t => _serviceworkerresponsesource;
    let yojson_of__serviceworkerresponsesource:
      _serviceworkerresponsesource => Yojson.Basic.t;
    /* Source of serviceworker response. */
    [@deriving yojson]
    type t = _serviceworkerresponsesource;
  } = {
    type _serviceworkerresponsesource = [
      | `cache_storage
      | `http_cache
      | `fallback_code
      | `network
    ];
    let _serviceworkerresponsesource_of_yojson =
      fun
      | `String("cache-storage") => `cache_storage
      | `String("http-cache") => `http_cache
      | `String("fallback-code") => `fallback_code
      | `String("network") => `network
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__serviceworkerresponsesource =
      fun
      | `cache_storage => `String("cache-storage")
      | `http_cache => `String("http-cache")
      | `fallback_code => `String("fallback-code")
      | `network => `String("network");
    /* Source of serviceworker response. */
    [@deriving yojson]
    type t = _serviceworkerresponsesource;
  }
  and TrustTokenParams: {
    type _trusttokenparams_refreshpolicy = [ | `UseCached | `Refresh];
    let _trusttokenparams_refreshpolicy_of_yojson:
      Yojson.Basic.t => _trusttokenparams_refreshpolicy;
    let yojson_of__trusttokenparams_refreshpolicy:
      _trusttokenparams_refreshpolicy => Yojson.Basic.t;
    /* Determines what type of Trust Token operation is executed and
       depending on the type, some additional parameters. The values
       are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: TrustTokenOperationType.t, /* No description provided */
      [@key "refreshPolicy"]
      refreshPolicy: _trusttokenparams_refreshpolicy, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
      [@yojson.option] [@key "issuers"]
      issuers: option(list(string)) /* Origins of issuers from whom to request tokens or redemption
records. */,
    };
  } = {
    type _trusttokenparams_refreshpolicy = [ | `UseCached | `Refresh];
    let _trusttokenparams_refreshpolicy_of_yojson =
      fun
      | `String("UseCached") => `UseCached
      | `String("Refresh") => `Refresh
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__trusttokenparams_refreshpolicy =
      fun
      | `UseCached => `String("UseCached")
      | `Refresh => `String("Refresh");
    /* Determines what type of Trust Token operation is executed and
       depending on the type, some additional parameters. The values
       are specified in third_party/blink/renderer/core/fetch/trust_token.idl. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: TrustTokenOperationType.t, /* No description provided */
      [@key "refreshPolicy"]
      refreshPolicy: _trusttokenparams_refreshpolicy, /* Only set for "token-redemption" type and determine whether
to request a fresh SRR or use a still valid cached SRR. */
      [@yojson.option] [@key "issuers"]
      issuers: option(list(string)) /* Origins of issuers from whom to request tokens or redemption
records. */,
    };
  }
  and TrustTokenOperationType: {
    type _trusttokenoperationtype = [ | `Issuance | `Redemption | `Signing];
    let _trusttokenoperationtype_of_yojson:
      Yojson.Basic.t => _trusttokenoperationtype;
    let yojson_of__trusttokenoperationtype:
      _trusttokenoperationtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _trusttokenoperationtype;
  } = {
    type _trusttokenoperationtype = [ | `Issuance | `Redemption | `Signing];
    let _trusttokenoperationtype_of_yojson =
      fun
      | `String("Issuance") => `Issuance
      | `String("Redemption") => `Redemption
      | `String("Signing") => `Signing
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__trusttokenoperationtype =
      fun
      | `Issuance => `String("Issuance")
      | `Redemption => `String("Redemption")
      | `Signing => `String("Signing");
    /* No description provided */
    [@deriving yojson]
    type t = _trusttokenoperationtype;
  }
  and Response: {
    /* HTTP response data. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
      [@key "status"]
      status: float, /* HTTP response status code. */
      [@key "statusText"]
      statusText: string, /* HTTP response status text. */
      [@key "headers"]
      headers: Headers.t, /* HTTP response headers. */
      [@yojson.option] [@key "headersText"]
      headersText: option(string), /* HTTP response headers text. This has been replaced by the headers in Network.responseReceivedExtraInfo. */
      [@key "mimeType"]
      mimeType: string, /* Resource mimeType as determined by the browser. */
      [@yojson.option] [@key "requestHeaders"]
      requestHeaders: option(Headers.t), /* Refined HTTP request headers that were actually transmitted over the network. */
      [@yojson.option] [@key "requestHeadersText"]
      requestHeadersText: option(string), /* HTTP request headers text. This has been replaced by the headers in Network.requestWillBeSentExtraInfo. */
      [@key "connectionReused"]
      connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
      [@key "connectionId"]
      connectionId: float, /* Physical connection id that was actually used for this request. */
      [@yojson.option] [@key "remoteIPAddress"]
      remoteIPAddress: option(string), /* Remote IP address. */
      [@yojson.option] [@key "remotePort"]
      remotePort: option(float), /* Remote port. */
      [@yojson.option] [@key "fromDiskCache"]
      fromDiskCache: option(bool), /* Specifies that the request was served from the disk cache. */
      [@yojson.option] [@key "fromServiceWorker"]
      fromServiceWorker: option(bool), /* Specifies that the request was served from the ServiceWorker. */
      [@yojson.option] [@key "fromPrefetchCache"]
      fromPrefetchCache: option(bool), /* Specifies that the request was served from the prefetch cache. */
      [@key "encodedDataLength"]
      encodedDataLength: float, /* Total number of bytes received for this request so far. */
      [@yojson.option] [@key "timing"]
      timing: option(ResourceTiming.t), /* Timing information for the given request. */
      [@yojson.option] [@key "serviceWorkerResponseSource"]
      serviceWorkerResponseSource: option(ServiceWorkerResponseSource.t), /* Response source of response from ServiceWorker. */
      [@yojson.option] [@key "responseTime"]
      responseTime: option(TimeSinceEpoch.t), /* The time at which the returned response was generated. */
      [@yojson.option] [@key "cacheStorageCacheName"]
      cacheStorageCacheName: option(string), /* Cache Storage Cache Name. */
      [@yojson.option] [@key "protocol"]
      protocol: option(string), /* Protocol used to fetch this request. */
      [@key "securityState"]
      securityState: Security.SecurityState.t, /* Security state of the request resource. */
      [@yojson.option] [@key "securityDetails"]
      securityDetails: option(SecurityDetails.t) /* Security details for the request. */,
    };
  } = {
    /* HTTP response data. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Response URL. This URL can be different from CachedResource.url in case of redirect. */
      [@key "status"]
      status: float, /* HTTP response status code. */
      [@key "statusText"]
      statusText: string, /* HTTP response status text. */
      [@key "headers"]
      headers: Headers.t, /* HTTP response headers. */
      [@yojson.option] [@key "headersText"]
      headersText: option(string), /* HTTP response headers text. This has been replaced by the headers in Network.responseReceivedExtraInfo. */
      [@key "mimeType"]
      mimeType: string, /* Resource mimeType as determined by the browser. */
      [@yojson.option] [@key "requestHeaders"]
      requestHeaders: option(Headers.t), /* Refined HTTP request headers that were actually transmitted over the network. */
      [@yojson.option] [@key "requestHeadersText"]
      requestHeadersText: option(string), /* HTTP request headers text. This has been replaced by the headers in Network.requestWillBeSentExtraInfo. */
      [@key "connectionReused"]
      connectionReused: bool, /* Specifies whether physical connection was actually reused for this request. */
      [@key "connectionId"]
      connectionId: float, /* Physical connection id that was actually used for this request. */
      [@yojson.option] [@key "remoteIPAddress"]
      remoteIPAddress: option(string), /* Remote IP address. */
      [@yojson.option] [@key "remotePort"]
      remotePort: option(float), /* Remote port. */
      [@yojson.option] [@key "fromDiskCache"]
      fromDiskCache: option(bool), /* Specifies that the request was served from the disk cache. */
      [@yojson.option] [@key "fromServiceWorker"]
      fromServiceWorker: option(bool), /* Specifies that the request was served from the ServiceWorker. */
      [@yojson.option] [@key "fromPrefetchCache"]
      fromPrefetchCache: option(bool), /* Specifies that the request was served from the prefetch cache. */
      [@key "encodedDataLength"]
      encodedDataLength: float, /* Total number of bytes received for this request so far. */
      [@yojson.option] [@key "timing"]
      timing: option(ResourceTiming.t), /* Timing information for the given request. */
      [@yojson.option] [@key "serviceWorkerResponseSource"]
      serviceWorkerResponseSource: option(ServiceWorkerResponseSource.t), /* Response source of response from ServiceWorker. */
      [@yojson.option] [@key "responseTime"]
      responseTime: option(TimeSinceEpoch.t), /* The time at which the returned response was generated. */
      [@yojson.option] [@key "cacheStorageCacheName"]
      cacheStorageCacheName: option(string), /* Cache Storage Cache Name. */
      [@yojson.option] [@key "protocol"]
      protocol: option(string), /* Protocol used to fetch this request. */
      [@key "securityState"]
      securityState: Security.SecurityState.t, /* Security state of the request resource. */
      [@yojson.option] [@key "securityDetails"]
      securityDetails: option(SecurityDetails.t) /* Security details for the request. */,
    };
  }
  and WebSocketRequest: {
    /* WebSocket request data. */
    [@deriving yojson]
    type t = {
      [@key "headers"]
      headers: Headers.t /* HTTP request headers. */,
    };
  } = {
    /* WebSocket request data. */
    [@deriving yojson]
    type t = {
      [@key "headers"]
      headers: Headers.t /* HTTP request headers. */,
    };
  }
  and WebSocketResponse: {
    /* WebSocket response data. */
    [@deriving yojson]
    type t = {
      [@key "status"]
      status: float, /* HTTP response status code. */
      [@key "statusText"]
      statusText: string, /* HTTP response status text. */
      [@key "headers"]
      headers: Headers.t, /* HTTP response headers. */
      [@yojson.option] [@key "headersText"]
      headersText: option(string), /* HTTP response headers text. */
      [@yojson.option] [@key "requestHeaders"]
      requestHeaders: option(Headers.t), /* HTTP request headers. */
      [@yojson.option] [@key "requestHeadersText"]
      requestHeadersText: option(string) /* HTTP request headers text. */,
    };
  } = {
    /* WebSocket response data. */
    [@deriving yojson]
    type t = {
      [@key "status"]
      status: float, /* HTTP response status code. */
      [@key "statusText"]
      statusText: string, /* HTTP response status text. */
      [@key "headers"]
      headers: Headers.t, /* HTTP response headers. */
      [@yojson.option] [@key "headersText"]
      headersText: option(string), /* HTTP response headers text. */
      [@yojson.option] [@key "requestHeaders"]
      requestHeaders: option(Headers.t), /* HTTP request headers. */
      [@yojson.option] [@key "requestHeadersText"]
      requestHeadersText: option(string) /* HTTP request headers text. */,
    };
  }
  and WebSocketFrame: {
    /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
    [@deriving yojson]
    type t = {
      [@key "opcode"]
      opcode: float, /* WebSocket message opcode. */
      [@key "mask"]
      mask: bool, /* WebSocket message mask. */
      [@key "payloadData"]
      payloadData: string /* WebSocket message payload data.
If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data. */,
    };
  } = {
    /* WebSocket message data. This represents an entire WebSocket message, not just a fragmented frame as the name suggests. */
    [@deriving yojson]
    type t = {
      [@key "opcode"]
      opcode: float, /* WebSocket message opcode. */
      [@key "mask"]
      mask: bool, /* WebSocket message mask. */
      [@key "payloadData"]
      payloadData: string /* WebSocket message payload data.
If the opcode is 1, this is a text message and payloadData is a UTF-8 string.
If the opcode isn't 1, then payloadData is a base64 encoded string representing binary data. */,
    };
  }
  and CachedResource: {
    /* Information about the cached resource. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Resource URL. This is the url of the original network request. */
      [@key "type"]
      type_: ResourceType.t, /* Type of this resource. */
      [@yojson.option] [@key "response"]
      response: option(Response.t), /* Cached response data. */
      [@key "bodySize"]
      bodySize: float /* Cached response body size. */,
    };
  } = {
    /* Information about the cached resource. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Resource URL. This is the url of the original network request. */
      [@key "type"]
      type_: ResourceType.t, /* Type of this resource. */
      [@yojson.option] [@key "response"]
      response: option(Response.t), /* Cached response data. */
      [@key "bodySize"]
      bodySize: float /* Cached response body size. */,
    };
  }
  and Initiator: {
    type _initiator_type = [
      | `parser
      | `script
      | `preload
      | `SignedExchange
      | `preflight
      | `other
    ];
    let _initiator_type_of_yojson: Yojson.Basic.t => _initiator_type;
    let yojson_of__initiator_type: _initiator_type => Yojson.Basic.t;
    /* Information about the request initiator. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _initiator_type, /* Type of this initiator. */
      [@yojson.option] [@key "stack"]
      stack: option(Runtime.StackTrace.t), /* Initiator JavaScript stack trace, set for Script only. */
      [@yojson.option] [@key "url"]
      url: option(string), /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
      [@yojson.option] [@key "lineNumber"]
      lineNumber: option(float), /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float), /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
      [@yojson.option] [@key "requestId"]
      requestId: option(RequestId.t) /* Set if another request triggered this request (e.g. preflight). */,
    };
  } = {
    type _initiator_type = [
      | `parser
      | `script
      | `preload
      | `SignedExchange
      | `preflight
      | `other
    ];
    let _initiator_type_of_yojson =
      fun
      | `String("parser") => `parser
      | `String("script") => `script
      | `String("preload") => `preload
      | `String("SignedExchange") => `SignedExchange
      | `String("preflight") => `preflight
      | `String("other") => `other
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__initiator_type =
      fun
      | `parser => `String("parser")
      | `script => `String("script")
      | `preload => `String("preload")
      | `SignedExchange => `String("SignedExchange")
      | `preflight => `String("preflight")
      | `other => `String("other");
    /* Information about the request initiator. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _initiator_type, /* Type of this initiator. */
      [@yojson.option] [@key "stack"]
      stack: option(Runtime.StackTrace.t), /* Initiator JavaScript stack trace, set for Script only. */
      [@yojson.option] [@key "url"]
      url: option(string), /* Initiator URL, set for Parser type or for Script type (when script is importing module) or for SignedExchange type. */
      [@yojson.option] [@key "lineNumber"]
      lineNumber: option(float), /* Initiator line number, set for Parser type or for Script type (when script is importing
module) (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float), /* Initiator column number, set for Parser type or for Script type (when script is importing
module) (0-based). */
      [@yojson.option] [@key "requestId"]
      requestId: option(RequestId.t) /* Set if another request triggered this request (e.g. preflight). */,
    };
  }
  and Cookie: {
    /* Cookie object */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Cookie name. */
      [@key "value"]
      value: string, /* Cookie value. */
      [@key "domain"]
      domain: string, /* Cookie domain. */
      [@key "path"]
      path: string, /* Cookie path. */
      [@key "expires"]
      expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
      [@key "size"]
      size: float, /* Cookie size. */
      [@key "httpOnly"]
      httpOnly: bool, /* True if cookie is http-only. */
      [@key "secure"]
      secure: bool, /* True if cookie is secure. */
      [@key "session"]
      session: bool, /* True in case of session cookie. */
      [@yojson.option] [@key "sameSite"]
      sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
      [@key "priority"]
      priority: CookiePriority.t, /* Cookie Priority */
      [@key "sameParty"]
      sameParty: bool, /* True if cookie is SameParty. */
      [@key "sourceScheme"]
      sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
      [@key "sourcePort"]
      sourcePort: float, /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */
      [@yojson.option] [@key "partitionKey"]
      partitionKey: option(string), /* Cookie partition key. The site of the top-level URL the browser was visiting at the start
of the request to the endpoint that set the cookie. */
      [@yojson.option] [@key "partitionKeyOpaque"]
      partitionKeyOpaque: option(bool) /* True if cookie partition key is opaque. */,
    };
  } = {
    /* Cookie object */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Cookie name. */
      [@key "value"]
      value: string, /* Cookie value. */
      [@key "domain"]
      domain: string, /* Cookie domain. */
      [@key "path"]
      path: string, /* Cookie path. */
      [@key "expires"]
      expires: float, /* Cookie expiration date as the number of seconds since the UNIX epoch. */
      [@key "size"]
      size: float, /* Cookie size. */
      [@key "httpOnly"]
      httpOnly: bool, /* True if cookie is http-only. */
      [@key "secure"]
      secure: bool, /* True if cookie is secure. */
      [@key "session"]
      session: bool, /* True in case of session cookie. */
      [@yojson.option] [@key "sameSite"]
      sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
      [@key "priority"]
      priority: CookiePriority.t, /* Cookie Priority */
      [@key "sameParty"]
      sameParty: bool, /* True if cookie is SameParty. */
      [@key "sourceScheme"]
      sourceScheme: CookieSourceScheme.t, /* Cookie source scheme type. */
      [@key "sourcePort"]
      sourcePort: float, /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */
      [@yojson.option] [@key "partitionKey"]
      partitionKey: option(string), /* Cookie partition key. The site of the top-level URL the browser was visiting at the start
of the request to the endpoint that set the cookie. */
      [@yojson.option] [@key "partitionKeyOpaque"]
      partitionKeyOpaque: option(bool) /* True if cookie partition key is opaque. */,
    };
  }
  and SetCookieBlockedReason: {
    type _setcookieblockedreason = [
      | `SecureOnly
      | `SameSiteStrict
      | `SameSiteLax
      | `SameSiteUnspecifiedTreatedAsLax
      | `SameSiteNoneInsecure
      | `UserPreferences
      | `SyntaxError
      | `SchemeNotSupported
      | `OverwriteSecure
      | `InvalidDomain
      | `InvalidPrefix
      | `UnknownError
      | `SchemefulSameSiteStrict
      | `SchemefulSameSiteLax
      | `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `SamePartyFromCrossPartyContext
      | `SamePartyConflictsWithOtherAttributes
      | `NameValuePairExceedsMaxSize
    ];
    let _setcookieblockedreason_of_yojson:
      Yojson.Basic.t => _setcookieblockedreason;
    let yojson_of__setcookieblockedreason:
      _setcookieblockedreason => Yojson.Basic.t;
    /* Types of reasons why a cookie may not be stored from a response. */
    [@deriving yojson]
    type t = _setcookieblockedreason;
  } = {
    type _setcookieblockedreason = [
      | `SecureOnly
      | `SameSiteStrict
      | `SameSiteLax
      | `SameSiteUnspecifiedTreatedAsLax
      | `SameSiteNoneInsecure
      | `UserPreferences
      | `SyntaxError
      | `SchemeNotSupported
      | `OverwriteSecure
      | `InvalidDomain
      | `InvalidPrefix
      | `UnknownError
      | `SchemefulSameSiteStrict
      | `SchemefulSameSiteLax
      | `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `SamePartyFromCrossPartyContext
      | `SamePartyConflictsWithOtherAttributes
      | `NameValuePairExceedsMaxSize
    ];
    let _setcookieblockedreason_of_yojson =
      fun
      | `String("SecureOnly") => `SecureOnly
      | `String("SameSiteStrict") => `SameSiteStrict
      | `String("SameSiteLax") => `SameSiteLax
      | `String("SameSiteUnspecifiedTreatedAsLax") => `SameSiteUnspecifiedTreatedAsLax
      | `String("SameSiteNoneInsecure") => `SameSiteNoneInsecure
      | `String("UserPreferences") => `UserPreferences
      | `String("SyntaxError") => `SyntaxError
      | `String("SchemeNotSupported") => `SchemeNotSupported
      | `String("OverwriteSecure") => `OverwriteSecure
      | `String("InvalidDomain") => `InvalidDomain
      | `String("InvalidPrefix") => `InvalidPrefix
      | `String("UnknownError") => `UnknownError
      | `String("SchemefulSameSiteStrict") => `SchemefulSameSiteStrict
      | `String("SchemefulSameSiteLax") => `SchemefulSameSiteLax
      | `String("SchemefulSameSiteUnspecifiedTreatedAsLax") => `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `String("SamePartyFromCrossPartyContext") => `SamePartyFromCrossPartyContext
      | `String("SamePartyConflictsWithOtherAttributes") => `SamePartyConflictsWithOtherAttributes
      | `String("NameValuePairExceedsMaxSize") => `NameValuePairExceedsMaxSize
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__setcookieblockedreason =
      fun
      | `SecureOnly => `String("SecureOnly")
      | `SameSiteStrict => `String("SameSiteStrict")
      | `SameSiteLax => `String("SameSiteLax")
      | `SameSiteUnspecifiedTreatedAsLax =>
        `String("SameSiteUnspecifiedTreatedAsLax")
      | `SameSiteNoneInsecure => `String("SameSiteNoneInsecure")
      | `UserPreferences => `String("UserPreferences")
      | `SyntaxError => `String("SyntaxError")
      | `SchemeNotSupported => `String("SchemeNotSupported")
      | `OverwriteSecure => `String("OverwriteSecure")
      | `InvalidDomain => `String("InvalidDomain")
      | `InvalidPrefix => `String("InvalidPrefix")
      | `UnknownError => `String("UnknownError")
      | `SchemefulSameSiteStrict => `String("SchemefulSameSiteStrict")
      | `SchemefulSameSiteLax => `String("SchemefulSameSiteLax")
      | `SchemefulSameSiteUnspecifiedTreatedAsLax =>
        `String("SchemefulSameSiteUnspecifiedTreatedAsLax")
      | `SamePartyFromCrossPartyContext =>
        `String("SamePartyFromCrossPartyContext")
      | `SamePartyConflictsWithOtherAttributes =>
        `String("SamePartyConflictsWithOtherAttributes")
      | `NameValuePairExceedsMaxSize =>
        `String("NameValuePairExceedsMaxSize");
    /* Types of reasons why a cookie may not be stored from a response. */
    [@deriving yojson]
    type t = _setcookieblockedreason;
  }
  and CookieBlockedReason: {
    type _cookieblockedreason = [
      | `SecureOnly
      | `NotOnPath
      | `DomainMismatch
      | `SameSiteStrict
      | `SameSiteLax
      | `SameSiteUnspecifiedTreatedAsLax
      | `SameSiteNoneInsecure
      | `UserPreferences
      | `UnknownError
      | `SchemefulSameSiteStrict
      | `SchemefulSameSiteLax
      | `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `SamePartyFromCrossPartyContext
      | `NameValuePairExceedsMaxSize
    ];
    let _cookieblockedreason_of_yojson: Yojson.Basic.t => _cookieblockedreason;
    let yojson_of__cookieblockedreason: _cookieblockedreason => Yojson.Basic.t;
    /* Types of reasons why a cookie may not be sent with a request. */
    [@deriving yojson]
    type t = _cookieblockedreason;
  } = {
    type _cookieblockedreason = [
      | `SecureOnly
      | `NotOnPath
      | `DomainMismatch
      | `SameSiteStrict
      | `SameSiteLax
      | `SameSiteUnspecifiedTreatedAsLax
      | `SameSiteNoneInsecure
      | `UserPreferences
      | `UnknownError
      | `SchemefulSameSiteStrict
      | `SchemefulSameSiteLax
      | `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `SamePartyFromCrossPartyContext
      | `NameValuePairExceedsMaxSize
    ];
    let _cookieblockedreason_of_yojson =
      fun
      | `String("SecureOnly") => `SecureOnly
      | `String("NotOnPath") => `NotOnPath
      | `String("DomainMismatch") => `DomainMismatch
      | `String("SameSiteStrict") => `SameSiteStrict
      | `String("SameSiteLax") => `SameSiteLax
      | `String("SameSiteUnspecifiedTreatedAsLax") => `SameSiteUnspecifiedTreatedAsLax
      | `String("SameSiteNoneInsecure") => `SameSiteNoneInsecure
      | `String("UserPreferences") => `UserPreferences
      | `String("UnknownError") => `UnknownError
      | `String("SchemefulSameSiteStrict") => `SchemefulSameSiteStrict
      | `String("SchemefulSameSiteLax") => `SchemefulSameSiteLax
      | `String("SchemefulSameSiteUnspecifiedTreatedAsLax") => `SchemefulSameSiteUnspecifiedTreatedAsLax
      | `String("SamePartyFromCrossPartyContext") => `SamePartyFromCrossPartyContext
      | `String("NameValuePairExceedsMaxSize") => `NameValuePairExceedsMaxSize
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__cookieblockedreason =
      fun
      | `SecureOnly => `String("SecureOnly")
      | `NotOnPath => `String("NotOnPath")
      | `DomainMismatch => `String("DomainMismatch")
      | `SameSiteStrict => `String("SameSiteStrict")
      | `SameSiteLax => `String("SameSiteLax")
      | `SameSiteUnspecifiedTreatedAsLax =>
        `String("SameSiteUnspecifiedTreatedAsLax")
      | `SameSiteNoneInsecure => `String("SameSiteNoneInsecure")
      | `UserPreferences => `String("UserPreferences")
      | `UnknownError => `String("UnknownError")
      | `SchemefulSameSiteStrict => `String("SchemefulSameSiteStrict")
      | `SchemefulSameSiteLax => `String("SchemefulSameSiteLax")
      | `SchemefulSameSiteUnspecifiedTreatedAsLax =>
        `String("SchemefulSameSiteUnspecifiedTreatedAsLax")
      | `SamePartyFromCrossPartyContext =>
        `String("SamePartyFromCrossPartyContext")
      | `NameValuePairExceedsMaxSize =>
        `String("NameValuePairExceedsMaxSize");
    /* Types of reasons why a cookie may not be sent with a request. */
    [@deriving yojson]
    type t = _cookieblockedreason;
  }
  and BlockedSetCookieWithReason: {
    /* A cookie which was not stored from a response with the corresponding reason. */
    [@deriving yojson]
    type t = {
      [@key "blockedReasons"]
      blockedReasons: list(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
      [@key "cookieLine"]
      cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
      [@yojson.option] [@key "cookie"]
      cookie: option(Cookie.t) /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
    };
  } = {
    /* A cookie which was not stored from a response with the corresponding reason. */
    [@deriving yojson]
    type t = {
      [@key "blockedReasons"]
      blockedReasons: list(SetCookieBlockedReason.t), /* The reason(s) this cookie was blocked. */
      [@key "cookieLine"]
      cookieLine: string, /* The string representing this individual cookie as it would appear in the header.
This is not the entire "cookie" or "set-cookie" header which could have multiple cookies. */
      [@yojson.option] [@key "cookie"]
      cookie: option(Cookie.t) /* The cookie object which represents the cookie which was not stored. It is optional because
sometimes complete cookie information is not available, such as in the case of parsing
errors. */,
    };
  }
  and BlockedCookieWithReason: {
    /* A cookie with was not sent with a request with the corresponding reason. */
    [@deriving yojson]
    type t = {
      [@key "blockedReasons"]
      blockedReasons: list(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
      [@key "cookie"]
      cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
    };
  } = {
    /* A cookie with was not sent with a request with the corresponding reason. */
    [@deriving yojson]
    type t = {
      [@key "blockedReasons"]
      blockedReasons: list(CookieBlockedReason.t), /* The reason(s) the cookie was blocked. */
      [@key "cookie"]
      cookie: Cookie.t /* The cookie object representing the cookie which was not sent. */,
    };
  }
  and CookieParam: {
    /* Cookie parameter object */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Cookie name. */
      [@key "value"]
      value: string, /* Cookie value. */
      [@yojson.option] [@key "url"]
      url: option(string), /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
      [@yojson.option] [@key "domain"]
      domain: option(string), /* Cookie domain. */
      [@yojson.option] [@key "path"]
      path: option(string), /* Cookie path. */
      [@yojson.option] [@key "secure"]
      secure: option(bool), /* True if cookie is secure. */
      [@yojson.option] [@key "httpOnly"]
      httpOnly: option(bool), /* True if cookie is http-only. */
      [@yojson.option] [@key "sameSite"]
      sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
      [@yojson.option] [@key "expires"]
      expires: option(TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
      [@yojson.option] [@key "priority"]
      priority: option(CookiePriority.t), /* Cookie Priority. */
      [@yojson.option] [@key "sameParty"]
      sameParty: option(bool), /* True if cookie is SameParty. */
      [@yojson.option] [@key "sourceScheme"]
      sourceScheme: option(CookieSourceScheme.t), /* Cookie source scheme type. */
      [@yojson.option] [@key "sourcePort"]
      sourcePort: option(float), /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */
      [@yojson.option] [@key "partitionKey"]
      partitionKey: option(string) /* Cookie partition key. The site of the top-level URL the browser was visiting at the start
of the request to the endpoint that set the cookie.
If not set, the cookie will be set as not partitioned. */,
    };
  } = {
    /* Cookie parameter object */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Cookie name. */
      [@key "value"]
      value: string, /* Cookie value. */
      [@yojson.option] [@key "url"]
      url: option(string), /* The request-URI to associate with the setting of the cookie. This value can affect the
default domain, path, source port, and source scheme values of the created cookie. */
      [@yojson.option] [@key "domain"]
      domain: option(string), /* Cookie domain. */
      [@yojson.option] [@key "path"]
      path: option(string), /* Cookie path. */
      [@yojson.option] [@key "secure"]
      secure: option(bool), /* True if cookie is secure. */
      [@yojson.option] [@key "httpOnly"]
      httpOnly: option(bool), /* True if cookie is http-only. */
      [@yojson.option] [@key "sameSite"]
      sameSite: option(CookieSameSite.t), /* Cookie SameSite type. */
      [@yojson.option] [@key "expires"]
      expires: option(TimeSinceEpoch.t), /* Cookie expiration date, session cookie if not set */
      [@yojson.option] [@key "priority"]
      priority: option(CookiePriority.t), /* Cookie Priority. */
      [@yojson.option] [@key "sameParty"]
      sameParty: option(bool), /* True if cookie is SameParty. */
      [@yojson.option] [@key "sourceScheme"]
      sourceScheme: option(CookieSourceScheme.t), /* Cookie source scheme type. */
      [@yojson.option] [@key "sourcePort"]
      sourcePort: option(float), /* Cookie source port. Valid values are {-1, [1, 65535]}, -1 indicates an unspecified port.
An unspecified port value allows protocol clients to emulate legacy cookie scope for the port.
This is a temporary ability and it will be removed in the future. */
      [@yojson.option] [@key "partitionKey"]
      partitionKey: option(string) /* Cookie partition key. The site of the top-level URL the browser was visiting at the start
of the request to the endpoint that set the cookie.
If not set, the cookie will be set as not partitioned. */,
    };
  }
  and AuthChallenge: {
    type _authchallenge_source = [ | `Server | `Proxy];
    let _authchallenge_source_of_yojson:
      Yojson.Basic.t => _authchallenge_source;
    let yojson_of__authchallenge_source:
      _authchallenge_source => Yojson.Basic.t;
    /* Authorization challenge for HTTP status code 401 or 407. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "source"]
      source: option(_authchallenge_source), /* Source of the authentication challenge. */
      [@key "origin"]
      origin: string, /* Origin of the challenger. */
      [@key "scheme"]
      scheme: string, /* The authentication scheme used, such as basic or digest */
      [@key "realm"]
      realm: string /* The realm of the challenge. May be empty. */,
    };
  } = {
    type _authchallenge_source = [ | `Server | `Proxy];
    let _authchallenge_source_of_yojson =
      fun
      | `String("Server") => `Server
      | `String("Proxy") => `Proxy
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__authchallenge_source =
      fun
      | `Server => `String("Server")
      | `Proxy => `String("Proxy");
    /* Authorization challenge for HTTP status code 401 or 407. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "source"]
      source: option(_authchallenge_source), /* Source of the authentication challenge. */
      [@key "origin"]
      origin: string, /* Origin of the challenger. */
      [@key "scheme"]
      scheme: string, /* The authentication scheme used, such as basic or digest */
      [@key "realm"]
      realm: string /* The realm of the challenge. May be empty. */,
    };
  }
  and AuthChallengeResponse: {
    type _authchallengeresponse_response = [
      | `Default
      | `CancelAuth
      | `ProvideCredentials
    ];
    let _authchallengeresponse_response_of_yojson:
      Yojson.Basic.t => _authchallengeresponse_response;
    let yojson_of__authchallengeresponse_response:
      _authchallengeresponse_response => Yojson.Basic.t;
    /* Response to an AuthChallenge. */
    [@deriving yojson]
    type t = {
      [@key "response"]
      response: _authchallengeresponse_response, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
      [@yojson.option] [@key "username"]
      username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
      [@yojson.option] [@key "password"]
      password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
    };
  } = {
    type _authchallengeresponse_response = [
      | `Default
      | `CancelAuth
      | `ProvideCredentials
    ];
    let _authchallengeresponse_response_of_yojson =
      fun
      | `String("Default") => `Default
      | `String("CancelAuth") => `CancelAuth
      | `String("ProvideCredentials") => `ProvideCredentials
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__authchallengeresponse_response =
      fun
      | `Default => `String("Default")
      | `CancelAuth => `String("CancelAuth")
      | `ProvideCredentials => `String("ProvideCredentials");
    /* Response to an AuthChallenge. */
    [@deriving yojson]
    type t = {
      [@key "response"]
      response: _authchallengeresponse_response, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
      [@yojson.option] [@key "username"]
      username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
      [@yojson.option] [@key "password"]
      password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
    };
  }
  and InterceptionStage: {
    type _interceptionstage = [ | `Request | `HeadersReceived];
    let _interceptionstage_of_yojson: Yojson.Basic.t => _interceptionstage;
    let yojson_of__interceptionstage: _interceptionstage => Yojson.Basic.t;
    /* Stages of the interception to begin intercepting. Request will intercept before the request is
       sent. Response will intercept after the response is received. */
    [@deriving yojson]
    type t = _interceptionstage;
  } = {
    type _interceptionstage = [ | `Request | `HeadersReceived];
    let _interceptionstage_of_yojson =
      fun
      | `String("Request") => `Request
      | `String("HeadersReceived") => `HeadersReceived
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__interceptionstage =
      fun
      | `Request => `String("Request")
      | `HeadersReceived => `String("HeadersReceived");
    /* Stages of the interception to begin intercepting. Request will intercept before the request is
       sent. Response will intercept after the response is received. */
    [@deriving yojson]
    type t = _interceptionstage;
  }
  and RequestPattern: {
    /* Request pattern for interception. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "urlPattern"]
      urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
      [@yojson.option] [@key "resourceType"]
      resourceType: option(ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
      [@yojson.option] [@key "interceptionStage"]
      interceptionStage: option(InterceptionStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
    };
  } = {
    /* Request pattern for interception. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "urlPattern"]
      urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
      [@yojson.option] [@key "resourceType"]
      resourceType: option(ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
      [@yojson.option] [@key "interceptionStage"]
      interceptionStage: option(InterceptionStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
    };
  }
  and SignedExchangeSignature: {
    /* Information about a signed exchange signature.
       https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
    [@deriving yojson]
    type t = {
      [@key "label"]
      label: string, /* Signed exchange signature label. */
      [@key "signature"]
      signature: string, /* The hex string of signed exchange signature. */
      [@key "integrity"]
      integrity: string, /* Signed exchange signature integrity. */
      [@yojson.option] [@key "certUrl"]
      certUrl: option(string), /* Signed exchange signature cert Url. */
      [@yojson.option] [@key "certSha256"]
      certSha256: option(string), /* The hex string of signed exchange signature cert sha256. */
      [@key "validityUrl"]
      validityUrl: string, /* Signed exchange signature validity Url. */
      [@key "date"]
      date: float, /* Signed exchange signature date. */
      [@key "expires"]
      expires: float, /* Signed exchange signature expires. */
      [@yojson.option] [@key "certificates"]
      certificates: option(list(string)) /* The encoded certificates. */,
    };
  } = {
    /* Information about a signed exchange signature.
       https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#rfc.section.3.1 */
    [@deriving yojson]
    type t = {
      [@key "label"]
      label: string, /* Signed exchange signature label. */
      [@key "signature"]
      signature: string, /* The hex string of signed exchange signature. */
      [@key "integrity"]
      integrity: string, /* Signed exchange signature integrity. */
      [@yojson.option] [@key "certUrl"]
      certUrl: option(string), /* Signed exchange signature cert Url. */
      [@yojson.option] [@key "certSha256"]
      certSha256: option(string), /* The hex string of signed exchange signature cert sha256. */
      [@key "validityUrl"]
      validityUrl: string, /* Signed exchange signature validity Url. */
      [@key "date"]
      date: float, /* Signed exchange signature date. */
      [@key "expires"]
      expires: float, /* Signed exchange signature expires. */
      [@yojson.option] [@key "certificates"]
      certificates: option(list(string)) /* The encoded certificates. */,
    };
  }
  and SignedExchangeHeader: {
    /* Information about a signed exchange header.
       https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
    [@deriving yojson]
    type t = {
      [@key "requestUrl"]
      requestUrl: string, /* Signed exchange request URL. */
      [@key "responseCode"]
      responseCode: float, /* Signed exchange response code. */
      [@key "responseHeaders"]
      responseHeaders: Headers.t, /* Signed exchange response headers. */
      [@key "signatures"]
      signatures: list(SignedExchangeSignature.t), /* Signed exchange response signature. */
      [@key "headerIntegrity"]
      headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
    };
  } = {
    /* Information about a signed exchange header.
       https://wicg.github.io/webpackage/draft-yasskin-httpbis-origin-signed-exchanges-impl.html#cbor-representation */
    [@deriving yojson]
    type t = {
      [@key "requestUrl"]
      requestUrl: string, /* Signed exchange request URL. */
      [@key "responseCode"]
      responseCode: float, /* Signed exchange response code. */
      [@key "responseHeaders"]
      responseHeaders: Headers.t, /* Signed exchange response headers. */
      [@key "signatures"]
      signatures: list(SignedExchangeSignature.t), /* Signed exchange response signature. */
      [@key "headerIntegrity"]
      headerIntegrity: string /* Signed exchange header integrity hash in the form of "sha256-<base64-hash-value>". */,
    };
  }
  and SignedExchangeErrorField: {
    type _signedexchangeerrorfield = [
      | `signatureSig
      | `signatureIntegrity
      | `signatureCertUrl
      | `signatureCertSha256
      | `signatureValidityUrl
      | `signatureTimestamps
    ];
    let _signedexchangeerrorfield_of_yojson:
      Yojson.Basic.t => _signedexchangeerrorfield;
    let yojson_of__signedexchangeerrorfield:
      _signedexchangeerrorfield => Yojson.Basic.t;
    /* Field type for a signed exchange related error. */
    [@deriving yojson]
    type t = _signedexchangeerrorfield;
  } = {
    type _signedexchangeerrorfield = [
      | `signatureSig
      | `signatureIntegrity
      | `signatureCertUrl
      | `signatureCertSha256
      | `signatureValidityUrl
      | `signatureTimestamps
    ];
    let _signedexchangeerrorfield_of_yojson =
      fun
      | `String("signatureSig") => `signatureSig
      | `String("signatureIntegrity") => `signatureIntegrity
      | `String("signatureCertUrl") => `signatureCertUrl
      | `String("signatureCertSha256") => `signatureCertSha256
      | `String("signatureValidityUrl") => `signatureValidityUrl
      | `String("signatureTimestamps") => `signatureTimestamps
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__signedexchangeerrorfield =
      fun
      | `signatureSig => `String("signatureSig")
      | `signatureIntegrity => `String("signatureIntegrity")
      | `signatureCertUrl => `String("signatureCertUrl")
      | `signatureCertSha256 => `String("signatureCertSha256")
      | `signatureValidityUrl => `String("signatureValidityUrl")
      | `signatureTimestamps => `String("signatureTimestamps");
    /* Field type for a signed exchange related error. */
    [@deriving yojson]
    type t = _signedexchangeerrorfield;
  }
  and SignedExchangeError: {
    /* Information about a signed exchange response. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@yojson.option] [@key "signatureIndex"]
      signatureIndex: option(float), /* The index of the signature which caused the error. */
      [@yojson.option] [@key "errorField"]
      errorField: option(SignedExchangeErrorField.t) /* The field which caused the error. */,
    };
  } = {
    /* Information about a signed exchange response. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@yojson.option] [@key "signatureIndex"]
      signatureIndex: option(float), /* The index of the signature which caused the error. */
      [@yojson.option] [@key "errorField"]
      errorField: option(SignedExchangeErrorField.t) /* The field which caused the error. */,
    };
  }
  and SignedExchangeInfo: {
    /* Information about a signed exchange response. */
    [@deriving yojson]
    type t = {
      [@key "outerResponse"]
      outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
      [@yojson.option] [@key "header"]
      header: option(SignedExchangeHeader.t), /* Information about the signed exchange header. */
      [@yojson.option] [@key "securityDetails"]
      securityDetails: option(SecurityDetails.t), /* Security details for the signed exchange header. */
      [@yojson.option] [@key "errors"]
      errors: option(list(SignedExchangeError.t)) /* Errors occurred while handling the signed exchagne. */,
    };
  } = {
    /* Information about a signed exchange response. */
    [@deriving yojson]
    type t = {
      [@key "outerResponse"]
      outerResponse: Response.t, /* The outer response of signed HTTP exchange which was received from network. */
      [@yojson.option] [@key "header"]
      header: option(SignedExchangeHeader.t), /* Information about the signed exchange header. */
      [@yojson.option] [@key "securityDetails"]
      securityDetails: option(SecurityDetails.t), /* Security details for the signed exchange header. */
      [@yojson.option] [@key "errors"]
      errors: option(list(SignedExchangeError.t)) /* Errors occurred while handling the signed exchagne. */,
    };
  }
  and ContentEncoding: {
    type _contentencoding = [ | `deflate | `gzip | `br];
    let _contentencoding_of_yojson: Yojson.Basic.t => _contentencoding;
    let yojson_of__contentencoding: _contentencoding => Yojson.Basic.t;
    /* List of content encodings supported by the backend. */
    [@deriving yojson]
    type t = _contentencoding;
  } = {
    type _contentencoding = [ | `deflate | `gzip | `br];
    let _contentencoding_of_yojson =
      fun
      | `String("deflate") => `deflate
      | `String("gzip") => `gzip
      | `String("br") => `br
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__contentencoding =
      fun
      | `deflate => `String("deflate")
      | `gzip => `String("gzip")
      | `br => `String("br");
    /* List of content encodings supported by the backend. */
    [@deriving yojson]
    type t = _contentencoding;
  }
  and PrivateNetworkRequestPolicy: {
    type _privatenetworkrequestpolicy = [
      | `Allow
      | `BlockFromInsecureToMorePrivate
      | `WarnFromInsecureToMorePrivate
      | `PreflightBlock
      | `PreflightWarn
    ];
    let _privatenetworkrequestpolicy_of_yojson:
      Yojson.Basic.t => _privatenetworkrequestpolicy;
    let yojson_of__privatenetworkrequestpolicy:
      _privatenetworkrequestpolicy => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _privatenetworkrequestpolicy;
  } = {
    type _privatenetworkrequestpolicy = [
      | `Allow
      | `BlockFromInsecureToMorePrivate
      | `WarnFromInsecureToMorePrivate
      | `PreflightBlock
      | `PreflightWarn
    ];
    let _privatenetworkrequestpolicy_of_yojson =
      fun
      | `String("Allow") => `Allow
      | `String("BlockFromInsecureToMorePrivate") => `BlockFromInsecureToMorePrivate
      | `String("WarnFromInsecureToMorePrivate") => `WarnFromInsecureToMorePrivate
      | `String("PreflightBlock") => `PreflightBlock
      | `String("PreflightWarn") => `PreflightWarn
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__privatenetworkrequestpolicy =
      fun
      | `Allow => `String("Allow")
      | `BlockFromInsecureToMorePrivate =>
        `String("BlockFromInsecureToMorePrivate")
      | `WarnFromInsecureToMorePrivate =>
        `String("WarnFromInsecureToMorePrivate")
      | `PreflightBlock => `String("PreflightBlock")
      | `PreflightWarn => `String("PreflightWarn");
    /* No description provided */
    [@deriving yojson]
    type t = _privatenetworkrequestpolicy;
  }
  and IPAddressSpace: {
    type _ipaddressspace = [ | `Local | `Private | `Public | `Unknown];
    let _ipaddressspace_of_yojson: Yojson.Basic.t => _ipaddressspace;
    let yojson_of__ipaddressspace: _ipaddressspace => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _ipaddressspace;
  } = {
    type _ipaddressspace = [ | `Local | `Private | `Public | `Unknown];
    let _ipaddressspace_of_yojson =
      fun
      | `String("Local") => `Local
      | `String("Private") => `Private
      | `String("Public") => `Public
      | `String("Unknown") => `Unknown
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__ipaddressspace =
      fun
      | `Local => `String("Local")
      | `Private => `String("Private")
      | `Public => `String("Public")
      | `Unknown => `String("Unknown");
    /* No description provided */
    [@deriving yojson]
    type t = _ipaddressspace;
  }
  and ConnectTiming: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "requestTime"]
      requestTime: float /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. Matches ResourceTiming's requestTime for
the same request (but not for redirected requests). */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "requestTime"]
      requestTime: float /* Timing's requestTime is a baseline in seconds, while the other numbers are ticks in
milliseconds relatively to this requestTime. Matches ResourceTiming's requestTime for
the same request (but not for redirected requests). */,
    };
  }
  and ClientSecurityState: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "initiatorIsSecureContext"]
      initiatorIsSecureContext: bool, /* No description provided */
      [@key "initiatorIPAddressSpace"]
      initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
      [@key "privateNetworkRequestPolicy"]
      privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "initiatorIsSecureContext"]
      initiatorIsSecureContext: bool, /* No description provided */
      [@key "initiatorIPAddressSpace"]
      initiatorIPAddressSpace: IPAddressSpace.t, /* No description provided */
      [@key "privateNetworkRequestPolicy"]
      privateNetworkRequestPolicy: PrivateNetworkRequestPolicy.t /* No description provided */,
    };
  }
  and CrossOriginOpenerPolicyValue: {
    type _crossoriginopenerpolicyvalue = [
      | `SameOrigin
      | `SameOriginAllowPopups
      | `UnsafeNone
      | `SameOriginPlusCoep
    ];
    let _crossoriginopenerpolicyvalue_of_yojson:
      Yojson.Basic.t => _crossoriginopenerpolicyvalue;
    let yojson_of__crossoriginopenerpolicyvalue:
      _crossoriginopenerpolicyvalue => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _crossoriginopenerpolicyvalue;
  } = {
    type _crossoriginopenerpolicyvalue = [
      | `SameOrigin
      | `SameOriginAllowPopups
      | `UnsafeNone
      | `SameOriginPlusCoep
    ];
    let _crossoriginopenerpolicyvalue_of_yojson =
      fun
      | `String("SameOrigin") => `SameOrigin
      | `String("SameOriginAllowPopups") => `SameOriginAllowPopups
      | `String("UnsafeNone") => `UnsafeNone
      | `String("SameOriginPlusCoep") => `SameOriginPlusCoep
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__crossoriginopenerpolicyvalue =
      fun
      | `SameOrigin => `String("SameOrigin")
      | `SameOriginAllowPopups => `String("SameOriginAllowPopups")
      | `UnsafeNone => `String("UnsafeNone")
      | `SameOriginPlusCoep => `String("SameOriginPlusCoep");
    /* No description provided */
    [@deriving yojson]
    type t = _crossoriginopenerpolicyvalue;
  }
  and CrossOriginOpenerPolicyStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: CrossOriginOpenerPolicyValue.t, /* No description provided */
      [@key "reportOnlyValue"]
      reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
      [@yojson.option] [@key "reportingEndpoint"]
      reportingEndpoint: option(string), /* No description provided */
      [@yojson.option] [@key "reportOnlyReportingEndpoint"]
      reportOnlyReportingEndpoint: option(string) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: CrossOriginOpenerPolicyValue.t, /* No description provided */
      [@key "reportOnlyValue"]
      reportOnlyValue: CrossOriginOpenerPolicyValue.t, /* No description provided */
      [@yojson.option] [@key "reportingEndpoint"]
      reportingEndpoint: option(string), /* No description provided */
      [@yojson.option] [@key "reportOnlyReportingEndpoint"]
      reportOnlyReportingEndpoint: option(string) /* No description provided */,
    };
  }
  and CrossOriginEmbedderPolicyValue: {
    type _crossoriginembedderpolicyvalue = [
      | `None
      | `Credentialless
      | `RequireCorp
    ];
    let _crossoriginembedderpolicyvalue_of_yojson:
      Yojson.Basic.t => _crossoriginembedderpolicyvalue;
    let yojson_of__crossoriginembedderpolicyvalue:
      _crossoriginembedderpolicyvalue => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _crossoriginembedderpolicyvalue;
  } = {
    type _crossoriginembedderpolicyvalue = [
      | `None
      | `Credentialless
      | `RequireCorp
    ];
    let _crossoriginembedderpolicyvalue_of_yojson =
      fun
      | `String("None") => `None
      | `String("Credentialless") => `Credentialless
      | `String("RequireCorp") => `RequireCorp
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__crossoriginembedderpolicyvalue =
      fun
      | `None => `String("None")
      | `Credentialless => `String("Credentialless")
      | `RequireCorp => `String("RequireCorp");
    /* No description provided */
    [@deriving yojson]
    type t = _crossoriginembedderpolicyvalue;
  }
  and CrossOriginEmbedderPolicyStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
      [@key "reportOnlyValue"]
      reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
      [@yojson.option] [@key "reportingEndpoint"]
      reportingEndpoint: option(string), /* No description provided */
      [@yojson.option] [@key "reportOnlyReportingEndpoint"]
      reportOnlyReportingEndpoint: option(string) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: CrossOriginEmbedderPolicyValue.t, /* No description provided */
      [@key "reportOnlyValue"]
      reportOnlyValue: CrossOriginEmbedderPolicyValue.t, /* No description provided */
      [@yojson.option] [@key "reportingEndpoint"]
      reportingEndpoint: option(string), /* No description provided */
      [@yojson.option] [@key "reportOnlyReportingEndpoint"]
      reportOnlyReportingEndpoint: option(string) /* No description provided */,
    };
  }
  and SecurityIsolationStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "coop"]
      coop: option(CrossOriginOpenerPolicyStatus.t), /* No description provided */
      [@yojson.option] [@key "coep"]
      coep: option(CrossOriginEmbedderPolicyStatus.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "coop"]
      coop: option(CrossOriginOpenerPolicyStatus.t), /* No description provided */
      [@yojson.option] [@key "coep"]
      coep: option(CrossOriginEmbedderPolicyStatus.t) /* No description provided */,
    };
  }
  and ReportStatus: {
    type _reportstatus = [
      | `Queued
      | `Pending
      | `MarkedForRemoval
      | `Success
    ];
    let _reportstatus_of_yojson: Yojson.Basic.t => _reportstatus;
    let yojson_of__reportstatus: _reportstatus => Yojson.Basic.t;
    /* The status of a Reporting API report. */
    [@deriving yojson]
    type t = _reportstatus;
  } = {
    type _reportstatus = [
      | `Queued
      | `Pending
      | `MarkedForRemoval
      | `Success
    ];
    let _reportstatus_of_yojson =
      fun
      | `String("Queued") => `Queued
      | `String("Pending") => `Pending
      | `String("MarkedForRemoval") => `MarkedForRemoval
      | `String("Success") => `Success
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__reportstatus =
      fun
      | `Queued => `String("Queued")
      | `Pending => `String("Pending")
      | `MarkedForRemoval => `String("MarkedForRemoval")
      | `Success => `String("Success");
    /* The status of a Reporting API report. */
    [@deriving yojson]
    type t = _reportstatus;
  }
  and ReportId: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and ReportingApiReport: {
    /* An object representing a report generated by the Reporting API. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: ReportId.t, /* No description provided */
      [@key "initiatorUrl"]
      initiatorUrl: string, /* The URL of the document that triggered the report. */
      [@key "destination"]
      destination: string, /* The name of the endpoint group that should be used to deliver the report. */
      [@key "type"]
      type_: string, /* The type of the report (specifies the set of data that is contained in the report body). */
      [@key "timestamp"]
      timestamp: Network.TimeSinceEpoch.t, /* When the report was generated. */
      [@key "depth"]
      depth: float, /* How many uploads deep the related request was. */
      [@key "completedAttempts"]
      completedAttempts: float, /* The number of delivery attempts made so far, not including an active attempt. */
      [@key "body"]
      body: assoc, /* No description provided */
      [@key "status"]
      status: ReportStatus.t /* No description provided */,
    };
  } = {
    /* An object representing a report generated by the Reporting API. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: ReportId.t, /* No description provided */
      [@key "initiatorUrl"]
      initiatorUrl: string, /* The URL of the document that triggered the report. */
      [@key "destination"]
      destination: string, /* The name of the endpoint group that should be used to deliver the report. */
      [@key "type"]
      type_: string, /* The type of the report (specifies the set of data that is contained in the report body). */
      [@key "timestamp"]
      timestamp: Network.TimeSinceEpoch.t, /* When the report was generated. */
      [@key "depth"]
      depth: float, /* How many uploads deep the related request was. */
      [@key "completedAttempts"]
      completedAttempts: float, /* The number of delivery attempts made so far, not including an active attempt. */
      [@key "body"]
      body: assoc, /* No description provided */
      [@key "status"]
      status: ReportStatus.t /* No description provided */,
    };
  }
  and ReportingApiEndpoint: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The URL of the endpoint to which reports may be delivered. */
      [@key "groupName"]
      groupName: string /* Name of the endpoint group. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The URL of the endpoint to which reports may be delivered. */
      [@key "groupName"]
      groupName: string /* Name of the endpoint group. */,
    };
  }
  and LoadNetworkResourcePageResult: {
    /* An object providing the result of a network resource load. */
    [@deriving yojson]
    type t = {
      [@key "success"]
      success: bool, /* No description provided */
      [@yojson.option] [@key "netError"]
      netError: option(float), /* Optional values used for error reporting. */
      [@yojson.option] [@key "netErrorName"]
      netErrorName: option(string), /* No description provided */
      [@yojson.option] [@key "httpStatusCode"]
      httpStatusCode: option(float), /* No description provided */
      [@yojson.option] [@key "stream"]
      stream: option(IO.StreamHandle.t), /* If successful, one of the following two fields holds the result. */
      [@yojson.option] [@key "headers"]
      headers: option(Network.Headers.t) /* Response headers. */,
    };
  } = {
    /* An object providing the result of a network resource load. */
    [@deriving yojson]
    type t = {
      [@key "success"]
      success: bool, /* No description provided */
      [@yojson.option] [@key "netError"]
      netError: option(float), /* Optional values used for error reporting. */
      [@yojson.option] [@key "netErrorName"]
      netErrorName: option(string), /* No description provided */
      [@yojson.option] [@key "httpStatusCode"]
      httpStatusCode: option(float), /* No description provided */
      [@yojson.option] [@key "stream"]
      stream: option(IO.StreamHandle.t), /* If successful, one of the following two fields holds the result. */
      [@yojson.option] [@key "headers"]
      headers: option(Network.Headers.t) /* Response headers. */,
    };
  }
  and LoadNetworkResourceOptions: {
    /* An options object that may be extended later to better support CORS,
       CORB and streaming. */
    [@deriving yojson]
    type t = {
      [@key "disableCache"]
      disableCache: bool, /* No description provided */
      [@key "includeCredentials"]
      includeCredentials: bool /* No description provided */,
    };
  } = {
    /* An options object that may be extended later to better support CORS,
       CORB and streaming. */
    [@deriving yojson]
    type t = {
      [@key "disableCache"]
      disableCache: bool, /* No description provided */
      [@key "includeCredentials"]
      includeCredentials: bool /* No description provided */,
    };
  };
}
and Overlay: {
  module rec SourceOrderConfig: {
    /* Configuration data for drawing the source order of an elements children. */
    [@deriving yojson]
    type t = {
      [@key "parentOutlineColor"]
      parentOutlineColor: DOM.RGBA.t, /* the color to outline the givent element in. */
      [@key "childOutlineColor"]
      childOutlineColor: DOM.RGBA.t /* the color to outline the child elements in. */,
    };
  }
  and GridHighlightConfig: {
    /* Configuration data for the highlighting of Grid elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "showGridExtensionLines"]
      showGridExtensionLines: option(bool), /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
      [@yojson.option] [@key "showPositiveLineNumbers"]
      showPositiveLineNumbers: option(bool), /* Show Positive line number labels (default: false). */
      [@yojson.option] [@key "showNegativeLineNumbers"]
      showNegativeLineNumbers: option(bool), /* Show Negative line number labels (default: false). */
      [@yojson.option] [@key "showAreaNames"]
      showAreaNames: option(bool), /* Show area name labels (default: false). */
      [@yojson.option] [@key "showLineNames"]
      showLineNames: option(bool), /* Show line name labels (default: false). */
      [@yojson.option] [@key "showTrackSizes"]
      showTrackSizes: option(bool), /* Show track size labels (default: false). */
      [@yojson.option] [@key "gridBorderColor"]
      gridBorderColor: option(DOM.RGBA.t), /* The grid container border highlight color (default: transparent). */
      [@yojson.option] [@key "cellBorderColor"]
      cellBorderColor: option(DOM.RGBA.t), /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
      [@yojson.option] [@key "rowLineColor"]
      rowLineColor: option(DOM.RGBA.t), /* The row line color (default: transparent). */
      [@yojson.option] [@key "columnLineColor"]
      columnLineColor: option(DOM.RGBA.t), /* The column line color (default: transparent). */
      [@yojson.option] [@key "gridBorderDash"]
      gridBorderDash: option(bool), /* Whether the grid border is dashed (default: false). */
      [@yojson.option] [@key "cellBorderDash"]
      cellBorderDash: option(bool), /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
      [@yojson.option] [@key "rowLineDash"]
      rowLineDash: option(bool), /* Whether row lines are dashed (default: false). */
      [@yojson.option] [@key "columnLineDash"]
      columnLineDash: option(bool), /* Whether column lines are dashed (default: false). */
      [@yojson.option] [@key "rowGapColor"]
      rowGapColor: option(DOM.RGBA.t), /* The row gap highlight fill color (default: transparent). */
      [@yojson.option] [@key "rowHatchColor"]
      rowHatchColor: option(DOM.RGBA.t), /* The row gap hatching fill color (default: transparent). */
      [@yojson.option] [@key "columnGapColor"]
      columnGapColor: option(DOM.RGBA.t), /* The column gap highlight fill color (default: transparent). */
      [@yojson.option] [@key "columnHatchColor"]
      columnHatchColor: option(DOM.RGBA.t), /* The column gap hatching fill color (default: transparent). */
      [@yojson.option] [@key "areaBorderColor"]
      areaBorderColor: option(DOM.RGBA.t), /* The named grid areas border color (Default: transparent). */
      [@yojson.option] [@key "gridBackgroundColor"]
      gridBackgroundColor: option(DOM.RGBA.t) /* The grid container background color (Default: transparent). */,
    };
  }
  and FlexContainerHighlightConfig: {
    /* Configuration data for the highlighting of Flex container elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "containerBorder"]
      containerBorder: option(LineStyle.t), /* The style of the container border */
      [@yojson.option] [@key "lineSeparator"]
      lineSeparator: option(LineStyle.t), /* The style of the separator between lines */
      [@yojson.option] [@key "itemSeparator"]
      itemSeparator: option(LineStyle.t), /* The style of the separator between items */
      [@yojson.option] [@key "mainDistributedSpace"]
      mainDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the main axis (justify-content). */
      [@yojson.option] [@key "crossDistributedSpace"]
      crossDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the cross axis (align-content). */
      [@yojson.option] [@key "rowGapSpace"]
      rowGapSpace: option(BoxStyle.t), /* Style of empty space caused by row gaps (gap/row-gap). */
      [@yojson.option] [@key "columnGapSpace"]
      columnGapSpace: option(BoxStyle.t), /* Style of empty space caused by columns gaps (gap/column-gap). */
      [@yojson.option] [@key "crossAlignment"]
      crossAlignment: option(LineStyle.t) /* Style of the self-alignment line (align-items). */,
    };
  }
  and FlexItemHighlightConfig: {
    /* Configuration data for the highlighting of Flex item elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "baseSizeBox"]
      baseSizeBox: option(BoxStyle.t), /* Style of the box representing the item's base size */
      [@yojson.option] [@key "baseSizeBorder"]
      baseSizeBorder: option(LineStyle.t), /* Style of the border around the box representing the item's base size */
      [@yojson.option] [@key "flexibilityArrow"]
      flexibilityArrow: option(LineStyle.t) /* Style of the arrow representing if the item grew or shrank */,
    };
  }
  and LineStyle: {
    type _linestyle_pattern = [ | `dashed | `dotted];
    let _linestyle_pattern_of_yojson: Yojson.Basic.t => _linestyle_pattern;
    let yojson_of__linestyle_pattern: _linestyle_pattern => Yojson.Basic.t;
    /* Style information for drawing a line. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "color"]
      color: option(DOM.RGBA.t), /* The color of the line (default: transparent) */
      [@yojson.option] [@key "pattern"]
      pattern: option(_linestyle_pattern) /* The line pattern (default: solid) */,
    };
  }
  and BoxStyle: {
    /* Style information for drawing a box. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "fillColor"]
      fillColor: option(DOM.RGBA.t), /* The background color for the box (default: transparent) */
      [@yojson.option] [@key "hatchColor"]
      hatchColor: option(DOM.RGBA.t) /* The hatching color for the box (default: transparent) */,
    };
  }
  and ContrastAlgorithm: {
    type _contrastalgorithm = [ | `aa | `aaa | `apca];
    let _contrastalgorithm_of_yojson: Yojson.Basic.t => _contrastalgorithm;
    let yojson_of__contrastalgorithm: _contrastalgorithm => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _contrastalgorithm;
  }
  and HighlightConfig: {
    /* Configuration data for the highlighting of page elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "showInfo"]
      showInfo: option(bool), /* Whether the node info tooltip should be shown (default: false). */
      [@yojson.option] [@key "showStyles"]
      showStyles: option(bool), /* Whether the node styles in the tooltip (default: false). */
      [@yojson.option] [@key "showRulers"]
      showRulers: option(bool), /* Whether the rulers should be shown (default: false). */
      [@yojson.option] [@key "showAccessibilityInfo"]
      showAccessibilityInfo: option(bool), /* Whether the a11y info should be shown (default: true). */
      [@yojson.option] [@key "showExtensionLines"]
      showExtensionLines: option(bool), /* Whether the extension lines from node to the rulers should be shown (default: false). */
      [@yojson.option] [@key "contentColor"]
      contentColor: option(DOM.RGBA.t), /* The content box highlight fill color (default: transparent). */
      [@yojson.option] [@key "paddingColor"]
      paddingColor: option(DOM.RGBA.t), /* The padding highlight fill color (default: transparent). */
      [@yojson.option] [@key "borderColor"]
      borderColor: option(DOM.RGBA.t), /* The border highlight fill color (default: transparent). */
      [@yojson.option] [@key "marginColor"]
      marginColor: option(DOM.RGBA.t), /* The margin highlight fill color (default: transparent). */
      [@yojson.option] [@key "eventTargetColor"]
      eventTargetColor: option(DOM.RGBA.t), /* The event target element highlight fill color (default: transparent). */
      [@yojson.option] [@key "shapeColor"]
      shapeColor: option(DOM.RGBA.t), /* The shape outside fill color (default: transparent). */
      [@yojson.option] [@key "shapeMarginColor"]
      shapeMarginColor: option(DOM.RGBA.t), /* The shape margin fill color (default: transparent). */
      [@yojson.option] [@key "cssGridColor"]
      cssGridColor: option(DOM.RGBA.t), /* The grid layout color (default: transparent). */
      [@yojson.option] [@key "colorFormat"]
      colorFormat: option(ColorFormat.t), /* The color format used to format color styles (default: hex). */
      [@yojson.option] [@key "gridHighlightConfig"]
      gridHighlightConfig: option(GridHighlightConfig.t), /* The grid layout highlight configuration (default: all transparent). */
      [@yojson.option] [@key "flexContainerHighlightConfig"]
      flexContainerHighlightConfig: option(FlexContainerHighlightConfig.t), /* The flex container highlight configuration (default: all transparent). */
      [@yojson.option] [@key "flexItemHighlightConfig"]
      flexItemHighlightConfig: option(FlexItemHighlightConfig.t), /* The flex item highlight configuration (default: all transparent). */
      [@yojson.option] [@key "contrastAlgorithm"]
      contrastAlgorithm: option(ContrastAlgorithm.t), /* The contrast algorithm to use for the contrast ratio (default: aa). */
      [@yojson.option] [@key "containerQueryContainerHighlightConfig"]
      containerQueryContainerHighlightConfig:
        option(ContainerQueryContainerHighlightConfig.t) /* The container query container highlight configuration (default: all transparent). */,
    };
  }
  and ColorFormat: {
    type _colorformat = [ | `rgb | `hsl | `hex];
    let _colorformat_of_yojson: Yojson.Basic.t => _colorformat;
    let yojson_of__colorformat: _colorformat => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _colorformat;
  }
  and GridNodeHighlightConfig: {
    /* Configurations for Persistent Grid Highlight */
    [@deriving yojson]
    type t = {
      [@key "gridHighlightConfig"]
      gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  }
  and FlexNodeHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "flexContainerHighlightConfig"]
      flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  }
  and ScrollSnapContainerHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "snapportBorder"]
      snapportBorder: option(LineStyle.t), /* The style of the snapport border (default: transparent) */
      [@yojson.option] [@key "snapAreaBorder"]
      snapAreaBorder: option(LineStyle.t), /* The style of the snap area border (default: transparent) */
      [@yojson.option] [@key "scrollMarginColor"]
      scrollMarginColor: option(DOM.RGBA.t), /* The margin highlight fill color (default: transparent). */
      [@yojson.option] [@key "scrollPaddingColor"]
      scrollPaddingColor: option(DOM.RGBA.t) /* The padding highlight fill color (default: transparent). */,
    };
  }
  and ScrollSnapHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "scrollSnapContainerHighlightConfig"]
      scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  }
  and HingeConfig: {
    /* Configuration for dual screen hinge */
    [@deriving yojson]
    type t = {
      [@key "rect"]
      rect: DOM.Rect.t, /* A rectangle represent hinge */
      [@yojson.option] [@key "contentColor"]
      contentColor: option(DOM.RGBA.t), /* The content box highlight fill color (default: a dark color). */
      [@yojson.option] [@key "outlineColor"]
      outlineColor: option(DOM.RGBA.t) /* The content box highlight outline color (default: transparent). */,
    };
  }
  and ContainerQueryHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "containerQueryContainerHighlightConfig"]
      containerQueryContainerHighlightConfig: ContainerQueryContainerHighlightConfig.t, /* A descriptor for the highlight appearance of container query containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the container node to highlight. */,
    };
  }
  and ContainerQueryContainerHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "containerBorder"]
      containerBorder: option(LineStyle.t), /* The style of the container border. */
      [@yojson.option] [@key "descendantBorder"]
      descendantBorder: option(LineStyle.t) /* The style of the descendants' borders. */,
    };
  }
  and IsolatedElementHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "isolationModeHighlightConfig"]
      isolationModeHighlightConfig: IsolationModeHighlightConfig.t, /* A descriptor for the highlight appearance of an element in isolation mode. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the isolated element to highlight. */,
    };
  }
  and IsolationModeHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "resizerColor"]
      resizerColor: option(DOM.RGBA.t), /* The fill color of the resizers (default: transparent). */
      [@yojson.option] [@key "resizerHandleColor"]
      resizerHandleColor: option(DOM.RGBA.t), /* The fill color for resizer handles (default: transparent). */
      [@yojson.option] [@key "maskColor"]
      maskColor: option(DOM.RGBA.t) /* The fill color for the mask covering non-isolated elements (default: transparent). */,
    };
  }
  and InspectMode: {
    type _inspectmode = [
      | `searchForNode
      | `searchForUAShadowDOM
      | `captureAreaScreenshot
      | `showDistances
      | `none
    ];
    let _inspectmode_of_yojson: Yojson.Basic.t => _inspectmode;
    let yojson_of__inspectmode: _inspectmode => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _inspectmode;
  };
} = {
  module rec SourceOrderConfig: {
    /* Configuration data for drawing the source order of an elements children. */
    [@deriving yojson]
    type t = {
      [@key "parentOutlineColor"]
      parentOutlineColor: DOM.RGBA.t, /* the color to outline the givent element in. */
      [@key "childOutlineColor"]
      childOutlineColor: DOM.RGBA.t /* the color to outline the child elements in. */,
    };
  } = {
    /* Configuration data for drawing the source order of an elements children. */
    [@deriving yojson]
    type t = {
      [@key "parentOutlineColor"]
      parentOutlineColor: DOM.RGBA.t, /* the color to outline the givent element in. */
      [@key "childOutlineColor"]
      childOutlineColor: DOM.RGBA.t /* the color to outline the child elements in. */,
    };
  }
  and GridHighlightConfig: {
    /* Configuration data for the highlighting of Grid elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "showGridExtensionLines"]
      showGridExtensionLines: option(bool), /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
      [@yojson.option] [@key "showPositiveLineNumbers"]
      showPositiveLineNumbers: option(bool), /* Show Positive line number labels (default: false). */
      [@yojson.option] [@key "showNegativeLineNumbers"]
      showNegativeLineNumbers: option(bool), /* Show Negative line number labels (default: false). */
      [@yojson.option] [@key "showAreaNames"]
      showAreaNames: option(bool), /* Show area name labels (default: false). */
      [@yojson.option] [@key "showLineNames"]
      showLineNames: option(bool), /* Show line name labels (default: false). */
      [@yojson.option] [@key "showTrackSizes"]
      showTrackSizes: option(bool), /* Show track size labels (default: false). */
      [@yojson.option] [@key "gridBorderColor"]
      gridBorderColor: option(DOM.RGBA.t), /* The grid container border highlight color (default: transparent). */
      [@yojson.option] [@key "cellBorderColor"]
      cellBorderColor: option(DOM.RGBA.t), /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
      [@yojson.option] [@key "rowLineColor"]
      rowLineColor: option(DOM.RGBA.t), /* The row line color (default: transparent). */
      [@yojson.option] [@key "columnLineColor"]
      columnLineColor: option(DOM.RGBA.t), /* The column line color (default: transparent). */
      [@yojson.option] [@key "gridBorderDash"]
      gridBorderDash: option(bool), /* Whether the grid border is dashed (default: false). */
      [@yojson.option] [@key "cellBorderDash"]
      cellBorderDash: option(bool), /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
      [@yojson.option] [@key "rowLineDash"]
      rowLineDash: option(bool), /* Whether row lines are dashed (default: false). */
      [@yojson.option] [@key "columnLineDash"]
      columnLineDash: option(bool), /* Whether column lines are dashed (default: false). */
      [@yojson.option] [@key "rowGapColor"]
      rowGapColor: option(DOM.RGBA.t), /* The row gap highlight fill color (default: transparent). */
      [@yojson.option] [@key "rowHatchColor"]
      rowHatchColor: option(DOM.RGBA.t), /* The row gap hatching fill color (default: transparent). */
      [@yojson.option] [@key "columnGapColor"]
      columnGapColor: option(DOM.RGBA.t), /* The column gap highlight fill color (default: transparent). */
      [@yojson.option] [@key "columnHatchColor"]
      columnHatchColor: option(DOM.RGBA.t), /* The column gap hatching fill color (default: transparent). */
      [@yojson.option] [@key "areaBorderColor"]
      areaBorderColor: option(DOM.RGBA.t), /* The named grid areas border color (Default: transparent). */
      [@yojson.option] [@key "gridBackgroundColor"]
      gridBackgroundColor: option(DOM.RGBA.t) /* The grid container background color (Default: transparent). */,
    };
  } = {
    /* Configuration data for the highlighting of Grid elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "showGridExtensionLines"]
      showGridExtensionLines: option(bool), /* Whether the extension lines from grid cells to the rulers should be shown (default: false). */
      [@yojson.option] [@key "showPositiveLineNumbers"]
      showPositiveLineNumbers: option(bool), /* Show Positive line number labels (default: false). */
      [@yojson.option] [@key "showNegativeLineNumbers"]
      showNegativeLineNumbers: option(bool), /* Show Negative line number labels (default: false). */
      [@yojson.option] [@key "showAreaNames"]
      showAreaNames: option(bool), /* Show area name labels (default: false). */
      [@yojson.option] [@key "showLineNames"]
      showLineNames: option(bool), /* Show line name labels (default: false). */
      [@yojson.option] [@key "showTrackSizes"]
      showTrackSizes: option(bool), /* Show track size labels (default: false). */
      [@yojson.option] [@key "gridBorderColor"]
      gridBorderColor: option(DOM.RGBA.t), /* The grid container border highlight color (default: transparent). */
      [@yojson.option] [@key "cellBorderColor"]
      cellBorderColor: option(DOM.RGBA.t), /* The cell border color (default: transparent). Deprecated, please use rowLineColor and columnLineColor instead. */
      [@yojson.option] [@key "rowLineColor"]
      rowLineColor: option(DOM.RGBA.t), /* The row line color (default: transparent). */
      [@yojson.option] [@key "columnLineColor"]
      columnLineColor: option(DOM.RGBA.t), /* The column line color (default: transparent). */
      [@yojson.option] [@key "gridBorderDash"]
      gridBorderDash: option(bool), /* Whether the grid border is dashed (default: false). */
      [@yojson.option] [@key "cellBorderDash"]
      cellBorderDash: option(bool), /* Whether the cell border is dashed (default: false). Deprecated, please us rowLineDash and columnLineDash instead. */
      [@yojson.option] [@key "rowLineDash"]
      rowLineDash: option(bool), /* Whether row lines are dashed (default: false). */
      [@yojson.option] [@key "columnLineDash"]
      columnLineDash: option(bool), /* Whether column lines are dashed (default: false). */
      [@yojson.option] [@key "rowGapColor"]
      rowGapColor: option(DOM.RGBA.t), /* The row gap highlight fill color (default: transparent). */
      [@yojson.option] [@key "rowHatchColor"]
      rowHatchColor: option(DOM.RGBA.t), /* The row gap hatching fill color (default: transparent). */
      [@yojson.option] [@key "columnGapColor"]
      columnGapColor: option(DOM.RGBA.t), /* The column gap highlight fill color (default: transparent). */
      [@yojson.option] [@key "columnHatchColor"]
      columnHatchColor: option(DOM.RGBA.t), /* The column gap hatching fill color (default: transparent). */
      [@yojson.option] [@key "areaBorderColor"]
      areaBorderColor: option(DOM.RGBA.t), /* The named grid areas border color (Default: transparent). */
      [@yojson.option] [@key "gridBackgroundColor"]
      gridBackgroundColor: option(DOM.RGBA.t) /* The grid container background color (Default: transparent). */,
    };
  }
  and FlexContainerHighlightConfig: {
    /* Configuration data for the highlighting of Flex container elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "containerBorder"]
      containerBorder: option(LineStyle.t), /* The style of the container border */
      [@yojson.option] [@key "lineSeparator"]
      lineSeparator: option(LineStyle.t), /* The style of the separator between lines */
      [@yojson.option] [@key "itemSeparator"]
      itemSeparator: option(LineStyle.t), /* The style of the separator between items */
      [@yojson.option] [@key "mainDistributedSpace"]
      mainDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the main axis (justify-content). */
      [@yojson.option] [@key "crossDistributedSpace"]
      crossDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the cross axis (align-content). */
      [@yojson.option] [@key "rowGapSpace"]
      rowGapSpace: option(BoxStyle.t), /* Style of empty space caused by row gaps (gap/row-gap). */
      [@yojson.option] [@key "columnGapSpace"]
      columnGapSpace: option(BoxStyle.t), /* Style of empty space caused by columns gaps (gap/column-gap). */
      [@yojson.option] [@key "crossAlignment"]
      crossAlignment: option(LineStyle.t) /* Style of the self-alignment line (align-items). */,
    };
  } = {
    /* Configuration data for the highlighting of Flex container elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "containerBorder"]
      containerBorder: option(LineStyle.t), /* The style of the container border */
      [@yojson.option] [@key "lineSeparator"]
      lineSeparator: option(LineStyle.t), /* The style of the separator between lines */
      [@yojson.option] [@key "itemSeparator"]
      itemSeparator: option(LineStyle.t), /* The style of the separator between items */
      [@yojson.option] [@key "mainDistributedSpace"]
      mainDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the main axis (justify-content). */
      [@yojson.option] [@key "crossDistributedSpace"]
      crossDistributedSpace: option(BoxStyle.t), /* Style of content-distribution space on the cross axis (align-content). */
      [@yojson.option] [@key "rowGapSpace"]
      rowGapSpace: option(BoxStyle.t), /* Style of empty space caused by row gaps (gap/row-gap). */
      [@yojson.option] [@key "columnGapSpace"]
      columnGapSpace: option(BoxStyle.t), /* Style of empty space caused by columns gaps (gap/column-gap). */
      [@yojson.option] [@key "crossAlignment"]
      crossAlignment: option(LineStyle.t) /* Style of the self-alignment line (align-items). */,
    };
  }
  and FlexItemHighlightConfig: {
    /* Configuration data for the highlighting of Flex item elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "baseSizeBox"]
      baseSizeBox: option(BoxStyle.t), /* Style of the box representing the item's base size */
      [@yojson.option] [@key "baseSizeBorder"]
      baseSizeBorder: option(LineStyle.t), /* Style of the border around the box representing the item's base size */
      [@yojson.option] [@key "flexibilityArrow"]
      flexibilityArrow: option(LineStyle.t) /* Style of the arrow representing if the item grew or shrank */,
    };
  } = {
    /* Configuration data for the highlighting of Flex item elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "baseSizeBox"]
      baseSizeBox: option(BoxStyle.t), /* Style of the box representing the item's base size */
      [@yojson.option] [@key "baseSizeBorder"]
      baseSizeBorder: option(LineStyle.t), /* Style of the border around the box representing the item's base size */
      [@yojson.option] [@key "flexibilityArrow"]
      flexibilityArrow: option(LineStyle.t) /* Style of the arrow representing if the item grew or shrank */,
    };
  }
  and LineStyle: {
    type _linestyle_pattern = [ | `dashed | `dotted];
    let _linestyle_pattern_of_yojson: Yojson.Basic.t => _linestyle_pattern;
    let yojson_of__linestyle_pattern: _linestyle_pattern => Yojson.Basic.t;
    /* Style information for drawing a line. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "color"]
      color: option(DOM.RGBA.t), /* The color of the line (default: transparent) */
      [@yojson.option] [@key "pattern"]
      pattern: option(_linestyle_pattern) /* The line pattern (default: solid) */,
    };
  } = {
    type _linestyle_pattern = [ | `dashed | `dotted];
    let _linestyle_pattern_of_yojson =
      fun
      | `String("dashed") => `dashed
      | `String("dotted") => `dotted
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__linestyle_pattern =
      fun
      | `dashed => `String("dashed")
      | `dotted => `String("dotted");
    /* Style information for drawing a line. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "color"]
      color: option(DOM.RGBA.t), /* The color of the line (default: transparent) */
      [@yojson.option] [@key "pattern"]
      pattern: option(_linestyle_pattern) /* The line pattern (default: solid) */,
    };
  }
  and BoxStyle: {
    /* Style information for drawing a box. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "fillColor"]
      fillColor: option(DOM.RGBA.t), /* The background color for the box (default: transparent) */
      [@yojson.option] [@key "hatchColor"]
      hatchColor: option(DOM.RGBA.t) /* The hatching color for the box (default: transparent) */,
    };
  } = {
    /* Style information for drawing a box. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "fillColor"]
      fillColor: option(DOM.RGBA.t), /* The background color for the box (default: transparent) */
      [@yojson.option] [@key "hatchColor"]
      hatchColor: option(DOM.RGBA.t) /* The hatching color for the box (default: transparent) */,
    };
  }
  and ContrastAlgorithm: {
    type _contrastalgorithm = [ | `aa | `aaa | `apca];
    let _contrastalgorithm_of_yojson: Yojson.Basic.t => _contrastalgorithm;
    let yojson_of__contrastalgorithm: _contrastalgorithm => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _contrastalgorithm;
  } = {
    type _contrastalgorithm = [ | `aa | `aaa | `apca];
    let _contrastalgorithm_of_yojson =
      fun
      | `String("aa") => `aa
      | `String("aaa") => `aaa
      | `String("apca") => `apca
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__contrastalgorithm =
      fun
      | `aa => `String("aa")
      | `aaa => `String("aaa")
      | `apca => `String("apca");
    /* No description provided */
    [@deriving yojson]
    type t = _contrastalgorithm;
  }
  and HighlightConfig: {
    /* Configuration data for the highlighting of page elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "showInfo"]
      showInfo: option(bool), /* Whether the node info tooltip should be shown (default: false). */
      [@yojson.option] [@key "showStyles"]
      showStyles: option(bool), /* Whether the node styles in the tooltip (default: false). */
      [@yojson.option] [@key "showRulers"]
      showRulers: option(bool), /* Whether the rulers should be shown (default: false). */
      [@yojson.option] [@key "showAccessibilityInfo"]
      showAccessibilityInfo: option(bool), /* Whether the a11y info should be shown (default: true). */
      [@yojson.option] [@key "showExtensionLines"]
      showExtensionLines: option(bool), /* Whether the extension lines from node to the rulers should be shown (default: false). */
      [@yojson.option] [@key "contentColor"]
      contentColor: option(DOM.RGBA.t), /* The content box highlight fill color (default: transparent). */
      [@yojson.option] [@key "paddingColor"]
      paddingColor: option(DOM.RGBA.t), /* The padding highlight fill color (default: transparent). */
      [@yojson.option] [@key "borderColor"]
      borderColor: option(DOM.RGBA.t), /* The border highlight fill color (default: transparent). */
      [@yojson.option] [@key "marginColor"]
      marginColor: option(DOM.RGBA.t), /* The margin highlight fill color (default: transparent). */
      [@yojson.option] [@key "eventTargetColor"]
      eventTargetColor: option(DOM.RGBA.t), /* The event target element highlight fill color (default: transparent). */
      [@yojson.option] [@key "shapeColor"]
      shapeColor: option(DOM.RGBA.t), /* The shape outside fill color (default: transparent). */
      [@yojson.option] [@key "shapeMarginColor"]
      shapeMarginColor: option(DOM.RGBA.t), /* The shape margin fill color (default: transparent). */
      [@yojson.option] [@key "cssGridColor"]
      cssGridColor: option(DOM.RGBA.t), /* The grid layout color (default: transparent). */
      [@yojson.option] [@key "colorFormat"]
      colorFormat: option(ColorFormat.t), /* The color format used to format color styles (default: hex). */
      [@yojson.option] [@key "gridHighlightConfig"]
      gridHighlightConfig: option(GridHighlightConfig.t), /* The grid layout highlight configuration (default: all transparent). */
      [@yojson.option] [@key "flexContainerHighlightConfig"]
      flexContainerHighlightConfig: option(FlexContainerHighlightConfig.t), /* The flex container highlight configuration (default: all transparent). */
      [@yojson.option] [@key "flexItemHighlightConfig"]
      flexItemHighlightConfig: option(FlexItemHighlightConfig.t), /* The flex item highlight configuration (default: all transparent). */
      [@yojson.option] [@key "contrastAlgorithm"]
      contrastAlgorithm: option(ContrastAlgorithm.t), /* The contrast algorithm to use for the contrast ratio (default: aa). */
      [@yojson.option] [@key "containerQueryContainerHighlightConfig"]
      containerQueryContainerHighlightConfig:
        option(ContainerQueryContainerHighlightConfig.t) /* The container query container highlight configuration (default: all transparent). */,
    };
  } = {
    /* Configuration data for the highlighting of page elements. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "showInfo"]
      showInfo: option(bool), /* Whether the node info tooltip should be shown (default: false). */
      [@yojson.option] [@key "showStyles"]
      showStyles: option(bool), /* Whether the node styles in the tooltip (default: false). */
      [@yojson.option] [@key "showRulers"]
      showRulers: option(bool), /* Whether the rulers should be shown (default: false). */
      [@yojson.option] [@key "showAccessibilityInfo"]
      showAccessibilityInfo: option(bool), /* Whether the a11y info should be shown (default: true). */
      [@yojson.option] [@key "showExtensionLines"]
      showExtensionLines: option(bool), /* Whether the extension lines from node to the rulers should be shown (default: false). */
      [@yojson.option] [@key "contentColor"]
      contentColor: option(DOM.RGBA.t), /* The content box highlight fill color (default: transparent). */
      [@yojson.option] [@key "paddingColor"]
      paddingColor: option(DOM.RGBA.t), /* The padding highlight fill color (default: transparent). */
      [@yojson.option] [@key "borderColor"]
      borderColor: option(DOM.RGBA.t), /* The border highlight fill color (default: transparent). */
      [@yojson.option] [@key "marginColor"]
      marginColor: option(DOM.RGBA.t), /* The margin highlight fill color (default: transparent). */
      [@yojson.option] [@key "eventTargetColor"]
      eventTargetColor: option(DOM.RGBA.t), /* The event target element highlight fill color (default: transparent). */
      [@yojson.option] [@key "shapeColor"]
      shapeColor: option(DOM.RGBA.t), /* The shape outside fill color (default: transparent). */
      [@yojson.option] [@key "shapeMarginColor"]
      shapeMarginColor: option(DOM.RGBA.t), /* The shape margin fill color (default: transparent). */
      [@yojson.option] [@key "cssGridColor"]
      cssGridColor: option(DOM.RGBA.t), /* The grid layout color (default: transparent). */
      [@yojson.option] [@key "colorFormat"]
      colorFormat: option(ColorFormat.t), /* The color format used to format color styles (default: hex). */
      [@yojson.option] [@key "gridHighlightConfig"]
      gridHighlightConfig: option(GridHighlightConfig.t), /* The grid layout highlight configuration (default: all transparent). */
      [@yojson.option] [@key "flexContainerHighlightConfig"]
      flexContainerHighlightConfig: option(FlexContainerHighlightConfig.t), /* The flex container highlight configuration (default: all transparent). */
      [@yojson.option] [@key "flexItemHighlightConfig"]
      flexItemHighlightConfig: option(FlexItemHighlightConfig.t), /* The flex item highlight configuration (default: all transparent). */
      [@yojson.option] [@key "contrastAlgorithm"]
      contrastAlgorithm: option(ContrastAlgorithm.t), /* The contrast algorithm to use for the contrast ratio (default: aa). */
      [@yojson.option] [@key "containerQueryContainerHighlightConfig"]
      containerQueryContainerHighlightConfig:
        option(ContainerQueryContainerHighlightConfig.t) /* The container query container highlight configuration (default: all transparent). */,
    };
  }
  and ColorFormat: {
    type _colorformat = [ | `rgb | `hsl | `hex];
    let _colorformat_of_yojson: Yojson.Basic.t => _colorformat;
    let yojson_of__colorformat: _colorformat => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _colorformat;
  } = {
    type _colorformat = [ | `rgb | `hsl | `hex];
    let _colorformat_of_yojson =
      fun
      | `String("rgb") => `rgb
      | `String("hsl") => `hsl
      | `String("hex") => `hex
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__colorformat =
      fun
      | `rgb => `String("rgb")
      | `hsl => `String("hsl")
      | `hex => `String("hex");
    /* No description provided */
    [@deriving yojson]
    type t = _colorformat;
  }
  and GridNodeHighlightConfig: {
    /* Configurations for Persistent Grid Highlight */
    [@deriving yojson]
    type t = {
      [@key "gridHighlightConfig"]
      gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  } = {
    /* Configurations for Persistent Grid Highlight */
    [@deriving yojson]
    type t = {
      [@key "gridHighlightConfig"]
      gridHighlightConfig: GridHighlightConfig.t, /* A descriptor for the highlight appearance. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  }
  and FlexNodeHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "flexContainerHighlightConfig"]
      flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "flexContainerHighlightConfig"]
      flexContainerHighlightConfig: FlexContainerHighlightConfig.t, /* A descriptor for the highlight appearance of flex containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  }
  and ScrollSnapContainerHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "snapportBorder"]
      snapportBorder: option(LineStyle.t), /* The style of the snapport border (default: transparent) */
      [@yojson.option] [@key "snapAreaBorder"]
      snapAreaBorder: option(LineStyle.t), /* The style of the snap area border (default: transparent) */
      [@yojson.option] [@key "scrollMarginColor"]
      scrollMarginColor: option(DOM.RGBA.t), /* The margin highlight fill color (default: transparent). */
      [@yojson.option] [@key "scrollPaddingColor"]
      scrollPaddingColor: option(DOM.RGBA.t) /* The padding highlight fill color (default: transparent). */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "snapportBorder"]
      snapportBorder: option(LineStyle.t), /* The style of the snapport border (default: transparent) */
      [@yojson.option] [@key "snapAreaBorder"]
      snapAreaBorder: option(LineStyle.t), /* The style of the snap area border (default: transparent) */
      [@yojson.option] [@key "scrollMarginColor"]
      scrollMarginColor: option(DOM.RGBA.t), /* The margin highlight fill color (default: transparent). */
      [@yojson.option] [@key "scrollPaddingColor"]
      scrollPaddingColor: option(DOM.RGBA.t) /* The padding highlight fill color (default: transparent). */,
    };
  }
  and ScrollSnapHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "scrollSnapContainerHighlightConfig"]
      scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "scrollSnapContainerHighlightConfig"]
      scrollSnapContainerHighlightConfig: ScrollSnapContainerHighlightConfig.t, /* A descriptor for the highlight appearance of scroll snap containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the node to highlight. */,
    };
  }
  and HingeConfig: {
    /* Configuration for dual screen hinge */
    [@deriving yojson]
    type t = {
      [@key "rect"]
      rect: DOM.Rect.t, /* A rectangle represent hinge */
      [@yojson.option] [@key "contentColor"]
      contentColor: option(DOM.RGBA.t), /* The content box highlight fill color (default: a dark color). */
      [@yojson.option] [@key "outlineColor"]
      outlineColor: option(DOM.RGBA.t) /* The content box highlight outline color (default: transparent). */,
    };
  } = {
    /* Configuration for dual screen hinge */
    [@deriving yojson]
    type t = {
      [@key "rect"]
      rect: DOM.Rect.t, /* A rectangle represent hinge */
      [@yojson.option] [@key "contentColor"]
      contentColor: option(DOM.RGBA.t), /* The content box highlight fill color (default: a dark color). */
      [@yojson.option] [@key "outlineColor"]
      outlineColor: option(DOM.RGBA.t) /* The content box highlight outline color (default: transparent). */,
    };
  }
  and ContainerQueryHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "containerQueryContainerHighlightConfig"]
      containerQueryContainerHighlightConfig: ContainerQueryContainerHighlightConfig.t, /* A descriptor for the highlight appearance of container query containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the container node to highlight. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "containerQueryContainerHighlightConfig"]
      containerQueryContainerHighlightConfig: ContainerQueryContainerHighlightConfig.t, /* A descriptor for the highlight appearance of container query containers. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the container node to highlight. */,
    };
  }
  and ContainerQueryContainerHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "containerBorder"]
      containerBorder: option(LineStyle.t), /* The style of the container border. */
      [@yojson.option] [@key "descendantBorder"]
      descendantBorder: option(LineStyle.t) /* The style of the descendants' borders. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "containerBorder"]
      containerBorder: option(LineStyle.t), /* The style of the container border. */
      [@yojson.option] [@key "descendantBorder"]
      descendantBorder: option(LineStyle.t) /* The style of the descendants' borders. */,
    };
  }
  and IsolatedElementHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "isolationModeHighlightConfig"]
      isolationModeHighlightConfig: IsolationModeHighlightConfig.t, /* A descriptor for the highlight appearance of an element in isolation mode. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the isolated element to highlight. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "isolationModeHighlightConfig"]
      isolationModeHighlightConfig: IsolationModeHighlightConfig.t, /* A descriptor for the highlight appearance of an element in isolation mode. */
      [@key "nodeId"]
      nodeId: DOM.NodeId.t /* Identifier of the isolated element to highlight. */,
    };
  }
  and IsolationModeHighlightConfig: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "resizerColor"]
      resizerColor: option(DOM.RGBA.t), /* The fill color of the resizers (default: transparent). */
      [@yojson.option] [@key "resizerHandleColor"]
      resizerHandleColor: option(DOM.RGBA.t), /* The fill color for resizer handles (default: transparent). */
      [@yojson.option] [@key "maskColor"]
      maskColor: option(DOM.RGBA.t) /* The fill color for the mask covering non-isolated elements (default: transparent). */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "resizerColor"]
      resizerColor: option(DOM.RGBA.t), /* The fill color of the resizers (default: transparent). */
      [@yojson.option] [@key "resizerHandleColor"]
      resizerHandleColor: option(DOM.RGBA.t), /* The fill color for resizer handles (default: transparent). */
      [@yojson.option] [@key "maskColor"]
      maskColor: option(DOM.RGBA.t) /* The fill color for the mask covering non-isolated elements (default: transparent). */,
    };
  }
  and InspectMode: {
    type _inspectmode = [
      | `searchForNode
      | `searchForUAShadowDOM
      | `captureAreaScreenshot
      | `showDistances
      | `none
    ];
    let _inspectmode_of_yojson: Yojson.Basic.t => _inspectmode;
    let yojson_of__inspectmode: _inspectmode => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _inspectmode;
  } = {
    type _inspectmode = [
      | `searchForNode
      | `searchForUAShadowDOM
      | `captureAreaScreenshot
      | `showDistances
      | `none
    ];
    let _inspectmode_of_yojson =
      fun
      | `String("searchForNode") => `searchForNode
      | `String("searchForUAShadowDOM") => `searchForUAShadowDOM
      | `String("captureAreaScreenshot") => `captureAreaScreenshot
      | `String("showDistances") => `showDistances
      | `String("none") => `none
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__inspectmode =
      fun
      | `searchForNode => `String("searchForNode")
      | `searchForUAShadowDOM => `String("searchForUAShadowDOM")
      | `captureAreaScreenshot => `String("captureAreaScreenshot")
      | `showDistances => `String("showDistances")
      | `none => `String("none");
    /* No description provided */
    [@deriving yojson]
    type t = _inspectmode;
  };
}
and Page: {
  module rec FrameId: {
    /* Unique frame identifier. */
    [@deriving yojson]
    type t = string;
  }
  and AdFrameType: {
    type _adframetype = [ | `none | `child | `root];
    let _adframetype_of_yojson: Yojson.Basic.t => _adframetype;
    let yojson_of__adframetype: _adframetype => Yojson.Basic.t;
    /* Indicates whether a frame has been identified as an ad. */
    [@deriving yojson]
    type t = _adframetype;
  }
  and AdFrameExplanation: {
    type _adframeexplanation = [
      | `ParentIsAd
      | `CreatedByAdScript
      | `MatchedBlockingRule
    ];
    let _adframeexplanation_of_yojson: Yojson.Basic.t => _adframeexplanation;
    let yojson_of__adframeexplanation: _adframeexplanation => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _adframeexplanation;
  }
  and AdFrameStatus: {
    /* Indicates whether a frame has been identified as an ad and why. */
    [@deriving yojson]
    type t = {
      [@key "adFrameType"]
      adFrameType: AdFrameType.t, /* No description provided */
      [@yojson.option] [@key "explanations"]
      explanations: option(list(AdFrameExplanation.t)) /* No description provided */,
    };
  }
  and SecureContextType: {
    type _securecontexttype = [
      | `Secure
      | `SecureLocalhost
      | `InsecureScheme
      | `InsecureAncestor
    ];
    let _securecontexttype_of_yojson: Yojson.Basic.t => _securecontexttype;
    let yojson_of__securecontexttype: _securecontexttype => Yojson.Basic.t;
    /* Indicates whether the frame is a secure context and why it is the case. */
    [@deriving yojson]
    type t = _securecontexttype;
  }
  and CrossOriginIsolatedContextType: {
    type _crossoriginisolatedcontexttype = [
      | `Isolated
      | `NotIsolated
      | `NotIsolatedFeatureDisabled
    ];
    let _crossoriginisolatedcontexttype_of_yojson:
      Yojson.Basic.t => _crossoriginisolatedcontexttype;
    let yojson_of__crossoriginisolatedcontexttype:
      _crossoriginisolatedcontexttype => Yojson.Basic.t;
    /* Indicates whether the frame is cross-origin isolated and why it is the case. */
    [@deriving yojson]
    type t = _crossoriginisolatedcontexttype;
  }
  and GatedAPIFeatures: {
    type _gatedapifeatures = [
      | `SharedArrayBuffers
      | `SharedArrayBuffersTransferAllowed
      | `PerformanceMeasureMemory
      | `PerformanceProfile
    ];
    let _gatedapifeatures_of_yojson: Yojson.Basic.t => _gatedapifeatures;
    let yojson_of__gatedapifeatures: _gatedapifeatures => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _gatedapifeatures;
  }
  and PermissionsPolicyFeature: {
    type _permissionspolicyfeature = [
      | `accelerometer
      | `ambient_light_sensor
      | `attribution_reporting
      | `autoplay
      | `camera
      | `ch_dpr
      | `ch_device_memory
      | `ch_downlink
      | `ch_ect
      | `ch_prefers_color_scheme
      | `ch_rtt
      | `ch_ua
      | `ch_ua_arch
      | `ch_ua_bitness
      | `ch_ua_platform
      | `ch_ua_model
      | `ch_ua_mobile
      | `ch_ua_full_version
      | `ch_ua_full_version_list
      | `ch_ua_platform_version
      | `ch_ua_reduced
      | `ch_viewport_height
      | `ch_viewport_width
      | `ch_width
      | `clipboard_read
      | `clipboard_write
      | `cross_origin_isolated
      | `direct_sockets
      | `display_capture
      | `document_domain
      | `encrypted_media
      | `execution_while_out_of_viewport
      | `execution_while_not_rendered
      | `focus_without_user_activation
      | `fullscreen
      | `frobulate
      | `gamepad
      | `geolocation
      | `gyroscope
      | `hid
      | `idle_detection
      | `interest_cohort
      | `join_ad_interest_group
      | `keyboard_map
      | `magnetometer
      | `microphone
      | `midi
      | `otp_credentials
      | `payment
      | `picture_in_picture
      | `publickey_credentials_get
      | `run_ad_auction
      | `screen_wake_lock
      | `serial
      | `shared_autofill
      | `storage_access_api
      | `sync_xhr
      | `trust_token_redemption
      | `usb
      | `vertical_scroll
      | `web_share
      | `window_placement
      | `xr_spatial_tracking
    ];
    let _permissionspolicyfeature_of_yojson:
      Yojson.Basic.t => _permissionspolicyfeature;
    let yojson_of__permissionspolicyfeature:
      _permissionspolicyfeature => Yojson.Basic.t;
    /* All Permissions Policy features. This enum should match the one defined
       in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
    [@deriving yojson]
    type t = _permissionspolicyfeature;
  }
  and PermissionsPolicyBlockReason: {
    type _permissionspolicyblockreason = [ | `Header | `IframeAttribute];
    let _permissionspolicyblockreason_of_yojson:
      Yojson.Basic.t => _permissionspolicyblockreason;
    let yojson_of__permissionspolicyblockreason:
      _permissionspolicyblockreason => Yojson.Basic.t;
    /* Reason for a permissions policy feature to be disabled. */
    [@deriving yojson]
    type t = _permissionspolicyblockreason;
  }
  and PermissionsPolicyBlockLocator: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: FrameId.t, /* No description provided */
      [@key "blockReason"]
      blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
    };
  }
  and PermissionsPolicyFeatureState: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "feature"]
      feature: PermissionsPolicyFeature.t, /* No description provided */
      [@key "allowed"]
      allowed: bool, /* No description provided */
      [@yojson.option] [@key "locator"]
      locator: option(PermissionsPolicyBlockLocator.t) /* No description provided */,
    };
  }
  and OriginTrialTokenStatus: {
    type _origintrialtokenstatus = [
      | `Success
      | `NotSupported
      | `Insecure
      | `Expired
      | `WrongOrigin
      | `InvalidSignature
      | `Malformed
      | `WrongVersion
      | `FeatureDisabled
      | `TokenDisabled
      | `FeatureDisabledForUser
      | `UnknownTrial
    ];
    let _origintrialtokenstatus_of_yojson:
      Yojson.Basic.t => _origintrialtokenstatus;
    let yojson_of__origintrialtokenstatus:
      _origintrialtokenstatus => Yojson.Basic.t;
    /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
       Status for an Origin Trial token. */
    [@deriving yojson]
    type t = _origintrialtokenstatus;
  }
  and OriginTrialStatus: {
    type _origintrialstatus = [
      | `Enabled
      | `ValidTokenNotProvided
      | `OSNotSupported
      | `TrialNotAllowed
    ];
    let _origintrialstatus_of_yojson: Yojson.Basic.t => _origintrialstatus;
    let yojson_of__origintrialstatus: _origintrialstatus => Yojson.Basic.t;
    /* Status for an Origin Trial. */
    [@deriving yojson]
    type t = _origintrialstatus;
  }
  and OriginTrialUsageRestriction: {
    type _origintrialusagerestriction = [ | `None | `Subset];
    let _origintrialusagerestriction_of_yojson:
      Yojson.Basic.t => _origintrialusagerestriction;
    let yojson_of__origintrialusagerestriction:
      _origintrialusagerestriction => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _origintrialusagerestriction;
  }
  and OriginTrialToken: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "origin"]
      origin: string, /* No description provided */
      [@key "matchSubDomains"]
      matchSubDomains: bool, /* No description provided */
      [@key "trialName"]
      trialName: string, /* No description provided */
      [@key "expiryTime"]
      expiryTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "isThirdParty"]
      isThirdParty: bool, /* No description provided */
      [@key "usageRestriction"]
      usageRestriction: OriginTrialUsageRestriction.t /* No description provided */,
    };
  }
  and OriginTrialTokenWithStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "rawTokenText"]
      rawTokenText: string, /* No description provided */
      [@yojson.option] [@key "parsedToken"]
      parsedToken: option(OriginTrialToken.t), /* `parsedToken` is present only when the token is extractable and
parsable. */
      [@key "status"]
      status: OriginTrialTokenStatus.t /* No description provided */,
    };
  }
  and OriginTrial: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "trialName"]
      trialName: string, /* No description provided */
      [@key "status"]
      status: OriginTrialStatus.t, /* No description provided */
      [@key "tokensWithStatus"]
      tokensWithStatus: list(OriginTrialTokenWithStatus.t) /* No description provided */,
    };
  }
  and Frame: {
    /* Information about the Frame on the page. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: FrameId.t, /* Frame unique identifier. */
      [@yojson.option] [@key "parentId"]
      parentId: option(FrameId.t), /* Parent frame identifier. */
      [@key "loaderId"]
      loaderId: Network.LoaderId.t, /* Identifier of the loader associated with this frame. */
      [@yojson.option] [@key "name"]
      name: option(string), /* Frame's name as specified in the tag. */
      [@key "url"]
      url: string, /* Frame document's URL without fragment. */
      [@yojson.option] [@key "urlFragment"]
      urlFragment: option(string), /* Frame document's URL fragment including the '#'. */
      [@key "domainAndRegistry"]
      domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
      [@key "securityOrigin"]
      securityOrigin: string, /* Frame document's security origin. */
      [@key "mimeType"]
      mimeType: string, /* Frame document's mimeType as determined by the browser. */
      [@yojson.option] [@key "unreachableUrl"]
      unreachableUrl: option(string), /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
      [@yojson.option] [@key "adFrameStatus"]
      adFrameStatus: option(AdFrameStatus.t), /* Indicates whether this frame was tagged as an ad and why. */
      [@key "secureContextType"]
      secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
      [@key "crossOriginIsolatedContextType"]
      crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
      [@key "gatedAPIFeatures"]
      gatedAPIFeatures: list(GatedAPIFeatures.t) /* Indicated which gated APIs / features are available. */,
    };
  }
  and FrameResource: {
    /* Information about the Resource on the page. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Resource URL. */
      [@key "type"]
      type_: Network.ResourceType.t, /* Type of this resource. */
      [@key "mimeType"]
      mimeType: string, /* Resource mimeType as determined by the browser. */
      [@yojson.option] [@key "lastModified"]
      lastModified: option(Network.TimeSinceEpoch.t), /* last-modified timestamp as reported by server. */
      [@yojson.option] [@key "contentSize"]
      contentSize: option(float), /* Resource content size. */
      [@yojson.option] [@key "failed"]
      failed: option(bool), /* True if the resource failed to load. */
      [@yojson.option] [@key "canceled"]
      canceled: option(bool) /* True if the resource was canceled during loading. */,
    };
  }
  and FrameResourceTree: {
    /* Information about the Frame hierarchy along with their cached resources. */
    [@deriving yojson]
    type t = {
      [@key "frame"]
      frame: Frame.t, /* Frame information for this tree item. */
      [@yojson.option] [@key "childFrames"]
      childFrames: option(list(FrameResourceTree.t)), /* Child frames. */
      [@key "resources"]
      resources: list(FrameResource.t) /* Information about frame resources. */,
    };
  }
  and FrameTree: {
    /* Information about the Frame hierarchy. */
    [@deriving yojson]
    type t = {
      [@key "frame"]
      frame: Frame.t, /* Frame information for this tree item. */
      [@yojson.option] [@key "childFrames"]
      childFrames: option(list(FrameTree.t)) /* Child frames. */,
    };
  }
  and ScriptIdentifier: {
    /* Unique script identifier. */
    [@deriving yojson]
    type t = string;
  }
  and TransitionType: {
    type _transitiontype = [
      | `link
      | `typed
      | `address_bar
      | `auto_bookmark
      | `auto_subframe
      | `manual_subframe
      | `generated
      | `auto_toplevel
      | `form_submit
      | `reload
      | `keyword
      | `keyword_generated
      | `other
    ];
    let _transitiontype_of_yojson: Yojson.Basic.t => _transitiontype;
    let yojson_of__transitiontype: _transitiontype => Yojson.Basic.t;
    /* Transition type. */
    [@deriving yojson]
    type t = _transitiontype;
  }
  and NavigationEntry: {
    /* Navigation history entry. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: float, /* Unique id of the navigation history entry. */
      [@key "url"]
      url: string, /* URL of the navigation history entry. */
      [@key "userTypedURL"]
      userTypedURL: string, /* URL that the user typed in the url bar. */
      [@key "title"]
      title: string, /* Title of the navigation history entry. */
      [@key "transitionType"]
      transitionType: TransitionType.t /* Transition type. */,
    };
  }
  and ScreencastFrameMetadata: {
    /* Screencast frame metadata. */
    [@deriving yojson]
    type t = {
      [@key "offsetTop"]
      offsetTop: float, /* Top offset in DIP. */
      [@key "pageScaleFactor"]
      pageScaleFactor: float, /* Page scale factor. */
      [@key "deviceWidth"]
      deviceWidth: float, /* Device screen width in DIP. */
      [@key "deviceHeight"]
      deviceHeight: float, /* Device screen height in DIP. */
      [@key "scrollOffsetX"]
      scrollOffsetX: float, /* Position of horizontal scroll in CSS pixels. */
      [@key "scrollOffsetY"]
      scrollOffsetY: float, /* Position of vertical scroll in CSS pixels. */
      [@yojson.option] [@key "timestamp"]
      timestamp: option(Network.TimeSinceEpoch.t) /* Frame swap timestamp. */,
    };
  }
  and DialogType: {
    type _dialogtype = [ | `alert | `confirm | `prompt | `beforeunload];
    let _dialogtype_of_yojson: Yojson.Basic.t => _dialogtype;
    let yojson_of__dialogtype: _dialogtype => Yojson.Basic.t;
    /* Javascript dialog type. */
    [@deriving yojson]
    type t = _dialogtype;
  }
  and AppManifestError: {
    /* Error while paring app manifest. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@key "critical"]
      critical: float, /* If criticial, this is a non-recoverable parse error. */
      [@key "line"]
      line: float, /* Error line. */
      [@key "column"]
      column: float /* Error column. */,
    };
  }
  and AppManifestParsedProperties: {
    /* Parsed app manifest properties. */
    [@deriving yojson]
    type t = {
      [@key "scope"]
      scope: string /* Computed scope value */,
    };
  }
  and LayoutViewport: {
    /* Layout viewport position and dimensions. */
    [@deriving yojson]
    type t = {
      [@key "pageX"]
      pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
      [@key "pageY"]
      pageY: float, /* Vertical offset relative to the document (CSS pixels). */
      [@key "clientWidth"]
      clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
      [@key "clientHeight"]
      clientHeight: float /* Height (CSS pixels), excludes scrollbar if present. */,
    };
  }
  and VisualViewport: {
    /* Visual viewport position, dimensions, and scale. */
    [@deriving yojson]
    type t = {
      [@key "offsetX"]
      offsetX: float, /* Horizontal offset relative to the layout viewport (CSS pixels). */
      [@key "offsetY"]
      offsetY: float, /* Vertical offset relative to the layout viewport (CSS pixels). */
      [@key "pageX"]
      pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
      [@key "pageY"]
      pageY: float, /* Vertical offset relative to the document (CSS pixels). */
      [@key "clientWidth"]
      clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
      [@key "clientHeight"]
      clientHeight: float, /* Height (CSS pixels), excludes scrollbar if present. */
      [@key "scale"]
      scale: float, /* Scale relative to the ideal viewport (size at width=device-width). */
      [@yojson.option] [@key "zoom"]
      zoom: option(float) /* Page zoom factor (CSS to device independent pixels ratio). */,
    };
  }
  and Viewport: {
    /* Viewport for capturing screenshot. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X offset in device independent pixels (dip). */
      [@key "y"]
      y: float, /* Y offset in device independent pixels (dip). */
      [@key "width"]
      width: float, /* Rectangle width in device independent pixels (dip). */
      [@key "height"]
      height: float, /* Rectangle height in device independent pixels (dip). */
      [@key "scale"]
      scale: float /* Page scale factor. */,
    };
  }
  and FontFamilies: {
    /* Generic font families collection. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "standard"]
      standard: option(string), /* The standard font-family. */
      [@yojson.option] [@key "fixed"]
      fixed: option(string), /* The fixed font-family. */
      [@yojson.option] [@key "serif"]
      serif: option(string), /* The serif font-family. */
      [@yojson.option] [@key "sansSerif"]
      sansSerif: option(string), /* The sansSerif font-family. */
      [@yojson.option] [@key "cursive"]
      cursive: option(string), /* The cursive font-family. */
      [@yojson.option] [@key "fantasy"]
      fantasy: option(string), /* The fantasy font-family. */
      [@yojson.option] [@key "pictograph"]
      pictograph: option(string) /* The pictograph font-family. */,
    };
  }
  and FontSizes: {
    /* Default font sizes. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "standard"]
      standard: option(float), /* Default standard font size. */
      [@yojson.option] [@key "fixed"]
      fixed: option(float) /* Default fixed font size. */,
    };
  }
  and ClientNavigationReason: {
    type _clientnavigationreason = [
      | `formSubmissionGet
      | `formSubmissionPost
      | `httpHeaderRefresh
      | `scriptInitiated
      | `metaTagRefresh
      | `pageBlockInterstitial
      | `reload
      | `anchorClick
    ];
    let _clientnavigationreason_of_yojson:
      Yojson.Basic.t => _clientnavigationreason;
    let yojson_of__clientnavigationreason:
      _clientnavigationreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _clientnavigationreason;
  }
  and ClientNavigationDisposition: {
    type _clientnavigationdisposition = [
      | `currentTab
      | `newTab
      | `newWindow
      | `download
    ];
    let _clientnavigationdisposition_of_yojson:
      Yojson.Basic.t => _clientnavigationdisposition;
    let yojson_of__clientnavigationdisposition:
      _clientnavigationdisposition => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _clientnavigationdisposition;
  }
  and InstallabilityErrorArgument: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
      [@key "value"]
      value: string /* Argument value (e.g. value:'64'). */,
    };
  }
  and InstallabilityError: {
    /* The installability error */
    [@deriving yojson]
    type t = {
      [@key "errorId"]
      errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
      [@key "errorArguments"]
      errorArguments: list(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
    };
  }
  and ReferrerPolicy: {
    type _referrerpolicy = [
      | `noReferrer
      | `noReferrerWhenDowngrade
      | `origin
      | `originWhenCrossOrigin
      | `sameOrigin
      | `strictOrigin
      | `strictOriginWhenCrossOrigin
      | `unsafeUrl
    ];
    let _referrerpolicy_of_yojson: Yojson.Basic.t => _referrerpolicy;
    let yojson_of__referrerpolicy: _referrerpolicy => Yojson.Basic.t;
    /* The referring-policy used for the navigation. */
    [@deriving yojson]
    type t = _referrerpolicy;
  }
  and CompilationCacheParams: {
    /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The URL of the script to produce a compilation cache entry for. */
      [@yojson.option] [@key "eager"]
      eager: option(bool) /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
    };
  }
  and NavigationType: {
    type _navigationtype = [ | `Navigation | `BackForwardCacheRestore];
    let _navigationtype_of_yojson: Yojson.Basic.t => _navigationtype;
    let yojson_of__navigationtype: _navigationtype => Yojson.Basic.t;
    /* The type of a frameNavigated event. */
    [@deriving yojson]
    type t = _navigationtype;
  }
  and BackForwardCacheNotRestoredReason: {
    type _backforwardcachenotrestoredreason = [
      | `NotMainFrame
      | `BackForwardCacheDisabled
      | `RelatedActiveContentsExist
      | `HTTPStatusNotOK
      | `SchemeNotHTTPOrHTTPS
      | `Loading
      | `WasGrantedMediaAccess
      | `DisableForRenderFrameHostCalled
      | `DomainNotAllowed
      | `HTTPMethodNotGET
      | `SubframeIsNavigating
      | `Timeout
      | `CacheLimit
      | `JavaScriptExecution
      | `RendererProcessKilled
      | `RendererProcessCrashed
      | `GrantedMediaStreamAccess
      | `SchedulerTrackedFeatureUsed
      | `ConflictingBrowsingInstance
      | `CacheFlushed
      | `ServiceWorkerVersionActivation
      | `SessionRestored
      | `ServiceWorkerPostMessage
      | `EnteredBackForwardCacheBeforeServiceWorkerHostAdded
      | `RenderFrameHostReused_SameSite
      | `RenderFrameHostReused_CrossSite
      | `ServiceWorkerClaim
      | `IgnoreEventAndEvict
      | `HaveInnerContents
      | `TimeoutPuttingInCache
      | `BackForwardCacheDisabledByLowMemory
      | `BackForwardCacheDisabledByCommandLine
      | `NetworkRequestDatapipeDrainedAsBytesConsumer
      | `NetworkRequestRedirected
      | `NetworkRequestTimeout
      | `NetworkExceedsBufferLimit
      | `NavigationCancelledWhileRestoring
      | `NotMostRecentNavigationEntry
      | `BackForwardCacheDisabledForPrerender
      | `UserAgentOverrideDiffers
      | `ForegroundCacheLimit
      | `BrowsingInstanceNotSwapped
      | `BackForwardCacheDisabledForDelegate
      | `OptInUnloadHeaderNotPresent
      | `UnloadHandlerExistsInMainFrame
      | `UnloadHandlerExistsInSubFrame
      | `ServiceWorkerUnregistration
      | `CacheControlNoStore
      | `CacheControlNoStoreCookieModified
      | `CacheControlNoStoreHTTPOnlyCookieModified
      | `NoResponseHead
      | `Unknown
      | `ActivationNavigationsDisallowedForBug1234857
      | `WebSocket
      | `WebTransport
      | `WebRTC
      | `MainResourceHasCacheControlNoStore
      | `MainResourceHasCacheControlNoCache
      | `SubresourceHasCacheControlNoStore
      | `SubresourceHasCacheControlNoCache
      | `ContainsPlugins
      | `DocumentLoaded
      | `DedicatedWorkerOrWorklet
      | `OutstandingNetworkRequestOthers
      | `OutstandingIndexedDBTransaction
      | `RequestedNotificationsPermission
      | `RequestedMIDIPermission
      | `RequestedAudioCapturePermission
      | `RequestedVideoCapturePermission
      | `RequestedBackForwardCacheBlockedSensors
      | `RequestedBackgroundWorkPermission
      | `BroadcastChannel
      | `IndexedDBConnection
      | `WebXR
      | `SharedWorker
      | `WebLocks
      | `WebHID
      | `WebShare
      | `RequestedStorageAccessGrant
      | `WebNfc
      | `OutstandingNetworkRequestFetch
      | `OutstandingNetworkRequestXHR
      | `AppBanner
      | `Printing
      | `WebDatabase
      | `PictureInPicture
      | `Portal
      | `SpeechRecognizer
      | `IdleManager
      | `PaymentManager
      | `SpeechSynthesis
      | `KeyboardLock
      | `WebOTPService
      | `OutstandingNetworkRequestDirectSocket
      | `InjectedJavascript
      | `InjectedStyleSheet
      | `Dummy
      | `ContentSecurityHandler
      | `ContentWebAuthenticationAPI
      | `ContentFileChooser
      | `ContentSerial
      | `ContentFileSystemAccess
      | `ContentMediaDevicesDispatcherHost
      | `ContentWebBluetooth
      | `ContentWebUSB
      | `ContentMediaSession
      | `ContentMediaSessionService
      | `EmbedderPopupBlockerTabHelper
      | `EmbedderSafeBrowsingTriggeredPopupBlocker
      | `EmbedderSafeBrowsingThreatDetails
      | `EmbedderAppBannerManager
      | `EmbedderDomDistillerViewerSource
      | `EmbedderDomDistillerSelfDeletingRequestDelegate
      | `EmbedderOomInterventionTabHelper
      | `EmbedderOfflinePage
      | `EmbedderChromePasswordManagerClientBindCredentialManager
      | `EmbedderPermissionRequestManager
      | `EmbedderModalDialog
      | `EmbedderExtensions
      | `EmbedderExtensionMessaging
      | `EmbedderExtensionMessagingForOpenPort
      | `EmbedderExtensionSentMessageToCachedFrame
    ];
    let _backforwardcachenotrestoredreason_of_yojson:
      Yojson.Basic.t => _backforwardcachenotrestoredreason;
    let yojson_of__backforwardcachenotrestoredreason:
      _backforwardcachenotrestoredreason => Yojson.Basic.t;
    /* List of not restored reasons for back-forward cache. */
    [@deriving yojson]
    type t = _backforwardcachenotrestoredreason;
  }
  and BackForwardCacheNotRestoredReasonType: {
    type _backforwardcachenotrestoredreasontype = [
      | `SupportPending
      | `PageSupportNeeded
      | `Circumstantial
    ];
    let _backforwardcachenotrestoredreasontype_of_yojson:
      Yojson.Basic.t => _backforwardcachenotrestoredreasontype;
    let yojson_of__backforwardcachenotrestoredreasontype:
      _backforwardcachenotrestoredreasontype => Yojson.Basic.t;
    /* Types of not restored reasons for back-forward cache. */
    [@deriving yojson]
    type t = _backforwardcachenotrestoredreasontype;
  }
  and BackForwardCacheNotRestoredExplanation: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: BackForwardCacheNotRestoredReasonType.t, /* Type of the reason */
      [@key "reason"]
      reason: BackForwardCacheNotRestoredReason.t /* Not restored reason */,
    };
  };
} = {
  module rec FrameId: {
    /* Unique frame identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique frame identifier. */
    [@deriving yojson]
    type t = string;
  }
  and AdFrameType: {
    type _adframetype = [ | `none | `child | `root];
    let _adframetype_of_yojson: Yojson.Basic.t => _adframetype;
    let yojson_of__adframetype: _adframetype => Yojson.Basic.t;
    /* Indicates whether a frame has been identified as an ad. */
    [@deriving yojson]
    type t = _adframetype;
  } = {
    type _adframetype = [ | `none | `child | `root];
    let _adframetype_of_yojson =
      fun
      | `String("none") => `none
      | `String("child") => `child
      | `String("root") => `root
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__adframetype =
      fun
      | `none => `String("none")
      | `child => `String("child")
      | `root => `String("root");
    /* Indicates whether a frame has been identified as an ad. */
    [@deriving yojson]
    type t = _adframetype;
  }
  and AdFrameExplanation: {
    type _adframeexplanation = [
      | `ParentIsAd
      | `CreatedByAdScript
      | `MatchedBlockingRule
    ];
    let _adframeexplanation_of_yojson: Yojson.Basic.t => _adframeexplanation;
    let yojson_of__adframeexplanation: _adframeexplanation => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _adframeexplanation;
  } = {
    type _adframeexplanation = [
      | `ParentIsAd
      | `CreatedByAdScript
      | `MatchedBlockingRule
    ];
    let _adframeexplanation_of_yojson =
      fun
      | `String("ParentIsAd") => `ParentIsAd
      | `String("CreatedByAdScript") => `CreatedByAdScript
      | `String("MatchedBlockingRule") => `MatchedBlockingRule
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__adframeexplanation =
      fun
      | `ParentIsAd => `String("ParentIsAd")
      | `CreatedByAdScript => `String("CreatedByAdScript")
      | `MatchedBlockingRule => `String("MatchedBlockingRule");
    /* No description provided */
    [@deriving yojson]
    type t = _adframeexplanation;
  }
  and AdFrameStatus: {
    /* Indicates whether a frame has been identified as an ad and why. */
    [@deriving yojson]
    type t = {
      [@key "adFrameType"]
      adFrameType: AdFrameType.t, /* No description provided */
      [@yojson.option] [@key "explanations"]
      explanations: option(list(AdFrameExplanation.t)) /* No description provided */,
    };
  } = {
    /* Indicates whether a frame has been identified as an ad and why. */
    [@deriving yojson]
    type t = {
      [@key "adFrameType"]
      adFrameType: AdFrameType.t, /* No description provided */
      [@yojson.option] [@key "explanations"]
      explanations: option(list(AdFrameExplanation.t)) /* No description provided */,
    };
  }
  and SecureContextType: {
    type _securecontexttype = [
      | `Secure
      | `SecureLocalhost
      | `InsecureScheme
      | `InsecureAncestor
    ];
    let _securecontexttype_of_yojson: Yojson.Basic.t => _securecontexttype;
    let yojson_of__securecontexttype: _securecontexttype => Yojson.Basic.t;
    /* Indicates whether the frame is a secure context and why it is the case. */
    [@deriving yojson]
    type t = _securecontexttype;
  } = {
    type _securecontexttype = [
      | `Secure
      | `SecureLocalhost
      | `InsecureScheme
      | `InsecureAncestor
    ];
    let _securecontexttype_of_yojson =
      fun
      | `String("Secure") => `Secure
      | `String("SecureLocalhost") => `SecureLocalhost
      | `String("InsecureScheme") => `InsecureScheme
      | `String("InsecureAncestor") => `InsecureAncestor
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__securecontexttype =
      fun
      | `Secure => `String("Secure")
      | `SecureLocalhost => `String("SecureLocalhost")
      | `InsecureScheme => `String("InsecureScheme")
      | `InsecureAncestor => `String("InsecureAncestor");
    /* Indicates whether the frame is a secure context and why it is the case. */
    [@deriving yojson]
    type t = _securecontexttype;
  }
  and CrossOriginIsolatedContextType: {
    type _crossoriginisolatedcontexttype = [
      | `Isolated
      | `NotIsolated
      | `NotIsolatedFeatureDisabled
    ];
    let _crossoriginisolatedcontexttype_of_yojson:
      Yojson.Basic.t => _crossoriginisolatedcontexttype;
    let yojson_of__crossoriginisolatedcontexttype:
      _crossoriginisolatedcontexttype => Yojson.Basic.t;
    /* Indicates whether the frame is cross-origin isolated and why it is the case. */
    [@deriving yojson]
    type t = _crossoriginisolatedcontexttype;
  } = {
    type _crossoriginisolatedcontexttype = [
      | `Isolated
      | `NotIsolated
      | `NotIsolatedFeatureDisabled
    ];
    let _crossoriginisolatedcontexttype_of_yojson =
      fun
      | `String("Isolated") => `Isolated
      | `String("NotIsolated") => `NotIsolated
      | `String("NotIsolatedFeatureDisabled") => `NotIsolatedFeatureDisabled
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__crossoriginisolatedcontexttype =
      fun
      | `Isolated => `String("Isolated")
      | `NotIsolated => `String("NotIsolated")
      | `NotIsolatedFeatureDisabled => `String("NotIsolatedFeatureDisabled");
    /* Indicates whether the frame is cross-origin isolated and why it is the case. */
    [@deriving yojson]
    type t = _crossoriginisolatedcontexttype;
  }
  and GatedAPIFeatures: {
    type _gatedapifeatures = [
      | `SharedArrayBuffers
      | `SharedArrayBuffersTransferAllowed
      | `PerformanceMeasureMemory
      | `PerformanceProfile
    ];
    let _gatedapifeatures_of_yojson: Yojson.Basic.t => _gatedapifeatures;
    let yojson_of__gatedapifeatures: _gatedapifeatures => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _gatedapifeatures;
  } = {
    type _gatedapifeatures = [
      | `SharedArrayBuffers
      | `SharedArrayBuffersTransferAllowed
      | `PerformanceMeasureMemory
      | `PerformanceProfile
    ];
    let _gatedapifeatures_of_yojson =
      fun
      | `String("SharedArrayBuffers") => `SharedArrayBuffers
      | `String("SharedArrayBuffersTransferAllowed") => `SharedArrayBuffersTransferAllowed
      | `String("PerformanceMeasureMemory") => `PerformanceMeasureMemory
      | `String("PerformanceProfile") => `PerformanceProfile
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__gatedapifeatures =
      fun
      | `SharedArrayBuffers => `String("SharedArrayBuffers")
      | `SharedArrayBuffersTransferAllowed =>
        `String("SharedArrayBuffersTransferAllowed")
      | `PerformanceMeasureMemory => `String("PerformanceMeasureMemory")
      | `PerformanceProfile => `String("PerformanceProfile");
    /* No description provided */
    [@deriving yojson]
    type t = _gatedapifeatures;
  }
  and PermissionsPolicyFeature: {
    type _permissionspolicyfeature = [
      | `accelerometer
      | `ambient_light_sensor
      | `attribution_reporting
      | `autoplay
      | `camera
      | `ch_dpr
      | `ch_device_memory
      | `ch_downlink
      | `ch_ect
      | `ch_prefers_color_scheme
      | `ch_rtt
      | `ch_ua
      | `ch_ua_arch
      | `ch_ua_bitness
      | `ch_ua_platform
      | `ch_ua_model
      | `ch_ua_mobile
      | `ch_ua_full_version
      | `ch_ua_full_version_list
      | `ch_ua_platform_version
      | `ch_ua_reduced
      | `ch_viewport_height
      | `ch_viewport_width
      | `ch_width
      | `clipboard_read
      | `clipboard_write
      | `cross_origin_isolated
      | `direct_sockets
      | `display_capture
      | `document_domain
      | `encrypted_media
      | `execution_while_out_of_viewport
      | `execution_while_not_rendered
      | `focus_without_user_activation
      | `fullscreen
      | `frobulate
      | `gamepad
      | `geolocation
      | `gyroscope
      | `hid
      | `idle_detection
      | `interest_cohort
      | `join_ad_interest_group
      | `keyboard_map
      | `magnetometer
      | `microphone
      | `midi
      | `otp_credentials
      | `payment
      | `picture_in_picture
      | `publickey_credentials_get
      | `run_ad_auction
      | `screen_wake_lock
      | `serial
      | `shared_autofill
      | `storage_access_api
      | `sync_xhr
      | `trust_token_redemption
      | `usb
      | `vertical_scroll
      | `web_share
      | `window_placement
      | `xr_spatial_tracking
    ];
    let _permissionspolicyfeature_of_yojson:
      Yojson.Basic.t => _permissionspolicyfeature;
    let yojson_of__permissionspolicyfeature:
      _permissionspolicyfeature => Yojson.Basic.t;
    /* All Permissions Policy features. This enum should match the one defined
       in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
    [@deriving yojson]
    type t = _permissionspolicyfeature;
  } = {
    type _permissionspolicyfeature = [
      | `accelerometer
      | `ambient_light_sensor
      | `attribution_reporting
      | `autoplay
      | `camera
      | `ch_dpr
      | `ch_device_memory
      | `ch_downlink
      | `ch_ect
      | `ch_prefers_color_scheme
      | `ch_rtt
      | `ch_ua
      | `ch_ua_arch
      | `ch_ua_bitness
      | `ch_ua_platform
      | `ch_ua_model
      | `ch_ua_mobile
      | `ch_ua_full_version
      | `ch_ua_full_version_list
      | `ch_ua_platform_version
      | `ch_ua_reduced
      | `ch_viewport_height
      | `ch_viewport_width
      | `ch_width
      | `clipboard_read
      | `clipboard_write
      | `cross_origin_isolated
      | `direct_sockets
      | `display_capture
      | `document_domain
      | `encrypted_media
      | `execution_while_out_of_viewport
      | `execution_while_not_rendered
      | `focus_without_user_activation
      | `fullscreen
      | `frobulate
      | `gamepad
      | `geolocation
      | `gyroscope
      | `hid
      | `idle_detection
      | `interest_cohort
      | `join_ad_interest_group
      | `keyboard_map
      | `magnetometer
      | `microphone
      | `midi
      | `otp_credentials
      | `payment
      | `picture_in_picture
      | `publickey_credentials_get
      | `run_ad_auction
      | `screen_wake_lock
      | `serial
      | `shared_autofill
      | `storage_access_api
      | `sync_xhr
      | `trust_token_redemption
      | `usb
      | `vertical_scroll
      | `web_share
      | `window_placement
      | `xr_spatial_tracking
    ];
    let _permissionspolicyfeature_of_yojson =
      fun
      | `String("accelerometer") => `accelerometer
      | `String("ambient-light-sensor") => `ambient_light_sensor
      | `String("attribution-reporting") => `attribution_reporting
      | `String("autoplay") => `autoplay
      | `String("camera") => `camera
      | `String("ch-dpr") => `ch_dpr
      | `String("ch-device-memory") => `ch_device_memory
      | `String("ch-downlink") => `ch_downlink
      | `String("ch-ect") => `ch_ect
      | `String("ch-prefers-color-scheme") => `ch_prefers_color_scheme
      | `String("ch-rtt") => `ch_rtt
      | `String("ch-ua") => `ch_ua
      | `String("ch-ua-arch") => `ch_ua_arch
      | `String("ch-ua-bitness") => `ch_ua_bitness
      | `String("ch-ua-platform") => `ch_ua_platform
      | `String("ch-ua-model") => `ch_ua_model
      | `String("ch-ua-mobile") => `ch_ua_mobile
      | `String("ch-ua-full-version") => `ch_ua_full_version
      | `String("ch-ua-full-version-list") => `ch_ua_full_version_list
      | `String("ch-ua-platform-version") => `ch_ua_platform_version
      | `String("ch-ua-reduced") => `ch_ua_reduced
      | `String("ch-viewport-height") => `ch_viewport_height
      | `String("ch-viewport-width") => `ch_viewport_width
      | `String("ch-width") => `ch_width
      | `String("clipboard-read") => `clipboard_read
      | `String("clipboard-write") => `clipboard_write
      | `String("cross-origin-isolated") => `cross_origin_isolated
      | `String("direct-sockets") => `direct_sockets
      | `String("display-capture") => `display_capture
      | `String("document-domain") => `document_domain
      | `String("encrypted-media") => `encrypted_media
      | `String("execution-while-out-of-viewport") => `execution_while_out_of_viewport
      | `String("execution-while-not-rendered") => `execution_while_not_rendered
      | `String("focus-without-user-activation") => `focus_without_user_activation
      | `String("fullscreen") => `fullscreen
      | `String("frobulate") => `frobulate
      | `String("gamepad") => `gamepad
      | `String("geolocation") => `geolocation
      | `String("gyroscope") => `gyroscope
      | `String("hid") => `hid
      | `String("idle-detection") => `idle_detection
      | `String("interest-cohort") => `interest_cohort
      | `String("join-ad-interest-group") => `join_ad_interest_group
      | `String("keyboard-map") => `keyboard_map
      | `String("magnetometer") => `magnetometer
      | `String("microphone") => `microphone
      | `String("midi") => `midi
      | `String("otp-credentials") => `otp_credentials
      | `String("payment") => `payment
      | `String("picture-in-picture") => `picture_in_picture
      | `String("publickey-credentials-get") => `publickey_credentials_get
      | `String("run-ad-auction") => `run_ad_auction
      | `String("screen-wake-lock") => `screen_wake_lock
      | `String("serial") => `serial
      | `String("shared-autofill") => `shared_autofill
      | `String("storage-access-api") => `storage_access_api
      | `String("sync-xhr") => `sync_xhr
      | `String("trust-token-redemption") => `trust_token_redemption
      | `String("usb") => `usb
      | `String("vertical-scroll") => `vertical_scroll
      | `String("web-share") => `web_share
      | `String("window-placement") => `window_placement
      | `String("xr-spatial-tracking") => `xr_spatial_tracking
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__permissionspolicyfeature =
      fun
      | `accelerometer => `String("accelerometer")
      | `ambient_light_sensor => `String("ambient-light-sensor")
      | `attribution_reporting => `String("attribution-reporting")
      | `autoplay => `String("autoplay")
      | `camera => `String("camera")
      | `ch_dpr => `String("ch-dpr")
      | `ch_device_memory => `String("ch-device-memory")
      | `ch_downlink => `String("ch-downlink")
      | `ch_ect => `String("ch-ect")
      | `ch_prefers_color_scheme => `String("ch-prefers-color-scheme")
      | `ch_rtt => `String("ch-rtt")
      | `ch_ua => `String("ch-ua")
      | `ch_ua_arch => `String("ch-ua-arch")
      | `ch_ua_bitness => `String("ch-ua-bitness")
      | `ch_ua_platform => `String("ch-ua-platform")
      | `ch_ua_model => `String("ch-ua-model")
      | `ch_ua_mobile => `String("ch-ua-mobile")
      | `ch_ua_full_version => `String("ch-ua-full-version")
      | `ch_ua_full_version_list => `String("ch-ua-full-version-list")
      | `ch_ua_platform_version => `String("ch-ua-platform-version")
      | `ch_ua_reduced => `String("ch-ua-reduced")
      | `ch_viewport_height => `String("ch-viewport-height")
      | `ch_viewport_width => `String("ch-viewport-width")
      | `ch_width => `String("ch-width")
      | `clipboard_read => `String("clipboard-read")
      | `clipboard_write => `String("clipboard-write")
      | `cross_origin_isolated => `String("cross-origin-isolated")
      | `direct_sockets => `String("direct-sockets")
      | `display_capture => `String("display-capture")
      | `document_domain => `String("document-domain")
      | `encrypted_media => `String("encrypted-media")
      | `execution_while_out_of_viewport =>
        `String("execution-while-out-of-viewport")
      | `execution_while_not_rendered =>
        `String("execution-while-not-rendered")
      | `focus_without_user_activation =>
        `String("focus-without-user-activation")
      | `fullscreen => `String("fullscreen")
      | `frobulate => `String("frobulate")
      | `gamepad => `String("gamepad")
      | `geolocation => `String("geolocation")
      | `gyroscope => `String("gyroscope")
      | `hid => `String("hid")
      | `idle_detection => `String("idle-detection")
      | `interest_cohort => `String("interest-cohort")
      | `join_ad_interest_group => `String("join-ad-interest-group")
      | `keyboard_map => `String("keyboard-map")
      | `magnetometer => `String("magnetometer")
      | `microphone => `String("microphone")
      | `midi => `String("midi")
      | `otp_credentials => `String("otp-credentials")
      | `payment => `String("payment")
      | `picture_in_picture => `String("picture-in-picture")
      | `publickey_credentials_get => `String("publickey-credentials-get")
      | `run_ad_auction => `String("run-ad-auction")
      | `screen_wake_lock => `String("screen-wake-lock")
      | `serial => `String("serial")
      | `shared_autofill => `String("shared-autofill")
      | `storage_access_api => `String("storage-access-api")
      | `sync_xhr => `String("sync-xhr")
      | `trust_token_redemption => `String("trust-token-redemption")
      | `usb => `String("usb")
      | `vertical_scroll => `String("vertical-scroll")
      | `web_share => `String("web-share")
      | `window_placement => `String("window-placement")
      | `xr_spatial_tracking => `String("xr-spatial-tracking");
    /* All Permissions Policy features. This enum should match the one defined
       in third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5. */
    [@deriving yojson]
    type t = _permissionspolicyfeature;
  }
  and PermissionsPolicyBlockReason: {
    type _permissionspolicyblockreason = [ | `Header | `IframeAttribute];
    let _permissionspolicyblockreason_of_yojson:
      Yojson.Basic.t => _permissionspolicyblockreason;
    let yojson_of__permissionspolicyblockreason:
      _permissionspolicyblockreason => Yojson.Basic.t;
    /* Reason for a permissions policy feature to be disabled. */
    [@deriving yojson]
    type t = _permissionspolicyblockreason;
  } = {
    type _permissionspolicyblockreason = [ | `Header | `IframeAttribute];
    let _permissionspolicyblockreason_of_yojson =
      fun
      | `String("Header") => `Header
      | `String("IframeAttribute") => `IframeAttribute
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__permissionspolicyblockreason =
      fun
      | `Header => `String("Header")
      | `IframeAttribute => `String("IframeAttribute");
    /* Reason for a permissions policy feature to be disabled. */
    [@deriving yojson]
    type t = _permissionspolicyblockreason;
  }
  and PermissionsPolicyBlockLocator: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: FrameId.t, /* No description provided */
      [@key "blockReason"]
      blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: FrameId.t, /* No description provided */
      [@key "blockReason"]
      blockReason: PermissionsPolicyBlockReason.t /* No description provided */,
    };
  }
  and PermissionsPolicyFeatureState: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "feature"]
      feature: PermissionsPolicyFeature.t, /* No description provided */
      [@key "allowed"]
      allowed: bool, /* No description provided */
      [@yojson.option] [@key "locator"]
      locator: option(PermissionsPolicyBlockLocator.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "feature"]
      feature: PermissionsPolicyFeature.t, /* No description provided */
      [@key "allowed"]
      allowed: bool, /* No description provided */
      [@yojson.option] [@key "locator"]
      locator: option(PermissionsPolicyBlockLocator.t) /* No description provided */,
    };
  }
  and OriginTrialTokenStatus: {
    type _origintrialtokenstatus = [
      | `Success
      | `NotSupported
      | `Insecure
      | `Expired
      | `WrongOrigin
      | `InvalidSignature
      | `Malformed
      | `WrongVersion
      | `FeatureDisabled
      | `TokenDisabled
      | `FeatureDisabledForUser
      | `UnknownTrial
    ];
    let _origintrialtokenstatus_of_yojson:
      Yojson.Basic.t => _origintrialtokenstatus;
    let yojson_of__origintrialtokenstatus:
      _origintrialtokenstatus => Yojson.Basic.t;
    /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
       Status for an Origin Trial token. */
    [@deriving yojson]
    type t = _origintrialtokenstatus;
  } = {
    type _origintrialtokenstatus = [
      | `Success
      | `NotSupported
      | `Insecure
      | `Expired
      | `WrongOrigin
      | `InvalidSignature
      | `Malformed
      | `WrongVersion
      | `FeatureDisabled
      | `TokenDisabled
      | `FeatureDisabledForUser
      | `UnknownTrial
    ];
    let _origintrialtokenstatus_of_yojson =
      fun
      | `String("Success") => `Success
      | `String("NotSupported") => `NotSupported
      | `String("Insecure") => `Insecure
      | `String("Expired") => `Expired
      | `String("WrongOrigin") => `WrongOrigin
      | `String("InvalidSignature") => `InvalidSignature
      | `String("Malformed") => `Malformed
      | `String("WrongVersion") => `WrongVersion
      | `String("FeatureDisabled") => `FeatureDisabled
      | `String("TokenDisabled") => `TokenDisabled
      | `String("FeatureDisabledForUser") => `FeatureDisabledForUser
      | `String("UnknownTrial") => `UnknownTrial
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__origintrialtokenstatus =
      fun
      | `Success => `String("Success")
      | `NotSupported => `String("NotSupported")
      | `Insecure => `String("Insecure")
      | `Expired => `String("Expired")
      | `WrongOrigin => `String("WrongOrigin")
      | `InvalidSignature => `String("InvalidSignature")
      | `Malformed => `String("Malformed")
      | `WrongVersion => `String("WrongVersion")
      | `FeatureDisabled => `String("FeatureDisabled")
      | `TokenDisabled => `String("TokenDisabled")
      | `FeatureDisabledForUser => `String("FeatureDisabledForUser")
      | `UnknownTrial => `String("UnknownTrial");
    /* Origin Trial(https://www.chromium.org/blink/origin-trials) support.
       Status for an Origin Trial token. */
    [@deriving yojson]
    type t = _origintrialtokenstatus;
  }
  and OriginTrialStatus: {
    type _origintrialstatus = [
      | `Enabled
      | `ValidTokenNotProvided
      | `OSNotSupported
      | `TrialNotAllowed
    ];
    let _origintrialstatus_of_yojson: Yojson.Basic.t => _origintrialstatus;
    let yojson_of__origintrialstatus: _origintrialstatus => Yojson.Basic.t;
    /* Status for an Origin Trial. */
    [@deriving yojson]
    type t = _origintrialstatus;
  } = {
    type _origintrialstatus = [
      | `Enabled
      | `ValidTokenNotProvided
      | `OSNotSupported
      | `TrialNotAllowed
    ];
    let _origintrialstatus_of_yojson =
      fun
      | `String("Enabled") => `Enabled
      | `String("ValidTokenNotProvided") => `ValidTokenNotProvided
      | `String("OSNotSupported") => `OSNotSupported
      | `String("TrialNotAllowed") => `TrialNotAllowed
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__origintrialstatus =
      fun
      | `Enabled => `String("Enabled")
      | `ValidTokenNotProvided => `String("ValidTokenNotProvided")
      | `OSNotSupported => `String("OSNotSupported")
      | `TrialNotAllowed => `String("TrialNotAllowed");
    /* Status for an Origin Trial. */
    [@deriving yojson]
    type t = _origintrialstatus;
  }
  and OriginTrialUsageRestriction: {
    type _origintrialusagerestriction = [ | `None | `Subset];
    let _origintrialusagerestriction_of_yojson:
      Yojson.Basic.t => _origintrialusagerestriction;
    let yojson_of__origintrialusagerestriction:
      _origintrialusagerestriction => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _origintrialusagerestriction;
  } = {
    type _origintrialusagerestriction = [ | `None | `Subset];
    let _origintrialusagerestriction_of_yojson =
      fun
      | `String("None") => `None
      | `String("Subset") => `Subset
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__origintrialusagerestriction =
      fun
      | `None => `String("None")
      | `Subset => `String("Subset");
    /* No description provided */
    [@deriving yojson]
    type t = _origintrialusagerestriction;
  }
  and OriginTrialToken: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "origin"]
      origin: string, /* No description provided */
      [@key "matchSubDomains"]
      matchSubDomains: bool, /* No description provided */
      [@key "trialName"]
      trialName: string, /* No description provided */
      [@key "expiryTime"]
      expiryTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "isThirdParty"]
      isThirdParty: bool, /* No description provided */
      [@key "usageRestriction"]
      usageRestriction: OriginTrialUsageRestriction.t /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "origin"]
      origin: string, /* No description provided */
      [@key "matchSubDomains"]
      matchSubDomains: bool, /* No description provided */
      [@key "trialName"]
      trialName: string, /* No description provided */
      [@key "expiryTime"]
      expiryTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "isThirdParty"]
      isThirdParty: bool, /* No description provided */
      [@key "usageRestriction"]
      usageRestriction: OriginTrialUsageRestriction.t /* No description provided */,
    };
  }
  and OriginTrialTokenWithStatus: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "rawTokenText"]
      rawTokenText: string, /* No description provided */
      [@yojson.option] [@key "parsedToken"]
      parsedToken: option(OriginTrialToken.t), /* `parsedToken` is present only when the token is extractable and
parsable. */
      [@key "status"]
      status: OriginTrialTokenStatus.t /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "rawTokenText"]
      rawTokenText: string, /* No description provided */
      [@yojson.option] [@key "parsedToken"]
      parsedToken: option(OriginTrialToken.t), /* `parsedToken` is present only when the token is extractable and
parsable. */
      [@key "status"]
      status: OriginTrialTokenStatus.t /* No description provided */,
    };
  }
  and OriginTrial: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "trialName"]
      trialName: string, /* No description provided */
      [@key "status"]
      status: OriginTrialStatus.t, /* No description provided */
      [@key "tokensWithStatus"]
      tokensWithStatus: list(OriginTrialTokenWithStatus.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "trialName"]
      trialName: string, /* No description provided */
      [@key "status"]
      status: OriginTrialStatus.t, /* No description provided */
      [@key "tokensWithStatus"]
      tokensWithStatus: list(OriginTrialTokenWithStatus.t) /* No description provided */,
    };
  }
  and Frame: {
    /* Information about the Frame on the page. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: FrameId.t, /* Frame unique identifier. */
      [@yojson.option] [@key "parentId"]
      parentId: option(FrameId.t), /* Parent frame identifier. */
      [@key "loaderId"]
      loaderId: Network.LoaderId.t, /* Identifier of the loader associated with this frame. */
      [@yojson.option] [@key "name"]
      name: option(string), /* Frame's name as specified in the tag. */
      [@key "url"]
      url: string, /* Frame document's URL without fragment. */
      [@yojson.option] [@key "urlFragment"]
      urlFragment: option(string), /* Frame document's URL fragment including the '#'. */
      [@key "domainAndRegistry"]
      domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
      [@key "securityOrigin"]
      securityOrigin: string, /* Frame document's security origin. */
      [@key "mimeType"]
      mimeType: string, /* Frame document's mimeType as determined by the browser. */
      [@yojson.option] [@key "unreachableUrl"]
      unreachableUrl: option(string), /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
      [@yojson.option] [@key "adFrameStatus"]
      adFrameStatus: option(AdFrameStatus.t), /* Indicates whether this frame was tagged as an ad and why. */
      [@key "secureContextType"]
      secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
      [@key "crossOriginIsolatedContextType"]
      crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
      [@key "gatedAPIFeatures"]
      gatedAPIFeatures: list(GatedAPIFeatures.t) /* Indicated which gated APIs / features are available. */,
    };
  } = {
    /* Information about the Frame on the page. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: FrameId.t, /* Frame unique identifier. */
      [@yojson.option] [@key "parentId"]
      parentId: option(FrameId.t), /* Parent frame identifier. */
      [@key "loaderId"]
      loaderId: Network.LoaderId.t, /* Identifier of the loader associated with this frame. */
      [@yojson.option] [@key "name"]
      name: option(string), /* Frame's name as specified in the tag. */
      [@key "url"]
      url: string, /* Frame document's URL without fragment. */
      [@yojson.option] [@key "urlFragment"]
      urlFragment: option(string), /* Frame document's URL fragment including the '#'. */
      [@key "domainAndRegistry"]
      domainAndRegistry: string, /* Frame document's registered domain, taking the public suffixes list into account.
Extracted from the Frame's url.
Example URLs: http://www.google.com/file.html -> "google.com"
              http://a.b.co.uk/file.html      -> "b.co.uk" */
      [@key "securityOrigin"]
      securityOrigin: string, /* Frame document's security origin. */
      [@key "mimeType"]
      mimeType: string, /* Frame document's mimeType as determined by the browser. */
      [@yojson.option] [@key "unreachableUrl"]
      unreachableUrl: option(string), /* If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment. */
      [@yojson.option] [@key "adFrameStatus"]
      adFrameStatus: option(AdFrameStatus.t), /* Indicates whether this frame was tagged as an ad and why. */
      [@key "secureContextType"]
      secureContextType: SecureContextType.t, /* Indicates whether the main document is a secure context and explains why that is the case. */
      [@key "crossOriginIsolatedContextType"]
      crossOriginIsolatedContextType: CrossOriginIsolatedContextType.t, /* Indicates whether this is a cross origin isolated context. */
      [@key "gatedAPIFeatures"]
      gatedAPIFeatures: list(GatedAPIFeatures.t) /* Indicated which gated APIs / features are available. */,
    };
  }
  and FrameResource: {
    /* Information about the Resource on the page. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Resource URL. */
      [@key "type"]
      type_: Network.ResourceType.t, /* Type of this resource. */
      [@key "mimeType"]
      mimeType: string, /* Resource mimeType as determined by the browser. */
      [@yojson.option] [@key "lastModified"]
      lastModified: option(Network.TimeSinceEpoch.t), /* last-modified timestamp as reported by server. */
      [@yojson.option] [@key "contentSize"]
      contentSize: option(float), /* Resource content size. */
      [@yojson.option] [@key "failed"]
      failed: option(bool), /* True if the resource failed to load. */
      [@yojson.option] [@key "canceled"]
      canceled: option(bool) /* True if the resource was canceled during loading. */,
    };
  } = {
    /* Information about the Resource on the page. */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* Resource URL. */
      [@key "type"]
      type_: Network.ResourceType.t, /* Type of this resource. */
      [@key "mimeType"]
      mimeType: string, /* Resource mimeType as determined by the browser. */
      [@yojson.option] [@key "lastModified"]
      lastModified: option(Network.TimeSinceEpoch.t), /* last-modified timestamp as reported by server. */
      [@yojson.option] [@key "contentSize"]
      contentSize: option(float), /* Resource content size. */
      [@yojson.option] [@key "failed"]
      failed: option(bool), /* True if the resource failed to load. */
      [@yojson.option] [@key "canceled"]
      canceled: option(bool) /* True if the resource was canceled during loading. */,
    };
  }
  and FrameResourceTree: {
    /* Information about the Frame hierarchy along with their cached resources. */
    [@deriving yojson]
    type t = {
      [@key "frame"]
      frame: Frame.t, /* Frame information for this tree item. */
      [@yojson.option] [@key "childFrames"]
      childFrames: option(list(FrameResourceTree.t)), /* Child frames. */
      [@key "resources"]
      resources: list(FrameResource.t) /* Information about frame resources. */,
    };
  } = {
    /* Information about the Frame hierarchy along with their cached resources. */
    [@deriving yojson]
    type t = {
      [@key "frame"]
      frame: Frame.t, /* Frame information for this tree item. */
      [@yojson.option] [@key "childFrames"]
      childFrames: option(list(FrameResourceTree.t)), /* Child frames. */
      [@key "resources"]
      resources: list(FrameResource.t) /* Information about frame resources. */,
    };
  }
  and FrameTree: {
    /* Information about the Frame hierarchy. */
    [@deriving yojson]
    type t = {
      [@key "frame"]
      frame: Frame.t, /* Frame information for this tree item. */
      [@yojson.option] [@key "childFrames"]
      childFrames: option(list(FrameTree.t)) /* Child frames. */,
    };
  } = {
    /* Information about the Frame hierarchy. */
    [@deriving yojson]
    type t = {
      [@key "frame"]
      frame: Frame.t, /* Frame information for this tree item. */
      [@yojson.option] [@key "childFrames"]
      childFrames: option(list(FrameTree.t)) /* Child frames. */,
    };
  }
  and ScriptIdentifier: {
    /* Unique script identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique script identifier. */
    [@deriving yojson]
    type t = string;
  }
  and TransitionType: {
    type _transitiontype = [
      | `link
      | `typed
      | `address_bar
      | `auto_bookmark
      | `auto_subframe
      | `manual_subframe
      | `generated
      | `auto_toplevel
      | `form_submit
      | `reload
      | `keyword
      | `keyword_generated
      | `other
    ];
    let _transitiontype_of_yojson: Yojson.Basic.t => _transitiontype;
    let yojson_of__transitiontype: _transitiontype => Yojson.Basic.t;
    /* Transition type. */
    [@deriving yojson]
    type t = _transitiontype;
  } = {
    type _transitiontype = [
      | `link
      | `typed
      | `address_bar
      | `auto_bookmark
      | `auto_subframe
      | `manual_subframe
      | `generated
      | `auto_toplevel
      | `form_submit
      | `reload
      | `keyword
      | `keyword_generated
      | `other
    ];
    let _transitiontype_of_yojson =
      fun
      | `String("link") => `link
      | `String("typed") => `typed
      | `String("address_bar") => `address_bar
      | `String("auto_bookmark") => `auto_bookmark
      | `String("auto_subframe") => `auto_subframe
      | `String("manual_subframe") => `manual_subframe
      | `String("generated") => `generated
      | `String("auto_toplevel") => `auto_toplevel
      | `String("form_submit") => `form_submit
      | `String("reload") => `reload
      | `String("keyword") => `keyword
      | `String("keyword_generated") => `keyword_generated
      | `String("other") => `other
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__transitiontype =
      fun
      | `link => `String("link")
      | `typed => `String("typed")
      | `address_bar => `String("address_bar")
      | `auto_bookmark => `String("auto_bookmark")
      | `auto_subframe => `String("auto_subframe")
      | `manual_subframe => `String("manual_subframe")
      | `generated => `String("generated")
      | `auto_toplevel => `String("auto_toplevel")
      | `form_submit => `String("form_submit")
      | `reload => `String("reload")
      | `keyword => `String("keyword")
      | `keyword_generated => `String("keyword_generated")
      | `other => `String("other");
    /* Transition type. */
    [@deriving yojson]
    type t = _transitiontype;
  }
  and NavigationEntry: {
    /* Navigation history entry. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: float, /* Unique id of the navigation history entry. */
      [@key "url"]
      url: string, /* URL of the navigation history entry. */
      [@key "userTypedURL"]
      userTypedURL: string, /* URL that the user typed in the url bar. */
      [@key "title"]
      title: string, /* Title of the navigation history entry. */
      [@key "transitionType"]
      transitionType: TransitionType.t /* Transition type. */,
    };
  } = {
    /* Navigation history entry. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: float, /* Unique id of the navigation history entry. */
      [@key "url"]
      url: string, /* URL of the navigation history entry. */
      [@key "userTypedURL"]
      userTypedURL: string, /* URL that the user typed in the url bar. */
      [@key "title"]
      title: string, /* Title of the navigation history entry. */
      [@key "transitionType"]
      transitionType: TransitionType.t /* Transition type. */,
    };
  }
  and ScreencastFrameMetadata: {
    /* Screencast frame metadata. */
    [@deriving yojson]
    type t = {
      [@key "offsetTop"]
      offsetTop: float, /* Top offset in DIP. */
      [@key "pageScaleFactor"]
      pageScaleFactor: float, /* Page scale factor. */
      [@key "deviceWidth"]
      deviceWidth: float, /* Device screen width in DIP. */
      [@key "deviceHeight"]
      deviceHeight: float, /* Device screen height in DIP. */
      [@key "scrollOffsetX"]
      scrollOffsetX: float, /* Position of horizontal scroll in CSS pixels. */
      [@key "scrollOffsetY"]
      scrollOffsetY: float, /* Position of vertical scroll in CSS pixels. */
      [@yojson.option] [@key "timestamp"]
      timestamp: option(Network.TimeSinceEpoch.t) /* Frame swap timestamp. */,
    };
  } = {
    /* Screencast frame metadata. */
    [@deriving yojson]
    type t = {
      [@key "offsetTop"]
      offsetTop: float, /* Top offset in DIP. */
      [@key "pageScaleFactor"]
      pageScaleFactor: float, /* Page scale factor. */
      [@key "deviceWidth"]
      deviceWidth: float, /* Device screen width in DIP. */
      [@key "deviceHeight"]
      deviceHeight: float, /* Device screen height in DIP. */
      [@key "scrollOffsetX"]
      scrollOffsetX: float, /* Position of horizontal scroll in CSS pixels. */
      [@key "scrollOffsetY"]
      scrollOffsetY: float, /* Position of vertical scroll in CSS pixels. */
      [@yojson.option] [@key "timestamp"]
      timestamp: option(Network.TimeSinceEpoch.t) /* Frame swap timestamp. */,
    };
  }
  and DialogType: {
    type _dialogtype = [ | `alert | `confirm | `prompt | `beforeunload];
    let _dialogtype_of_yojson: Yojson.Basic.t => _dialogtype;
    let yojson_of__dialogtype: _dialogtype => Yojson.Basic.t;
    /* Javascript dialog type. */
    [@deriving yojson]
    type t = _dialogtype;
  } = {
    type _dialogtype = [ | `alert | `confirm | `prompt | `beforeunload];
    let _dialogtype_of_yojson =
      fun
      | `String("alert") => `alert
      | `String("confirm") => `confirm
      | `String("prompt") => `prompt
      | `String("beforeunload") => `beforeunload
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__dialogtype =
      fun
      | `alert => `String("alert")
      | `confirm => `String("confirm")
      | `prompt => `String("prompt")
      | `beforeunload => `String("beforeunload");
    /* Javascript dialog type. */
    [@deriving yojson]
    type t = _dialogtype;
  }
  and AppManifestError: {
    /* Error while paring app manifest. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@key "critical"]
      critical: float, /* If criticial, this is a non-recoverable parse error. */
      [@key "line"]
      line: float, /* Error line. */
      [@key "column"]
      column: float /* Error column. */,
    };
  } = {
    /* Error while paring app manifest. */
    [@deriving yojson]
    type t = {
      [@key "message"]
      message: string, /* Error message. */
      [@key "critical"]
      critical: float, /* If criticial, this is a non-recoverable parse error. */
      [@key "line"]
      line: float, /* Error line. */
      [@key "column"]
      column: float /* Error column. */,
    };
  }
  and AppManifestParsedProperties: {
    /* Parsed app manifest properties. */
    [@deriving yojson]
    type t = {
      [@key "scope"]
      scope: string /* Computed scope value */,
    };
  } = {
    /* Parsed app manifest properties. */
    [@deriving yojson]
    type t = {
      [@key "scope"]
      scope: string /* Computed scope value */,
    };
  }
  and LayoutViewport: {
    /* Layout viewport position and dimensions. */
    [@deriving yojson]
    type t = {
      [@key "pageX"]
      pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
      [@key "pageY"]
      pageY: float, /* Vertical offset relative to the document (CSS pixels). */
      [@key "clientWidth"]
      clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
      [@key "clientHeight"]
      clientHeight: float /* Height (CSS pixels), excludes scrollbar if present. */,
    };
  } = {
    /* Layout viewport position and dimensions. */
    [@deriving yojson]
    type t = {
      [@key "pageX"]
      pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
      [@key "pageY"]
      pageY: float, /* Vertical offset relative to the document (CSS pixels). */
      [@key "clientWidth"]
      clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
      [@key "clientHeight"]
      clientHeight: float /* Height (CSS pixels), excludes scrollbar if present. */,
    };
  }
  and VisualViewport: {
    /* Visual viewport position, dimensions, and scale. */
    [@deriving yojson]
    type t = {
      [@key "offsetX"]
      offsetX: float, /* Horizontal offset relative to the layout viewport (CSS pixels). */
      [@key "offsetY"]
      offsetY: float, /* Vertical offset relative to the layout viewport (CSS pixels). */
      [@key "pageX"]
      pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
      [@key "pageY"]
      pageY: float, /* Vertical offset relative to the document (CSS pixels). */
      [@key "clientWidth"]
      clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
      [@key "clientHeight"]
      clientHeight: float, /* Height (CSS pixels), excludes scrollbar if present. */
      [@key "scale"]
      scale: float, /* Scale relative to the ideal viewport (size at width=device-width). */
      [@yojson.option] [@key "zoom"]
      zoom: option(float) /* Page zoom factor (CSS to device independent pixels ratio). */,
    };
  } = {
    /* Visual viewport position, dimensions, and scale. */
    [@deriving yojson]
    type t = {
      [@key "offsetX"]
      offsetX: float, /* Horizontal offset relative to the layout viewport (CSS pixels). */
      [@key "offsetY"]
      offsetY: float, /* Vertical offset relative to the layout viewport (CSS pixels). */
      [@key "pageX"]
      pageX: float, /* Horizontal offset relative to the document (CSS pixels). */
      [@key "pageY"]
      pageY: float, /* Vertical offset relative to the document (CSS pixels). */
      [@key "clientWidth"]
      clientWidth: float, /* Width (CSS pixels), excludes scrollbar if present. */
      [@key "clientHeight"]
      clientHeight: float, /* Height (CSS pixels), excludes scrollbar if present. */
      [@key "scale"]
      scale: float, /* Scale relative to the ideal viewport (size at width=device-width). */
      [@yojson.option] [@key "zoom"]
      zoom: option(float) /* Page zoom factor (CSS to device independent pixels ratio). */,
    };
  }
  and Viewport: {
    /* Viewport for capturing screenshot. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X offset in device independent pixels (dip). */
      [@key "y"]
      y: float, /* Y offset in device independent pixels (dip). */
      [@key "width"]
      width: float, /* Rectangle width in device independent pixels (dip). */
      [@key "height"]
      height: float, /* Rectangle height in device independent pixels (dip). */
      [@key "scale"]
      scale: float /* Page scale factor. */,
    };
  } = {
    /* Viewport for capturing screenshot. */
    [@deriving yojson]
    type t = {
      [@key "x"]
      x: float, /* X offset in device independent pixels (dip). */
      [@key "y"]
      y: float, /* Y offset in device independent pixels (dip). */
      [@key "width"]
      width: float, /* Rectangle width in device independent pixels (dip). */
      [@key "height"]
      height: float, /* Rectangle height in device independent pixels (dip). */
      [@key "scale"]
      scale: float /* Page scale factor. */,
    };
  }
  and FontFamilies: {
    /* Generic font families collection. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "standard"]
      standard: option(string), /* The standard font-family. */
      [@yojson.option] [@key "fixed"]
      fixed: option(string), /* The fixed font-family. */
      [@yojson.option] [@key "serif"]
      serif: option(string), /* The serif font-family. */
      [@yojson.option] [@key "sansSerif"]
      sansSerif: option(string), /* The sansSerif font-family. */
      [@yojson.option] [@key "cursive"]
      cursive: option(string), /* The cursive font-family. */
      [@yojson.option] [@key "fantasy"]
      fantasy: option(string), /* The fantasy font-family. */
      [@yojson.option] [@key "pictograph"]
      pictograph: option(string) /* The pictograph font-family. */,
    };
  } = {
    /* Generic font families collection. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "standard"]
      standard: option(string), /* The standard font-family. */
      [@yojson.option] [@key "fixed"]
      fixed: option(string), /* The fixed font-family. */
      [@yojson.option] [@key "serif"]
      serif: option(string), /* The serif font-family. */
      [@yojson.option] [@key "sansSerif"]
      sansSerif: option(string), /* The sansSerif font-family. */
      [@yojson.option] [@key "cursive"]
      cursive: option(string), /* The cursive font-family. */
      [@yojson.option] [@key "fantasy"]
      fantasy: option(string), /* The fantasy font-family. */
      [@yojson.option] [@key "pictograph"]
      pictograph: option(string) /* The pictograph font-family. */,
    };
  }
  and FontSizes: {
    /* Default font sizes. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "standard"]
      standard: option(float), /* Default standard font size. */
      [@yojson.option] [@key "fixed"]
      fixed: option(float) /* Default fixed font size. */,
    };
  } = {
    /* Default font sizes. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "standard"]
      standard: option(float), /* Default standard font size. */
      [@yojson.option] [@key "fixed"]
      fixed: option(float) /* Default fixed font size. */,
    };
  }
  and ClientNavigationReason: {
    type _clientnavigationreason = [
      | `formSubmissionGet
      | `formSubmissionPost
      | `httpHeaderRefresh
      | `scriptInitiated
      | `metaTagRefresh
      | `pageBlockInterstitial
      | `reload
      | `anchorClick
    ];
    let _clientnavigationreason_of_yojson:
      Yojson.Basic.t => _clientnavigationreason;
    let yojson_of__clientnavigationreason:
      _clientnavigationreason => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _clientnavigationreason;
  } = {
    type _clientnavigationreason = [
      | `formSubmissionGet
      | `formSubmissionPost
      | `httpHeaderRefresh
      | `scriptInitiated
      | `metaTagRefresh
      | `pageBlockInterstitial
      | `reload
      | `anchorClick
    ];
    let _clientnavigationreason_of_yojson =
      fun
      | `String("formSubmissionGet") => `formSubmissionGet
      | `String("formSubmissionPost") => `formSubmissionPost
      | `String("httpHeaderRefresh") => `httpHeaderRefresh
      | `String("scriptInitiated") => `scriptInitiated
      | `String("metaTagRefresh") => `metaTagRefresh
      | `String("pageBlockInterstitial") => `pageBlockInterstitial
      | `String("reload") => `reload
      | `String("anchorClick") => `anchorClick
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__clientnavigationreason =
      fun
      | `formSubmissionGet => `String("formSubmissionGet")
      | `formSubmissionPost => `String("formSubmissionPost")
      | `httpHeaderRefresh => `String("httpHeaderRefresh")
      | `scriptInitiated => `String("scriptInitiated")
      | `metaTagRefresh => `String("metaTagRefresh")
      | `pageBlockInterstitial => `String("pageBlockInterstitial")
      | `reload => `String("reload")
      | `anchorClick => `String("anchorClick");
    /* No description provided */
    [@deriving yojson]
    type t = _clientnavigationreason;
  }
  and ClientNavigationDisposition: {
    type _clientnavigationdisposition = [
      | `currentTab
      | `newTab
      | `newWindow
      | `download
    ];
    let _clientnavigationdisposition_of_yojson:
      Yojson.Basic.t => _clientnavigationdisposition;
    let yojson_of__clientnavigationdisposition:
      _clientnavigationdisposition => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _clientnavigationdisposition;
  } = {
    type _clientnavigationdisposition = [
      | `currentTab
      | `newTab
      | `newWindow
      | `download
    ];
    let _clientnavigationdisposition_of_yojson =
      fun
      | `String("currentTab") => `currentTab
      | `String("newTab") => `newTab
      | `String("newWindow") => `newWindow
      | `String("download") => `download
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__clientnavigationdisposition =
      fun
      | `currentTab => `String("currentTab")
      | `newTab => `String("newTab")
      | `newWindow => `String("newWindow")
      | `download => `String("download");
    /* No description provided */
    [@deriving yojson]
    type t = _clientnavigationdisposition;
  }
  and InstallabilityErrorArgument: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
      [@key "value"]
      value: string /* Argument value (e.g. value:'64'). */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Argument name (e.g. name:'minimum-icon-size-in-pixels'). */
      [@key "value"]
      value: string /* Argument value (e.g. value:'64'). */,
    };
  }
  and InstallabilityError: {
    /* The installability error */
    [@deriving yojson]
    type t = {
      [@key "errorId"]
      errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
      [@key "errorArguments"]
      errorArguments: list(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
    };
  } = {
    /* The installability error */
    [@deriving yojson]
    type t = {
      [@key "errorId"]
      errorId: string, /* The error id (e.g. 'manifest-missing-suitable-icon'). */
      [@key "errorArguments"]
      errorArguments: list(InstallabilityErrorArgument.t) /* The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}). */,
    };
  }
  and ReferrerPolicy: {
    type _referrerpolicy = [
      | `noReferrer
      | `noReferrerWhenDowngrade
      | `origin
      | `originWhenCrossOrigin
      | `sameOrigin
      | `strictOrigin
      | `strictOriginWhenCrossOrigin
      | `unsafeUrl
    ];
    let _referrerpolicy_of_yojson: Yojson.Basic.t => _referrerpolicy;
    let yojson_of__referrerpolicy: _referrerpolicy => Yojson.Basic.t;
    /* The referring-policy used for the navigation. */
    [@deriving yojson]
    type t = _referrerpolicy;
  } = {
    type _referrerpolicy = [
      | `noReferrer
      | `noReferrerWhenDowngrade
      | `origin
      | `originWhenCrossOrigin
      | `sameOrigin
      | `strictOrigin
      | `strictOriginWhenCrossOrigin
      | `unsafeUrl
    ];
    let _referrerpolicy_of_yojson =
      fun
      | `String("noReferrer") => `noReferrer
      | `String("noReferrerWhenDowngrade") => `noReferrerWhenDowngrade
      | `String("origin") => `origin
      | `String("originWhenCrossOrigin") => `originWhenCrossOrigin
      | `String("sameOrigin") => `sameOrigin
      | `String("strictOrigin") => `strictOrigin
      | `String("strictOriginWhenCrossOrigin") => `strictOriginWhenCrossOrigin
      | `String("unsafeUrl") => `unsafeUrl
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__referrerpolicy =
      fun
      | `noReferrer => `String("noReferrer")
      | `noReferrerWhenDowngrade => `String("noReferrerWhenDowngrade")
      | `origin => `String("origin")
      | `originWhenCrossOrigin => `String("originWhenCrossOrigin")
      | `sameOrigin => `String("sameOrigin")
      | `strictOrigin => `String("strictOrigin")
      | `strictOriginWhenCrossOrigin => `String("strictOriginWhenCrossOrigin")
      | `unsafeUrl => `String("unsafeUrl");
    /* The referring-policy used for the navigation. */
    [@deriving yojson]
    type t = _referrerpolicy;
  }
  and CompilationCacheParams: {
    /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The URL of the script to produce a compilation cache entry for. */
      [@yojson.option] [@key "eager"]
      eager: option(bool) /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
    };
  } = {
    /* Per-script compilation cache parameters for `Page.produceCompilationCache` */
    [@deriving yojson]
    type t = {
      [@key "url"]
      url: string, /* The URL of the script to produce a compilation cache entry for. */
      [@yojson.option] [@key "eager"]
      eager: option(bool) /* A hint to the backend whether eager compilation is recommended.
(the actual compilation mode used is upon backend discretion). */,
    };
  }
  and NavigationType: {
    type _navigationtype = [ | `Navigation | `BackForwardCacheRestore];
    let _navigationtype_of_yojson: Yojson.Basic.t => _navigationtype;
    let yojson_of__navigationtype: _navigationtype => Yojson.Basic.t;
    /* The type of a frameNavigated event. */
    [@deriving yojson]
    type t = _navigationtype;
  } = {
    type _navigationtype = [ | `Navigation | `BackForwardCacheRestore];
    let _navigationtype_of_yojson =
      fun
      | `String("Navigation") => `Navigation
      | `String("BackForwardCacheRestore") => `BackForwardCacheRestore
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__navigationtype =
      fun
      | `Navigation => `String("Navigation")
      | `BackForwardCacheRestore => `String("BackForwardCacheRestore");
    /* The type of a frameNavigated event. */
    [@deriving yojson]
    type t = _navigationtype;
  }
  and BackForwardCacheNotRestoredReason: {
    type _backforwardcachenotrestoredreason = [
      | `NotMainFrame
      | `BackForwardCacheDisabled
      | `RelatedActiveContentsExist
      | `HTTPStatusNotOK
      | `SchemeNotHTTPOrHTTPS
      | `Loading
      | `WasGrantedMediaAccess
      | `DisableForRenderFrameHostCalled
      | `DomainNotAllowed
      | `HTTPMethodNotGET
      | `SubframeIsNavigating
      | `Timeout
      | `CacheLimit
      | `JavaScriptExecution
      | `RendererProcessKilled
      | `RendererProcessCrashed
      | `GrantedMediaStreamAccess
      | `SchedulerTrackedFeatureUsed
      | `ConflictingBrowsingInstance
      | `CacheFlushed
      | `ServiceWorkerVersionActivation
      | `SessionRestored
      | `ServiceWorkerPostMessage
      | `EnteredBackForwardCacheBeforeServiceWorkerHostAdded
      | `RenderFrameHostReused_SameSite
      | `RenderFrameHostReused_CrossSite
      | `ServiceWorkerClaim
      | `IgnoreEventAndEvict
      | `HaveInnerContents
      | `TimeoutPuttingInCache
      | `BackForwardCacheDisabledByLowMemory
      | `BackForwardCacheDisabledByCommandLine
      | `NetworkRequestDatapipeDrainedAsBytesConsumer
      | `NetworkRequestRedirected
      | `NetworkRequestTimeout
      | `NetworkExceedsBufferLimit
      | `NavigationCancelledWhileRestoring
      | `NotMostRecentNavigationEntry
      | `BackForwardCacheDisabledForPrerender
      | `UserAgentOverrideDiffers
      | `ForegroundCacheLimit
      | `BrowsingInstanceNotSwapped
      | `BackForwardCacheDisabledForDelegate
      | `OptInUnloadHeaderNotPresent
      | `UnloadHandlerExistsInMainFrame
      | `UnloadHandlerExistsInSubFrame
      | `ServiceWorkerUnregistration
      | `CacheControlNoStore
      | `CacheControlNoStoreCookieModified
      | `CacheControlNoStoreHTTPOnlyCookieModified
      | `NoResponseHead
      | `Unknown
      | `ActivationNavigationsDisallowedForBug1234857
      | `WebSocket
      | `WebTransport
      | `WebRTC
      | `MainResourceHasCacheControlNoStore
      | `MainResourceHasCacheControlNoCache
      | `SubresourceHasCacheControlNoStore
      | `SubresourceHasCacheControlNoCache
      | `ContainsPlugins
      | `DocumentLoaded
      | `DedicatedWorkerOrWorklet
      | `OutstandingNetworkRequestOthers
      | `OutstandingIndexedDBTransaction
      | `RequestedNotificationsPermission
      | `RequestedMIDIPermission
      | `RequestedAudioCapturePermission
      | `RequestedVideoCapturePermission
      | `RequestedBackForwardCacheBlockedSensors
      | `RequestedBackgroundWorkPermission
      | `BroadcastChannel
      | `IndexedDBConnection
      | `WebXR
      | `SharedWorker
      | `WebLocks
      | `WebHID
      | `WebShare
      | `RequestedStorageAccessGrant
      | `WebNfc
      | `OutstandingNetworkRequestFetch
      | `OutstandingNetworkRequestXHR
      | `AppBanner
      | `Printing
      | `WebDatabase
      | `PictureInPicture
      | `Portal
      | `SpeechRecognizer
      | `IdleManager
      | `PaymentManager
      | `SpeechSynthesis
      | `KeyboardLock
      | `WebOTPService
      | `OutstandingNetworkRequestDirectSocket
      | `InjectedJavascript
      | `InjectedStyleSheet
      | `Dummy
      | `ContentSecurityHandler
      | `ContentWebAuthenticationAPI
      | `ContentFileChooser
      | `ContentSerial
      | `ContentFileSystemAccess
      | `ContentMediaDevicesDispatcherHost
      | `ContentWebBluetooth
      | `ContentWebUSB
      | `ContentMediaSession
      | `ContentMediaSessionService
      | `EmbedderPopupBlockerTabHelper
      | `EmbedderSafeBrowsingTriggeredPopupBlocker
      | `EmbedderSafeBrowsingThreatDetails
      | `EmbedderAppBannerManager
      | `EmbedderDomDistillerViewerSource
      | `EmbedderDomDistillerSelfDeletingRequestDelegate
      | `EmbedderOomInterventionTabHelper
      | `EmbedderOfflinePage
      | `EmbedderChromePasswordManagerClientBindCredentialManager
      | `EmbedderPermissionRequestManager
      | `EmbedderModalDialog
      | `EmbedderExtensions
      | `EmbedderExtensionMessaging
      | `EmbedderExtensionMessagingForOpenPort
      | `EmbedderExtensionSentMessageToCachedFrame
    ];
    let _backforwardcachenotrestoredreason_of_yojson:
      Yojson.Basic.t => _backforwardcachenotrestoredreason;
    let yojson_of__backforwardcachenotrestoredreason:
      _backforwardcachenotrestoredreason => Yojson.Basic.t;
    /* List of not restored reasons for back-forward cache. */
    [@deriving yojson]
    type t = _backforwardcachenotrestoredreason;
  } = {
    type _backforwardcachenotrestoredreason = [
      | `NotMainFrame
      | `BackForwardCacheDisabled
      | `RelatedActiveContentsExist
      | `HTTPStatusNotOK
      | `SchemeNotHTTPOrHTTPS
      | `Loading
      | `WasGrantedMediaAccess
      | `DisableForRenderFrameHostCalled
      | `DomainNotAllowed
      | `HTTPMethodNotGET
      | `SubframeIsNavigating
      | `Timeout
      | `CacheLimit
      | `JavaScriptExecution
      | `RendererProcessKilled
      | `RendererProcessCrashed
      | `GrantedMediaStreamAccess
      | `SchedulerTrackedFeatureUsed
      | `ConflictingBrowsingInstance
      | `CacheFlushed
      | `ServiceWorkerVersionActivation
      | `SessionRestored
      | `ServiceWorkerPostMessage
      | `EnteredBackForwardCacheBeforeServiceWorkerHostAdded
      | `RenderFrameHostReused_SameSite
      | `RenderFrameHostReused_CrossSite
      | `ServiceWorkerClaim
      | `IgnoreEventAndEvict
      | `HaveInnerContents
      | `TimeoutPuttingInCache
      | `BackForwardCacheDisabledByLowMemory
      | `BackForwardCacheDisabledByCommandLine
      | `NetworkRequestDatapipeDrainedAsBytesConsumer
      | `NetworkRequestRedirected
      | `NetworkRequestTimeout
      | `NetworkExceedsBufferLimit
      | `NavigationCancelledWhileRestoring
      | `NotMostRecentNavigationEntry
      | `BackForwardCacheDisabledForPrerender
      | `UserAgentOverrideDiffers
      | `ForegroundCacheLimit
      | `BrowsingInstanceNotSwapped
      | `BackForwardCacheDisabledForDelegate
      | `OptInUnloadHeaderNotPresent
      | `UnloadHandlerExistsInMainFrame
      | `UnloadHandlerExistsInSubFrame
      | `ServiceWorkerUnregistration
      | `CacheControlNoStore
      | `CacheControlNoStoreCookieModified
      | `CacheControlNoStoreHTTPOnlyCookieModified
      | `NoResponseHead
      | `Unknown
      | `ActivationNavigationsDisallowedForBug1234857
      | `WebSocket
      | `WebTransport
      | `WebRTC
      | `MainResourceHasCacheControlNoStore
      | `MainResourceHasCacheControlNoCache
      | `SubresourceHasCacheControlNoStore
      | `SubresourceHasCacheControlNoCache
      | `ContainsPlugins
      | `DocumentLoaded
      | `DedicatedWorkerOrWorklet
      | `OutstandingNetworkRequestOthers
      | `OutstandingIndexedDBTransaction
      | `RequestedNotificationsPermission
      | `RequestedMIDIPermission
      | `RequestedAudioCapturePermission
      | `RequestedVideoCapturePermission
      | `RequestedBackForwardCacheBlockedSensors
      | `RequestedBackgroundWorkPermission
      | `BroadcastChannel
      | `IndexedDBConnection
      | `WebXR
      | `SharedWorker
      | `WebLocks
      | `WebHID
      | `WebShare
      | `RequestedStorageAccessGrant
      | `WebNfc
      | `OutstandingNetworkRequestFetch
      | `OutstandingNetworkRequestXHR
      | `AppBanner
      | `Printing
      | `WebDatabase
      | `PictureInPicture
      | `Portal
      | `SpeechRecognizer
      | `IdleManager
      | `PaymentManager
      | `SpeechSynthesis
      | `KeyboardLock
      | `WebOTPService
      | `OutstandingNetworkRequestDirectSocket
      | `InjectedJavascript
      | `InjectedStyleSheet
      | `Dummy
      | `ContentSecurityHandler
      | `ContentWebAuthenticationAPI
      | `ContentFileChooser
      | `ContentSerial
      | `ContentFileSystemAccess
      | `ContentMediaDevicesDispatcherHost
      | `ContentWebBluetooth
      | `ContentWebUSB
      | `ContentMediaSession
      | `ContentMediaSessionService
      | `EmbedderPopupBlockerTabHelper
      | `EmbedderSafeBrowsingTriggeredPopupBlocker
      | `EmbedderSafeBrowsingThreatDetails
      | `EmbedderAppBannerManager
      | `EmbedderDomDistillerViewerSource
      | `EmbedderDomDistillerSelfDeletingRequestDelegate
      | `EmbedderOomInterventionTabHelper
      | `EmbedderOfflinePage
      | `EmbedderChromePasswordManagerClientBindCredentialManager
      | `EmbedderPermissionRequestManager
      | `EmbedderModalDialog
      | `EmbedderExtensions
      | `EmbedderExtensionMessaging
      | `EmbedderExtensionMessagingForOpenPort
      | `EmbedderExtensionSentMessageToCachedFrame
    ];
    let _backforwardcachenotrestoredreason_of_yojson =
      fun
      | `String("NotMainFrame") => `NotMainFrame
      | `String("BackForwardCacheDisabled") => `BackForwardCacheDisabled
      | `String("RelatedActiveContentsExist") => `RelatedActiveContentsExist
      | `String("HTTPStatusNotOK") => `HTTPStatusNotOK
      | `String("SchemeNotHTTPOrHTTPS") => `SchemeNotHTTPOrHTTPS
      | `String("Loading") => `Loading
      | `String("WasGrantedMediaAccess") => `WasGrantedMediaAccess
      | `String("DisableForRenderFrameHostCalled") => `DisableForRenderFrameHostCalled
      | `String("DomainNotAllowed") => `DomainNotAllowed
      | `String("HTTPMethodNotGET") => `HTTPMethodNotGET
      | `String("SubframeIsNavigating") => `SubframeIsNavigating
      | `String("Timeout") => `Timeout
      | `String("CacheLimit") => `CacheLimit
      | `String("JavaScriptExecution") => `JavaScriptExecution
      | `String("RendererProcessKilled") => `RendererProcessKilled
      | `String("RendererProcessCrashed") => `RendererProcessCrashed
      | `String("GrantedMediaStreamAccess") => `GrantedMediaStreamAccess
      | `String("SchedulerTrackedFeatureUsed") => `SchedulerTrackedFeatureUsed
      | `String("ConflictingBrowsingInstance") => `ConflictingBrowsingInstance
      | `String("CacheFlushed") => `CacheFlushed
      | `String("ServiceWorkerVersionActivation") => `ServiceWorkerVersionActivation
      | `String("SessionRestored") => `SessionRestored
      | `String("ServiceWorkerPostMessage") => `ServiceWorkerPostMessage
      | `String("EnteredBackForwardCacheBeforeServiceWorkerHostAdded") => `EnteredBackForwardCacheBeforeServiceWorkerHostAdded
      | `String("RenderFrameHostReused_SameSite") => `RenderFrameHostReused_SameSite
      | `String("RenderFrameHostReused_CrossSite") => `RenderFrameHostReused_CrossSite
      | `String("ServiceWorkerClaim") => `ServiceWorkerClaim
      | `String("IgnoreEventAndEvict") => `IgnoreEventAndEvict
      | `String("HaveInnerContents") => `HaveInnerContents
      | `String("TimeoutPuttingInCache") => `TimeoutPuttingInCache
      | `String("BackForwardCacheDisabledByLowMemory") => `BackForwardCacheDisabledByLowMemory
      | `String("BackForwardCacheDisabledByCommandLine") => `BackForwardCacheDisabledByCommandLine
      | `String("NetworkRequestDatapipeDrainedAsBytesConsumer") => `NetworkRequestDatapipeDrainedAsBytesConsumer
      | `String("NetworkRequestRedirected") => `NetworkRequestRedirected
      | `String("NetworkRequestTimeout") => `NetworkRequestTimeout
      | `String("NetworkExceedsBufferLimit") => `NetworkExceedsBufferLimit
      | `String("NavigationCancelledWhileRestoring") => `NavigationCancelledWhileRestoring
      | `String("NotMostRecentNavigationEntry") => `NotMostRecentNavigationEntry
      | `String("BackForwardCacheDisabledForPrerender") => `BackForwardCacheDisabledForPrerender
      | `String("UserAgentOverrideDiffers") => `UserAgentOverrideDiffers
      | `String("ForegroundCacheLimit") => `ForegroundCacheLimit
      | `String("BrowsingInstanceNotSwapped") => `BrowsingInstanceNotSwapped
      | `String("BackForwardCacheDisabledForDelegate") => `BackForwardCacheDisabledForDelegate
      | `String("OptInUnloadHeaderNotPresent") => `OptInUnloadHeaderNotPresent
      | `String("UnloadHandlerExistsInMainFrame") => `UnloadHandlerExistsInMainFrame
      | `String("UnloadHandlerExistsInSubFrame") => `UnloadHandlerExistsInSubFrame
      | `String("ServiceWorkerUnregistration") => `ServiceWorkerUnregistration
      | `String("CacheControlNoStore") => `CacheControlNoStore
      | `String("CacheControlNoStoreCookieModified") => `CacheControlNoStoreCookieModified
      | `String("CacheControlNoStoreHTTPOnlyCookieModified") => `CacheControlNoStoreHTTPOnlyCookieModified
      | `String("NoResponseHead") => `NoResponseHead
      | `String("Unknown") => `Unknown
      | `String("ActivationNavigationsDisallowedForBug1234857") => `ActivationNavigationsDisallowedForBug1234857
      | `String("WebSocket") => `WebSocket
      | `String("WebTransport") => `WebTransport
      | `String("WebRTC") => `WebRTC
      | `String("MainResourceHasCacheControlNoStore") => `MainResourceHasCacheControlNoStore
      | `String("MainResourceHasCacheControlNoCache") => `MainResourceHasCacheControlNoCache
      | `String("SubresourceHasCacheControlNoStore") => `SubresourceHasCacheControlNoStore
      | `String("SubresourceHasCacheControlNoCache") => `SubresourceHasCacheControlNoCache
      | `String("ContainsPlugins") => `ContainsPlugins
      | `String("DocumentLoaded") => `DocumentLoaded
      | `String("DedicatedWorkerOrWorklet") => `DedicatedWorkerOrWorklet
      | `String("OutstandingNetworkRequestOthers") => `OutstandingNetworkRequestOthers
      | `String("OutstandingIndexedDBTransaction") => `OutstandingIndexedDBTransaction
      | `String("RequestedNotificationsPermission") => `RequestedNotificationsPermission
      | `String("RequestedMIDIPermission") => `RequestedMIDIPermission
      | `String("RequestedAudioCapturePermission") => `RequestedAudioCapturePermission
      | `String("RequestedVideoCapturePermission") => `RequestedVideoCapturePermission
      | `String("RequestedBackForwardCacheBlockedSensors") => `RequestedBackForwardCacheBlockedSensors
      | `String("RequestedBackgroundWorkPermission") => `RequestedBackgroundWorkPermission
      | `String("BroadcastChannel") => `BroadcastChannel
      | `String("IndexedDBConnection") => `IndexedDBConnection
      | `String("WebXR") => `WebXR
      | `String("SharedWorker") => `SharedWorker
      | `String("WebLocks") => `WebLocks
      | `String("WebHID") => `WebHID
      | `String("WebShare") => `WebShare
      | `String("RequestedStorageAccessGrant") => `RequestedStorageAccessGrant
      | `String("WebNfc") => `WebNfc
      | `String("OutstandingNetworkRequestFetch") => `OutstandingNetworkRequestFetch
      | `String("OutstandingNetworkRequestXHR") => `OutstandingNetworkRequestXHR
      | `String("AppBanner") => `AppBanner
      | `String("Printing") => `Printing
      | `String("WebDatabase") => `WebDatabase
      | `String("PictureInPicture") => `PictureInPicture
      | `String("Portal") => `Portal
      | `String("SpeechRecognizer") => `SpeechRecognizer
      | `String("IdleManager") => `IdleManager
      | `String("PaymentManager") => `PaymentManager
      | `String("SpeechSynthesis") => `SpeechSynthesis
      | `String("KeyboardLock") => `KeyboardLock
      | `String("WebOTPService") => `WebOTPService
      | `String("OutstandingNetworkRequestDirectSocket") => `OutstandingNetworkRequestDirectSocket
      | `String("InjectedJavascript") => `InjectedJavascript
      | `String("InjectedStyleSheet") => `InjectedStyleSheet
      | `String("Dummy") => `Dummy
      | `String("ContentSecurityHandler") => `ContentSecurityHandler
      | `String("ContentWebAuthenticationAPI") => `ContentWebAuthenticationAPI
      | `String("ContentFileChooser") => `ContentFileChooser
      | `String("ContentSerial") => `ContentSerial
      | `String("ContentFileSystemAccess") => `ContentFileSystemAccess
      | `String("ContentMediaDevicesDispatcherHost") => `ContentMediaDevicesDispatcherHost
      | `String("ContentWebBluetooth") => `ContentWebBluetooth
      | `String("ContentWebUSB") => `ContentWebUSB
      | `String("ContentMediaSession") => `ContentMediaSession
      | `String("ContentMediaSessionService") => `ContentMediaSessionService
      | `String("EmbedderPopupBlockerTabHelper") => `EmbedderPopupBlockerTabHelper
      | `String("EmbedderSafeBrowsingTriggeredPopupBlocker") => `EmbedderSafeBrowsingTriggeredPopupBlocker
      | `String("EmbedderSafeBrowsingThreatDetails") => `EmbedderSafeBrowsingThreatDetails
      | `String("EmbedderAppBannerManager") => `EmbedderAppBannerManager
      | `String("EmbedderDomDistillerViewerSource") => `EmbedderDomDistillerViewerSource
      | `String("EmbedderDomDistillerSelfDeletingRequestDelegate") => `EmbedderDomDistillerSelfDeletingRequestDelegate
      | `String("EmbedderOomInterventionTabHelper") => `EmbedderOomInterventionTabHelper
      | `String("EmbedderOfflinePage") => `EmbedderOfflinePage
      | `String("EmbedderChromePasswordManagerClientBindCredentialManager") => `EmbedderChromePasswordManagerClientBindCredentialManager
      | `String("EmbedderPermissionRequestManager") => `EmbedderPermissionRequestManager
      | `String("EmbedderModalDialog") => `EmbedderModalDialog
      | `String("EmbedderExtensions") => `EmbedderExtensions
      | `String("EmbedderExtensionMessaging") => `EmbedderExtensionMessaging
      | `String("EmbedderExtensionMessagingForOpenPort") => `EmbedderExtensionMessagingForOpenPort
      | `String("EmbedderExtensionSentMessageToCachedFrame") => `EmbedderExtensionSentMessageToCachedFrame
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__backforwardcachenotrestoredreason =
      fun
      | `NotMainFrame => `String("NotMainFrame")
      | `BackForwardCacheDisabled => `String("BackForwardCacheDisabled")
      | `RelatedActiveContentsExist => `String("RelatedActiveContentsExist")
      | `HTTPStatusNotOK => `String("HTTPStatusNotOK")
      | `SchemeNotHTTPOrHTTPS => `String("SchemeNotHTTPOrHTTPS")
      | `Loading => `String("Loading")
      | `WasGrantedMediaAccess => `String("WasGrantedMediaAccess")
      | `DisableForRenderFrameHostCalled =>
        `String("DisableForRenderFrameHostCalled")
      | `DomainNotAllowed => `String("DomainNotAllowed")
      | `HTTPMethodNotGET => `String("HTTPMethodNotGET")
      | `SubframeIsNavigating => `String("SubframeIsNavigating")
      | `Timeout => `String("Timeout")
      | `CacheLimit => `String("CacheLimit")
      | `JavaScriptExecution => `String("JavaScriptExecution")
      | `RendererProcessKilled => `String("RendererProcessKilled")
      | `RendererProcessCrashed => `String("RendererProcessCrashed")
      | `GrantedMediaStreamAccess => `String("GrantedMediaStreamAccess")
      | `SchedulerTrackedFeatureUsed => `String("SchedulerTrackedFeatureUsed")
      | `ConflictingBrowsingInstance => `String("ConflictingBrowsingInstance")
      | `CacheFlushed => `String("CacheFlushed")
      | `ServiceWorkerVersionActivation =>
        `String("ServiceWorkerVersionActivation")
      | `SessionRestored => `String("SessionRestored")
      | `ServiceWorkerPostMessage => `String("ServiceWorkerPostMessage")
      | `EnteredBackForwardCacheBeforeServiceWorkerHostAdded =>
        `String("EnteredBackForwardCacheBeforeServiceWorkerHostAdded")
      | `RenderFrameHostReused_SameSite =>
        `String("RenderFrameHostReused_SameSite")
      | `RenderFrameHostReused_CrossSite =>
        `String("RenderFrameHostReused_CrossSite")
      | `ServiceWorkerClaim => `String("ServiceWorkerClaim")
      | `IgnoreEventAndEvict => `String("IgnoreEventAndEvict")
      | `HaveInnerContents => `String("HaveInnerContents")
      | `TimeoutPuttingInCache => `String("TimeoutPuttingInCache")
      | `BackForwardCacheDisabledByLowMemory =>
        `String("BackForwardCacheDisabledByLowMemory")
      | `BackForwardCacheDisabledByCommandLine =>
        `String("BackForwardCacheDisabledByCommandLine")
      | `NetworkRequestDatapipeDrainedAsBytesConsumer =>
        `String("NetworkRequestDatapipeDrainedAsBytesConsumer")
      | `NetworkRequestRedirected => `String("NetworkRequestRedirected")
      | `NetworkRequestTimeout => `String("NetworkRequestTimeout")
      | `NetworkExceedsBufferLimit => `String("NetworkExceedsBufferLimit")
      | `NavigationCancelledWhileRestoring =>
        `String("NavigationCancelledWhileRestoring")
      | `NotMostRecentNavigationEntry =>
        `String("NotMostRecentNavigationEntry")
      | `BackForwardCacheDisabledForPrerender =>
        `String("BackForwardCacheDisabledForPrerender")
      | `UserAgentOverrideDiffers => `String("UserAgentOverrideDiffers")
      | `ForegroundCacheLimit => `String("ForegroundCacheLimit")
      | `BrowsingInstanceNotSwapped => `String("BrowsingInstanceNotSwapped")
      | `BackForwardCacheDisabledForDelegate =>
        `String("BackForwardCacheDisabledForDelegate")
      | `OptInUnloadHeaderNotPresent => `String("OptInUnloadHeaderNotPresent")
      | `UnloadHandlerExistsInMainFrame =>
        `String("UnloadHandlerExistsInMainFrame")
      | `UnloadHandlerExistsInSubFrame =>
        `String("UnloadHandlerExistsInSubFrame")
      | `ServiceWorkerUnregistration => `String("ServiceWorkerUnregistration")
      | `CacheControlNoStore => `String("CacheControlNoStore")
      | `CacheControlNoStoreCookieModified =>
        `String("CacheControlNoStoreCookieModified")
      | `CacheControlNoStoreHTTPOnlyCookieModified =>
        `String("CacheControlNoStoreHTTPOnlyCookieModified")
      | `NoResponseHead => `String("NoResponseHead")
      | `Unknown => `String("Unknown")
      | `ActivationNavigationsDisallowedForBug1234857 =>
        `String("ActivationNavigationsDisallowedForBug1234857")
      | `WebSocket => `String("WebSocket")
      | `WebTransport => `String("WebTransport")
      | `WebRTC => `String("WebRTC")
      | `MainResourceHasCacheControlNoStore =>
        `String("MainResourceHasCacheControlNoStore")
      | `MainResourceHasCacheControlNoCache =>
        `String("MainResourceHasCacheControlNoCache")
      | `SubresourceHasCacheControlNoStore =>
        `String("SubresourceHasCacheControlNoStore")
      | `SubresourceHasCacheControlNoCache =>
        `String("SubresourceHasCacheControlNoCache")
      | `ContainsPlugins => `String("ContainsPlugins")
      | `DocumentLoaded => `String("DocumentLoaded")
      | `DedicatedWorkerOrWorklet => `String("DedicatedWorkerOrWorklet")
      | `OutstandingNetworkRequestOthers =>
        `String("OutstandingNetworkRequestOthers")
      | `OutstandingIndexedDBTransaction =>
        `String("OutstandingIndexedDBTransaction")
      | `RequestedNotificationsPermission =>
        `String("RequestedNotificationsPermission")
      | `RequestedMIDIPermission => `String("RequestedMIDIPermission")
      | `RequestedAudioCapturePermission =>
        `String("RequestedAudioCapturePermission")
      | `RequestedVideoCapturePermission =>
        `String("RequestedVideoCapturePermission")
      | `RequestedBackForwardCacheBlockedSensors =>
        `String("RequestedBackForwardCacheBlockedSensors")
      | `RequestedBackgroundWorkPermission =>
        `String("RequestedBackgroundWorkPermission")
      | `BroadcastChannel => `String("BroadcastChannel")
      | `IndexedDBConnection => `String("IndexedDBConnection")
      | `WebXR => `String("WebXR")
      | `SharedWorker => `String("SharedWorker")
      | `WebLocks => `String("WebLocks")
      | `WebHID => `String("WebHID")
      | `WebShare => `String("WebShare")
      | `RequestedStorageAccessGrant => `String("RequestedStorageAccessGrant")
      | `WebNfc => `String("WebNfc")
      | `OutstandingNetworkRequestFetch =>
        `String("OutstandingNetworkRequestFetch")
      | `OutstandingNetworkRequestXHR =>
        `String("OutstandingNetworkRequestXHR")
      | `AppBanner => `String("AppBanner")
      | `Printing => `String("Printing")
      | `WebDatabase => `String("WebDatabase")
      | `PictureInPicture => `String("PictureInPicture")
      | `Portal => `String("Portal")
      | `SpeechRecognizer => `String("SpeechRecognizer")
      | `IdleManager => `String("IdleManager")
      | `PaymentManager => `String("PaymentManager")
      | `SpeechSynthesis => `String("SpeechSynthesis")
      | `KeyboardLock => `String("KeyboardLock")
      | `WebOTPService => `String("WebOTPService")
      | `OutstandingNetworkRequestDirectSocket =>
        `String("OutstandingNetworkRequestDirectSocket")
      | `InjectedJavascript => `String("InjectedJavascript")
      | `InjectedStyleSheet => `String("InjectedStyleSheet")
      | `Dummy => `String("Dummy")
      | `ContentSecurityHandler => `String("ContentSecurityHandler")
      | `ContentWebAuthenticationAPI => `String("ContentWebAuthenticationAPI")
      | `ContentFileChooser => `String("ContentFileChooser")
      | `ContentSerial => `String("ContentSerial")
      | `ContentFileSystemAccess => `String("ContentFileSystemAccess")
      | `ContentMediaDevicesDispatcherHost =>
        `String("ContentMediaDevicesDispatcherHost")
      | `ContentWebBluetooth => `String("ContentWebBluetooth")
      | `ContentWebUSB => `String("ContentWebUSB")
      | `ContentMediaSession => `String("ContentMediaSession")
      | `ContentMediaSessionService => `String("ContentMediaSessionService")
      | `EmbedderPopupBlockerTabHelper =>
        `String("EmbedderPopupBlockerTabHelper")
      | `EmbedderSafeBrowsingTriggeredPopupBlocker =>
        `String("EmbedderSafeBrowsingTriggeredPopupBlocker")
      | `EmbedderSafeBrowsingThreatDetails =>
        `String("EmbedderSafeBrowsingThreatDetails")
      | `EmbedderAppBannerManager => `String("EmbedderAppBannerManager")
      | `EmbedderDomDistillerViewerSource =>
        `String("EmbedderDomDistillerViewerSource")
      | `EmbedderDomDistillerSelfDeletingRequestDelegate =>
        `String("EmbedderDomDistillerSelfDeletingRequestDelegate")
      | `EmbedderOomInterventionTabHelper =>
        `String("EmbedderOomInterventionTabHelper")
      | `EmbedderOfflinePage => `String("EmbedderOfflinePage")
      | `EmbedderChromePasswordManagerClientBindCredentialManager =>
        `String("EmbedderChromePasswordManagerClientBindCredentialManager")
      | `EmbedderPermissionRequestManager =>
        `String("EmbedderPermissionRequestManager")
      | `EmbedderModalDialog => `String("EmbedderModalDialog")
      | `EmbedderExtensions => `String("EmbedderExtensions")
      | `EmbedderExtensionMessaging => `String("EmbedderExtensionMessaging")
      | `EmbedderExtensionMessagingForOpenPort =>
        `String("EmbedderExtensionMessagingForOpenPort")
      | `EmbedderExtensionSentMessageToCachedFrame =>
        `String("EmbedderExtensionSentMessageToCachedFrame");
    /* List of not restored reasons for back-forward cache. */
    [@deriving yojson]
    type t = _backforwardcachenotrestoredreason;
  }
  and BackForwardCacheNotRestoredReasonType: {
    type _backforwardcachenotrestoredreasontype = [
      | `SupportPending
      | `PageSupportNeeded
      | `Circumstantial
    ];
    let _backforwardcachenotrestoredreasontype_of_yojson:
      Yojson.Basic.t => _backforwardcachenotrestoredreasontype;
    let yojson_of__backforwardcachenotrestoredreasontype:
      _backforwardcachenotrestoredreasontype => Yojson.Basic.t;
    /* Types of not restored reasons for back-forward cache. */
    [@deriving yojson]
    type t = _backforwardcachenotrestoredreasontype;
  } = {
    type _backforwardcachenotrestoredreasontype = [
      | `SupportPending
      | `PageSupportNeeded
      | `Circumstantial
    ];
    let _backforwardcachenotrestoredreasontype_of_yojson =
      fun
      | `String("SupportPending") => `SupportPending
      | `String("PageSupportNeeded") => `PageSupportNeeded
      | `String("Circumstantial") => `Circumstantial
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__backforwardcachenotrestoredreasontype =
      fun
      | `SupportPending => `String("SupportPending")
      | `PageSupportNeeded => `String("PageSupportNeeded")
      | `Circumstantial => `String("Circumstantial");
    /* Types of not restored reasons for back-forward cache. */
    [@deriving yojson]
    type t = _backforwardcachenotrestoredreasontype;
  }
  and BackForwardCacheNotRestoredExplanation: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: BackForwardCacheNotRestoredReasonType.t, /* Type of the reason */
      [@key "reason"]
      reason: BackForwardCacheNotRestoredReason.t /* Not restored reason */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: BackForwardCacheNotRestoredReasonType.t, /* Type of the reason */
      [@key "reason"]
      reason: BackForwardCacheNotRestoredReason.t /* Not restored reason */,
    };
  };
}
and Performance: {
  module rec Metric: {
    /* Run-time execution metric. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Metric name. */
      [@key "value"]
      value: float /* Metric value. */,
    };
  };
} = {
  module rec Metric: {
    /* Run-time execution metric. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Metric name. */
      [@key "value"]
      value: float /* Metric value. */,
    };
  } = {
    /* Run-time execution metric. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Metric name. */
      [@key "value"]
      value: float /* Metric value. */,
    };
  };
}
and PerformanceTimeline: {
  module rec LargestContentfulPaint: {
    /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
    [@deriving yojson]
    type t = {
      [@key "renderTime"]
      renderTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "loadTime"]
      loadTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "size"]
      size: float, /* The number of pixels being painted. */
      [@yojson.option] [@key "elementId"]
      elementId: option(string), /* The id attribute of the element, if available. */
      [@yojson.option] [@key "url"]
      url: option(string), /* The URL of the image (may be trimmed). */
      [@yojson.option] [@key "nodeId"]
      nodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  }
  and LayoutShiftAttribution: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "previousRect"]
      previousRect: DOM.Rect.t, /* No description provided */
      [@key "currentRect"]
      currentRect: DOM.Rect.t, /* No description provided */
      [@yojson.option] [@key "nodeId"]
      nodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  }
  and LayoutShift: {
    /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: float, /* Score increment produced by this event. */
      [@key "hadRecentInput"]
      hadRecentInput: bool, /* No description provided */
      [@key "lastInputTime"]
      lastInputTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "sources"]
      sources: list(LayoutShiftAttribution.t) /* No description provided */,
    };
  }
  and TimelineEvent: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: Page.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
      [@key "type"]
      type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
      [@key "name"]
      name: string, /* Name may be empty depending on the type. */
      [@key "time"]
      time: Network.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
      [@yojson.option] [@key "duration"]
      duration: option(float), /* Event duration, if applicable. */
      [@yojson.option] [@key "lcpDetails"]
      lcpDetails: option(LargestContentfulPaint.t), /* No description provided */
      [@yojson.option] [@key "layoutShiftDetails"]
      layoutShiftDetails: option(LayoutShift.t) /* No description provided */,
    };
  };
} = {
  module rec LargestContentfulPaint: {
    /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
    [@deriving yojson]
    type t = {
      [@key "renderTime"]
      renderTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "loadTime"]
      loadTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "size"]
      size: float, /* The number of pixels being painted. */
      [@yojson.option] [@key "elementId"]
      elementId: option(string), /* The id attribute of the element, if available. */
      [@yojson.option] [@key "url"]
      url: option(string), /* The URL of the image (may be trimmed). */
      [@yojson.option] [@key "nodeId"]
      nodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  } = {
    /* See https://github.com/WICG/LargestContentfulPaint and largest_contentful_paint.idl */
    [@deriving yojson]
    type t = {
      [@key "renderTime"]
      renderTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "loadTime"]
      loadTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "size"]
      size: float, /* The number of pixels being painted. */
      [@yojson.option] [@key "elementId"]
      elementId: option(string), /* The id attribute of the element, if available. */
      [@yojson.option] [@key "url"]
      url: option(string), /* The URL of the image (may be trimmed). */
      [@yojson.option] [@key "nodeId"]
      nodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  }
  and LayoutShiftAttribution: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "previousRect"]
      previousRect: DOM.Rect.t, /* No description provided */
      [@key "currentRect"]
      currentRect: DOM.Rect.t, /* No description provided */
      [@yojson.option] [@key "nodeId"]
      nodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "previousRect"]
      previousRect: DOM.Rect.t, /* No description provided */
      [@key "currentRect"]
      currentRect: DOM.Rect.t, /* No description provided */
      [@yojson.option] [@key "nodeId"]
      nodeId: option(DOM.BackendNodeId.t) /* No description provided */,
    };
  }
  and LayoutShift: {
    /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: float, /* Score increment produced by this event. */
      [@key "hadRecentInput"]
      hadRecentInput: bool, /* No description provided */
      [@key "lastInputTime"]
      lastInputTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "sources"]
      sources: list(LayoutShiftAttribution.t) /* No description provided */,
    };
  } = {
    /* See https://wicg.github.io/layout-instability/#sec-layout-shift and layout_shift.idl */
    [@deriving yojson]
    type t = {
      [@key "value"]
      value: float, /* Score increment produced by this event. */
      [@key "hadRecentInput"]
      hadRecentInput: bool, /* No description provided */
      [@key "lastInputTime"]
      lastInputTime: Network.TimeSinceEpoch.t, /* No description provided */
      [@key "sources"]
      sources: list(LayoutShiftAttribution.t) /* No description provided */,
    };
  }
  and TimelineEvent: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: Page.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
      [@key "type"]
      type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
      [@key "name"]
      name: string, /* Name may be empty depending on the type. */
      [@key "time"]
      time: Network.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
      [@yojson.option] [@key "duration"]
      duration: option(float), /* Event duration, if applicable. */
      [@yojson.option] [@key "lcpDetails"]
      lcpDetails: option(LargestContentfulPaint.t), /* No description provided */
      [@yojson.option] [@key "layoutShiftDetails"]
      layoutShiftDetails: option(LayoutShift.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "frameId"]
      frameId: Page.FrameId.t, /* Identifies the frame that this event is related to. Empty for non-frame targets. */
      [@key "type"]
      type_: string, /* The event type, as specified in https://w3c.github.io/performance-timeline/#dom-performanceentry-entrytype
This determines which of the optional "details" fiedls is present. */
      [@key "name"]
      name: string, /* Name may be empty depending on the type. */
      [@key "time"]
      time: Network.TimeSinceEpoch.t, /* Time in seconds since Epoch, monotonically increasing within document lifetime. */
      [@yojson.option] [@key "duration"]
      duration: option(float), /* Event duration, if applicable. */
      [@yojson.option] [@key "lcpDetails"]
      lcpDetails: option(LargestContentfulPaint.t), /* No description provided */
      [@yojson.option] [@key "layoutShiftDetails"]
      layoutShiftDetails: option(LayoutShift.t) /* No description provided */,
    };
  };
}
and Security: {
  module rec CertificateId: {
    /* An internal certificate ID value. */
    [@deriving yojson]
    type t = float;
  }
  and MixedContentType: {
    type _mixedcontenttype = [ | `blockable | `optionally_blockable | `none];
    let _mixedcontenttype_of_yojson: Yojson.Basic.t => _mixedcontenttype;
    let yojson_of__mixedcontenttype: _mixedcontenttype => Yojson.Basic.t;
    /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
       https://www.w3.org/TR/mixed-content/#categories */
    [@deriving yojson]
    type t = _mixedcontenttype;
  }
  and SecurityState: {
    type _securitystate = [
      | `unknown
      | `neutral
      | `insecure
      | `secure
      | `info
      | `insecure_broken
    ];
    let _securitystate_of_yojson: Yojson.Basic.t => _securitystate;
    let yojson_of__securitystate: _securitystate => Yojson.Basic.t;
    /* The security level of a page or resource. */
    [@deriving yojson]
    type t = _securitystate;
  }
  and CertificateSecurityState: {
    /* Details about the security state of the page certificate. */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
      [@key "keyExchange"]
      keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
      [@yojson.option] [@key "keyExchangeGroup"]
      keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
      [@key "cipher"]
      cipher: string, /* Cipher name. */
      [@yojson.option] [@key "mac"]
      mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
      [@key "certificate"]
      certificate: list(string), /* Page certificate. */
      [@key "subjectName"]
      subjectName: string, /* Certificate subject name. */
      [@key "issuer"]
      issuer: string, /* Name of the issuing CA. */
      [@key "validFrom"]
      validFrom: Network.TimeSinceEpoch.t, /* Certificate valid from date. */
      [@key "validTo"]
      validTo: Network.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
      [@yojson.option] [@key "certificateNetworkError"]
      certificateNetworkError: option(string), /* The highest priority network error code, if the certificate has an error. */
      [@key "certificateHasWeakSignature"]
      certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
      [@key "certificateHasSha1Signature"]
      certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
      [@key "modernSSL"]
      modernSSL: bool, /* True if modern SSL */
      [@key "obsoleteSslProtocol"]
      obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
      [@key "obsoleteSslKeyExchange"]
      obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
      [@key "obsoleteSslCipher"]
      obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
      [@key "obsoleteSslSignature"]
      obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
    };
  }
  and SafetyTipStatus: {
    type _safetytipstatus = [ | `badReputation | `lookalike];
    let _safetytipstatus_of_yojson: Yojson.Basic.t => _safetytipstatus;
    let yojson_of__safetytipstatus: _safetytipstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _safetytipstatus;
  }
  and SafetyTipInfo: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "safetyTipStatus"]
      safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
      [@yojson.option] [@key "safeUrl"]
      safeUrl: option(string) /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
    };
  }
  and VisibleSecurityState: {
    /* Security state information about the page. */
    [@deriving yojson]
    type t = {
      [@key "securityState"]
      securityState: SecurityState.t, /* The security level of the page. */
      [@yojson.option] [@key "certificateSecurityState"]
      certificateSecurityState: option(CertificateSecurityState.t), /* Security state details about the page certificate. */
      [@yojson.option] [@key "safetyTipInfo"]
      safetyTipInfo: option(SafetyTipInfo.t), /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
      [@key "securityStateIssueIds"]
      securityStateIssueIds: list(string) /* Array of security state issues ids. */,
    };
  }
  and SecurityStateExplanation: {
    /* An explanation of an factor contributing to the security state. */
    [@deriving yojson]
    type t = {
      [@key "securityState"]
      securityState: SecurityState.t, /* Security state representing the severity of the factor being explained. */
      [@key "title"]
      title: string, /* Title describing the type of factor. */
      [@key "summary"]
      summary: string, /* Short phrase describing the type of factor. */
      [@key "description"]
      description: string, /* Full text explanation of the factor. */
      [@key "mixedContentType"]
      mixedContentType: MixedContentType.t, /* The type of mixed content described by the explanation. */
      [@key "certificate"]
      certificate: list(string), /* Page certificate. */
      [@yojson.option] [@key "recommendations"]
      recommendations: option(list(string)) /* Recommendations to fix any issues. */,
    };
  }
  and InsecureContentStatus: {
    /* Information about insecure content on the page. */
    [@deriving yojson]
    type t = {
      [@key "ranMixedContent"]
      ranMixedContent: bool, /* Always false. */
      [@key "displayedMixedContent"]
      displayedMixedContent: bool, /* Always false. */
      [@key "containedMixedForm"]
      containedMixedForm: bool, /* Always false. */
      [@key "ranContentWithCertErrors"]
      ranContentWithCertErrors: bool, /* Always false. */
      [@key "displayedContentWithCertErrors"]
      displayedContentWithCertErrors: bool, /* Always false. */
      [@key "ranInsecureContentStyle"]
      ranInsecureContentStyle: SecurityState.t, /* Always set to unknown. */
      [@key "displayedInsecureContentStyle"]
      displayedInsecureContentStyle: SecurityState.t /* Always set to unknown. */,
    };
  }
  and CertificateErrorAction: {
    type _certificateerroraction = [ | `continue | `cancel];
    let _certificateerroraction_of_yojson:
      Yojson.Basic.t => _certificateerroraction;
    let yojson_of__certificateerroraction:
      _certificateerroraction => Yojson.Basic.t;
    /* The action to take when a certificate error occurs. continue will continue processing the
       request and cancel will cancel the request. */
    [@deriving yojson]
    type t = _certificateerroraction;
  };
} = {
  module rec CertificateId: {
    /* An internal certificate ID value. */
    [@deriving yojson]
    type t = float;
  } = {
    /* An internal certificate ID value. */
    [@deriving yojson]
    type t = float;
  }
  and MixedContentType: {
    type _mixedcontenttype = [ | `blockable | `optionally_blockable | `none];
    let _mixedcontenttype_of_yojson: Yojson.Basic.t => _mixedcontenttype;
    let yojson_of__mixedcontenttype: _mixedcontenttype => Yojson.Basic.t;
    /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
       https://www.w3.org/TR/mixed-content/#categories */
    [@deriving yojson]
    type t = _mixedcontenttype;
  } = {
    type _mixedcontenttype = [ | `blockable | `optionally_blockable | `none];
    let _mixedcontenttype_of_yojson =
      fun
      | `String("blockable") => `blockable
      | `String("optionally-blockable") => `optionally_blockable
      | `String("none") => `none
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__mixedcontenttype =
      fun
      | `blockable => `String("blockable")
      | `optionally_blockable => `String("optionally-blockable")
      | `none => `String("none");
    /* A description of mixed content (HTTP resources on HTTPS pages), as defined by
       https://www.w3.org/TR/mixed-content/#categories */
    [@deriving yojson]
    type t = _mixedcontenttype;
  }
  and SecurityState: {
    type _securitystate = [
      | `unknown
      | `neutral
      | `insecure
      | `secure
      | `info
      | `insecure_broken
    ];
    let _securitystate_of_yojson: Yojson.Basic.t => _securitystate;
    let yojson_of__securitystate: _securitystate => Yojson.Basic.t;
    /* The security level of a page or resource. */
    [@deriving yojson]
    type t = _securitystate;
  } = {
    type _securitystate = [
      | `unknown
      | `neutral
      | `insecure
      | `secure
      | `info
      | `insecure_broken
    ];
    let _securitystate_of_yojson =
      fun
      | `String("unknown") => `unknown
      | `String("neutral") => `neutral
      | `String("insecure") => `insecure
      | `String("secure") => `secure
      | `String("info") => `info
      | `String("insecure-broken") => `insecure_broken
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__securitystate =
      fun
      | `unknown => `String("unknown")
      | `neutral => `String("neutral")
      | `insecure => `String("insecure")
      | `secure => `String("secure")
      | `info => `String("info")
      | `insecure_broken => `String("insecure-broken");
    /* The security level of a page or resource. */
    [@deriving yojson]
    type t = _securitystate;
  }
  and CertificateSecurityState: {
    /* Details about the security state of the page certificate. */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
      [@key "keyExchange"]
      keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
      [@yojson.option] [@key "keyExchangeGroup"]
      keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
      [@key "cipher"]
      cipher: string, /* Cipher name. */
      [@yojson.option] [@key "mac"]
      mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
      [@key "certificate"]
      certificate: list(string), /* Page certificate. */
      [@key "subjectName"]
      subjectName: string, /* Certificate subject name. */
      [@key "issuer"]
      issuer: string, /* Name of the issuing CA. */
      [@key "validFrom"]
      validFrom: Network.TimeSinceEpoch.t, /* Certificate valid from date. */
      [@key "validTo"]
      validTo: Network.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
      [@yojson.option] [@key "certificateNetworkError"]
      certificateNetworkError: option(string), /* The highest priority network error code, if the certificate has an error. */
      [@key "certificateHasWeakSignature"]
      certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
      [@key "certificateHasSha1Signature"]
      certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
      [@key "modernSSL"]
      modernSSL: bool, /* True if modern SSL */
      [@key "obsoleteSslProtocol"]
      obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
      [@key "obsoleteSslKeyExchange"]
      obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
      [@key "obsoleteSslCipher"]
      obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
      [@key "obsoleteSslSignature"]
      obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
    };
  } = {
    /* Details about the security state of the page certificate. */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: string, /* Protocol name (e.g. "TLS 1.2" or "QUIC"). */
      [@key "keyExchange"]
      keyExchange: string, /* Key Exchange used by the connection, or the empty string if not applicable. */
      [@yojson.option] [@key "keyExchangeGroup"]
      keyExchangeGroup: option(string), /* (EC)DH group used by the connection, if applicable. */
      [@key "cipher"]
      cipher: string, /* Cipher name. */
      [@yojson.option] [@key "mac"]
      mac: option(string), /* TLS MAC. Note that AEAD ciphers do not have separate MACs. */
      [@key "certificate"]
      certificate: list(string), /* Page certificate. */
      [@key "subjectName"]
      subjectName: string, /* Certificate subject name. */
      [@key "issuer"]
      issuer: string, /* Name of the issuing CA. */
      [@key "validFrom"]
      validFrom: Network.TimeSinceEpoch.t, /* Certificate valid from date. */
      [@key "validTo"]
      validTo: Network.TimeSinceEpoch.t, /* Certificate valid to (expiration) date */
      [@yojson.option] [@key "certificateNetworkError"]
      certificateNetworkError: option(string), /* The highest priority network error code, if the certificate has an error. */
      [@key "certificateHasWeakSignature"]
      certificateHasWeakSignature: bool, /* True if the certificate uses a weak signature aglorithm. */
      [@key "certificateHasSha1Signature"]
      certificateHasSha1Signature: bool, /* True if the certificate has a SHA1 signature in the chain. */
      [@key "modernSSL"]
      modernSSL: bool, /* True if modern SSL */
      [@key "obsoleteSslProtocol"]
      obsoleteSslProtocol: bool, /* True if the connection is using an obsolete SSL protocol. */
      [@key "obsoleteSslKeyExchange"]
      obsoleteSslKeyExchange: bool, /* True if the connection is using an obsolete SSL key exchange. */
      [@key "obsoleteSslCipher"]
      obsoleteSslCipher: bool, /* True if the connection is using an obsolete SSL cipher. */
      [@key "obsoleteSslSignature"]
      obsoleteSslSignature: bool /* True if the connection is using an obsolete SSL signature. */,
    };
  }
  and SafetyTipStatus: {
    type _safetytipstatus = [ | `badReputation | `lookalike];
    let _safetytipstatus_of_yojson: Yojson.Basic.t => _safetytipstatus;
    let yojson_of__safetytipstatus: _safetytipstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _safetytipstatus;
  } = {
    type _safetytipstatus = [ | `badReputation | `lookalike];
    let _safetytipstatus_of_yojson =
      fun
      | `String("badReputation") => `badReputation
      | `String("lookalike") => `lookalike
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__safetytipstatus =
      fun
      | `badReputation => `String("badReputation")
      | `lookalike => `String("lookalike");
    /* No description provided */
    [@deriving yojson]
    type t = _safetytipstatus;
  }
  and SafetyTipInfo: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "safetyTipStatus"]
      safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
      [@yojson.option] [@key "safeUrl"]
      safeUrl: option(string) /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "safetyTipStatus"]
      safetyTipStatus: SafetyTipStatus.t, /* Describes whether the page triggers any safety tips or reputation warnings. Default is unknown. */
      [@yojson.option] [@key "safeUrl"]
      safeUrl: option(string) /* The URL the safety tip suggested ("Did you mean?"). Only filled in for lookalike matches. */,
    };
  }
  and VisibleSecurityState: {
    /* Security state information about the page. */
    [@deriving yojson]
    type t = {
      [@key "securityState"]
      securityState: SecurityState.t, /* The security level of the page. */
      [@yojson.option] [@key "certificateSecurityState"]
      certificateSecurityState: option(CertificateSecurityState.t), /* Security state details about the page certificate. */
      [@yojson.option] [@key "safetyTipInfo"]
      safetyTipInfo: option(SafetyTipInfo.t), /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
      [@key "securityStateIssueIds"]
      securityStateIssueIds: list(string) /* Array of security state issues ids. */,
    };
  } = {
    /* Security state information about the page. */
    [@deriving yojson]
    type t = {
      [@key "securityState"]
      securityState: SecurityState.t, /* The security level of the page. */
      [@yojson.option] [@key "certificateSecurityState"]
      certificateSecurityState: option(CertificateSecurityState.t), /* Security state details about the page certificate. */
      [@yojson.option] [@key "safetyTipInfo"]
      safetyTipInfo: option(SafetyTipInfo.t), /* The type of Safety Tip triggered on the page. Note that this field will be set even if the Safety Tip UI was not actually shown. */
      [@key "securityStateIssueIds"]
      securityStateIssueIds: list(string) /* Array of security state issues ids. */,
    };
  }
  and SecurityStateExplanation: {
    /* An explanation of an factor contributing to the security state. */
    [@deriving yojson]
    type t = {
      [@key "securityState"]
      securityState: SecurityState.t, /* Security state representing the severity of the factor being explained. */
      [@key "title"]
      title: string, /* Title describing the type of factor. */
      [@key "summary"]
      summary: string, /* Short phrase describing the type of factor. */
      [@key "description"]
      description: string, /* Full text explanation of the factor. */
      [@key "mixedContentType"]
      mixedContentType: MixedContentType.t, /* The type of mixed content described by the explanation. */
      [@key "certificate"]
      certificate: list(string), /* Page certificate. */
      [@yojson.option] [@key "recommendations"]
      recommendations: option(list(string)) /* Recommendations to fix any issues. */,
    };
  } = {
    /* An explanation of an factor contributing to the security state. */
    [@deriving yojson]
    type t = {
      [@key "securityState"]
      securityState: SecurityState.t, /* Security state representing the severity of the factor being explained. */
      [@key "title"]
      title: string, /* Title describing the type of factor. */
      [@key "summary"]
      summary: string, /* Short phrase describing the type of factor. */
      [@key "description"]
      description: string, /* Full text explanation of the factor. */
      [@key "mixedContentType"]
      mixedContentType: MixedContentType.t, /* The type of mixed content described by the explanation. */
      [@key "certificate"]
      certificate: list(string), /* Page certificate. */
      [@yojson.option] [@key "recommendations"]
      recommendations: option(list(string)) /* Recommendations to fix any issues. */,
    };
  }
  and InsecureContentStatus: {
    /* Information about insecure content on the page. */
    [@deriving yojson]
    type t = {
      [@key "ranMixedContent"]
      ranMixedContent: bool, /* Always false. */
      [@key "displayedMixedContent"]
      displayedMixedContent: bool, /* Always false. */
      [@key "containedMixedForm"]
      containedMixedForm: bool, /* Always false. */
      [@key "ranContentWithCertErrors"]
      ranContentWithCertErrors: bool, /* Always false. */
      [@key "displayedContentWithCertErrors"]
      displayedContentWithCertErrors: bool, /* Always false. */
      [@key "ranInsecureContentStyle"]
      ranInsecureContentStyle: SecurityState.t, /* Always set to unknown. */
      [@key "displayedInsecureContentStyle"]
      displayedInsecureContentStyle: SecurityState.t /* Always set to unknown. */,
    };
  } = {
    /* Information about insecure content on the page. */
    [@deriving yojson]
    type t = {
      [@key "ranMixedContent"]
      ranMixedContent: bool, /* Always false. */
      [@key "displayedMixedContent"]
      displayedMixedContent: bool, /* Always false. */
      [@key "containedMixedForm"]
      containedMixedForm: bool, /* Always false. */
      [@key "ranContentWithCertErrors"]
      ranContentWithCertErrors: bool, /* Always false. */
      [@key "displayedContentWithCertErrors"]
      displayedContentWithCertErrors: bool, /* Always false. */
      [@key "ranInsecureContentStyle"]
      ranInsecureContentStyle: SecurityState.t, /* Always set to unknown. */
      [@key "displayedInsecureContentStyle"]
      displayedInsecureContentStyle: SecurityState.t /* Always set to unknown. */,
    };
  }
  and CertificateErrorAction: {
    type _certificateerroraction = [ | `continue | `cancel];
    let _certificateerroraction_of_yojson:
      Yojson.Basic.t => _certificateerroraction;
    let yojson_of__certificateerroraction:
      _certificateerroraction => Yojson.Basic.t;
    /* The action to take when a certificate error occurs. continue will continue processing the
       request and cancel will cancel the request. */
    [@deriving yojson]
    type t = _certificateerroraction;
  } = {
    type _certificateerroraction = [ | `continue | `cancel];
    let _certificateerroraction_of_yojson =
      fun
      | `String("continue") => `continue
      | `String("cancel") => `cancel
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__certificateerroraction =
      fun
      | `continue => `String("continue")
      | `cancel => `String("cancel");
    /* The action to take when a certificate error occurs. continue will continue processing the
       request and cancel will cancel the request. */
    [@deriving yojson]
    type t = _certificateerroraction;
  };
}
and ServiceWorker: {
  module rec RegistrationID: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and ServiceWorkerRegistration: {
    /* ServiceWorker registration. */
    [@deriving yojson]
    type t = {
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "scopeURL"]
      scopeURL: string, /* No description provided */
      [@key "isDeleted"]
      isDeleted: bool /* No description provided */,
    };
  }
  and ServiceWorkerVersionRunningStatus: {
    type _serviceworkerversionrunningstatus = [
      | `stopped
      | `starting
      | `running
      | `stopping
    ];
    let _serviceworkerversionrunningstatus_of_yojson:
      Yojson.Basic.t => _serviceworkerversionrunningstatus;
    let yojson_of__serviceworkerversionrunningstatus:
      _serviceworkerversionrunningstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _serviceworkerversionrunningstatus;
  }
  and ServiceWorkerVersionStatus: {
    type _serviceworkerversionstatus = [
      | `new_
      | `installing
      | `installed
      | `activating
      | `activated
      | `redundant
    ];
    let _serviceworkerversionstatus_of_yojson:
      Yojson.Basic.t => _serviceworkerversionstatus;
    let yojson_of__serviceworkerversionstatus:
      _serviceworkerversionstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _serviceworkerversionstatus;
  }
  and ServiceWorkerVersion: {
    /* ServiceWorker version. */
    [@deriving yojson]
    type t = {
      [@key "versionId"]
      versionId: string, /* No description provided */
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "scriptURL"]
      scriptURL: string, /* No description provided */
      [@key "runningStatus"]
      runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
      [@key "status"]
      status: ServiceWorkerVersionStatus.t, /* No description provided */
      [@yojson.option] [@key "scriptLastModified"]
      scriptLastModified: option(float), /* The Last-Modified header value of the main script. */
      [@yojson.option] [@key "scriptResponseTime"]
      scriptResponseTime: option(float), /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
      [@yojson.option] [@key "controlledClients"]
      controlledClients: option(list(Target.TargetID.t)), /* No description provided */
      [@yojson.option] [@key "targetId"]
      targetId: option(Target.TargetID.t) /* No description provided */,
    };
  }
  and ServiceWorkerErrorMessage: {
    /* ServiceWorker error message. */
    [@deriving yojson]
    type t = {
      [@key "errorMessage"]
      errorMessage: string, /* No description provided */
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "versionId"]
      versionId: string, /* No description provided */
      [@key "sourceURL"]
      sourceURL: string, /* No description provided */
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  };
} = {
  module rec RegistrationID: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and ServiceWorkerRegistration: {
    /* ServiceWorker registration. */
    [@deriving yojson]
    type t = {
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "scopeURL"]
      scopeURL: string, /* No description provided */
      [@key "isDeleted"]
      isDeleted: bool /* No description provided */,
    };
  } = {
    /* ServiceWorker registration. */
    [@deriving yojson]
    type t = {
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "scopeURL"]
      scopeURL: string, /* No description provided */
      [@key "isDeleted"]
      isDeleted: bool /* No description provided */,
    };
  }
  and ServiceWorkerVersionRunningStatus: {
    type _serviceworkerversionrunningstatus = [
      | `stopped
      | `starting
      | `running
      | `stopping
    ];
    let _serviceworkerversionrunningstatus_of_yojson:
      Yojson.Basic.t => _serviceworkerversionrunningstatus;
    let yojson_of__serviceworkerversionrunningstatus:
      _serviceworkerversionrunningstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _serviceworkerversionrunningstatus;
  } = {
    type _serviceworkerversionrunningstatus = [
      | `stopped
      | `starting
      | `running
      | `stopping
    ];
    let _serviceworkerversionrunningstatus_of_yojson =
      fun
      | `String("stopped") => `stopped
      | `String("starting") => `starting
      | `String("running") => `running
      | `String("stopping") => `stopping
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__serviceworkerversionrunningstatus =
      fun
      | `stopped => `String("stopped")
      | `starting => `String("starting")
      | `running => `String("running")
      | `stopping => `String("stopping");
    /* No description provided */
    [@deriving yojson]
    type t = _serviceworkerversionrunningstatus;
  }
  and ServiceWorkerVersionStatus: {
    type _serviceworkerversionstatus = [
      | `new_
      | `installing
      | `installed
      | `activating
      | `activated
      | `redundant
    ];
    let _serviceworkerversionstatus_of_yojson:
      Yojson.Basic.t => _serviceworkerversionstatus;
    let yojson_of__serviceworkerversionstatus:
      _serviceworkerversionstatus => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _serviceworkerversionstatus;
  } = {
    type _serviceworkerversionstatus = [
      | `new_
      | `installing
      | `installed
      | `activating
      | `activated
      | `redundant
    ];
    let _serviceworkerversionstatus_of_yojson =
      fun
      | `String("new") => `new_
      | `String("installing") => `installing
      | `String("installed") => `installed
      | `String("activating") => `activating
      | `String("activated") => `activated
      | `String("redundant") => `redundant
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__serviceworkerversionstatus =
      fun
      | `new_ => `String("new")
      | `installing => `String("installing")
      | `installed => `String("installed")
      | `activating => `String("activating")
      | `activated => `String("activated")
      | `redundant => `String("redundant");
    /* No description provided */
    [@deriving yojson]
    type t = _serviceworkerversionstatus;
  }
  and ServiceWorkerVersion: {
    /* ServiceWorker version. */
    [@deriving yojson]
    type t = {
      [@key "versionId"]
      versionId: string, /* No description provided */
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "scriptURL"]
      scriptURL: string, /* No description provided */
      [@key "runningStatus"]
      runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
      [@key "status"]
      status: ServiceWorkerVersionStatus.t, /* No description provided */
      [@yojson.option] [@key "scriptLastModified"]
      scriptLastModified: option(float), /* The Last-Modified header value of the main script. */
      [@yojson.option] [@key "scriptResponseTime"]
      scriptResponseTime: option(float), /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
      [@yojson.option] [@key "controlledClients"]
      controlledClients: option(list(Target.TargetID.t)), /* No description provided */
      [@yojson.option] [@key "targetId"]
      targetId: option(Target.TargetID.t) /* No description provided */,
    };
  } = {
    /* ServiceWorker version. */
    [@deriving yojson]
    type t = {
      [@key "versionId"]
      versionId: string, /* No description provided */
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "scriptURL"]
      scriptURL: string, /* No description provided */
      [@key "runningStatus"]
      runningStatus: ServiceWorkerVersionRunningStatus.t, /* No description provided */
      [@key "status"]
      status: ServiceWorkerVersionStatus.t, /* No description provided */
      [@yojson.option] [@key "scriptLastModified"]
      scriptLastModified: option(float), /* The Last-Modified header value of the main script. */
      [@yojson.option] [@key "scriptResponseTime"]
      scriptResponseTime: option(float), /* The time at which the response headers of the main script were received from the server.
For cached script it is the last time the cache entry was validated. */
      [@yojson.option] [@key "controlledClients"]
      controlledClients: option(list(Target.TargetID.t)), /* No description provided */
      [@yojson.option] [@key "targetId"]
      targetId: option(Target.TargetID.t) /* No description provided */,
    };
  }
  and ServiceWorkerErrorMessage: {
    /* ServiceWorker error message. */
    [@deriving yojson]
    type t = {
      [@key "errorMessage"]
      errorMessage: string, /* No description provided */
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "versionId"]
      versionId: string, /* No description provided */
      [@key "sourceURL"]
      sourceURL: string, /* No description provided */
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  } = {
    /* ServiceWorker error message. */
    [@deriving yojson]
    type t = {
      [@key "errorMessage"]
      errorMessage: string, /* No description provided */
      [@key "registrationId"]
      registrationId: RegistrationID.t, /* No description provided */
      [@key "versionId"]
      versionId: string, /* No description provided */
      [@key "sourceURL"]
      sourceURL: string, /* No description provided */
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  };
}
and Storage: {
  module rec StorageType: {
    type _storagetype = [
      | `appcache
      | `cookies
      | `file_systems
      | `indexeddb
      | `local_storage
      | `shader_cache
      | `websql
      | `service_workers
      | `cache_storage
      | `all
      | `other
    ];
    let _storagetype_of_yojson: Yojson.Basic.t => _storagetype;
    let yojson_of__storagetype: _storagetype => Yojson.Basic.t;
    /* Enum of possible storage types. */
    [@deriving yojson]
    type t = _storagetype;
  }
  and UsageForType: {
    /* Usage for a storage type. */
    [@deriving yojson]
    type t = {
      [@key "storageType"]
      storageType: StorageType.t, /* Name of storage type. */
      [@key "usage"]
      usage: float /* Storage usage (bytes). */,
    };
  }
  and TrustTokens: {
    /* Pair of issuer origin and number of available (signed, but not used) Trust
       Tokens from that issuer. */
    [@deriving yojson]
    type t = {
      [@key "issuerOrigin"]
      issuerOrigin: string, /* No description provided */
      [@key "count"]
      count: float /* No description provided */,
    };
  };
} = {
  module rec StorageType: {
    type _storagetype = [
      | `appcache
      | `cookies
      | `file_systems
      | `indexeddb
      | `local_storage
      | `shader_cache
      | `websql
      | `service_workers
      | `cache_storage
      | `all
      | `other
    ];
    let _storagetype_of_yojson: Yojson.Basic.t => _storagetype;
    let yojson_of__storagetype: _storagetype => Yojson.Basic.t;
    /* Enum of possible storage types. */
    [@deriving yojson]
    type t = _storagetype;
  } = {
    type _storagetype = [
      | `appcache
      | `cookies
      | `file_systems
      | `indexeddb
      | `local_storage
      | `shader_cache
      | `websql
      | `service_workers
      | `cache_storage
      | `all
      | `other
    ];
    let _storagetype_of_yojson =
      fun
      | `String("appcache") => `appcache
      | `String("cookies") => `cookies
      | `String("file_systems") => `file_systems
      | `String("indexeddb") => `indexeddb
      | `String("local_storage") => `local_storage
      | `String("shader_cache") => `shader_cache
      | `String("websql") => `websql
      | `String("service_workers") => `service_workers
      | `String("cache_storage") => `cache_storage
      | `String("all") => `all
      | `String("other") => `other
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__storagetype =
      fun
      | `appcache => `String("appcache")
      | `cookies => `String("cookies")
      | `file_systems => `String("file_systems")
      | `indexeddb => `String("indexeddb")
      | `local_storage => `String("local_storage")
      | `shader_cache => `String("shader_cache")
      | `websql => `String("websql")
      | `service_workers => `String("service_workers")
      | `cache_storage => `String("cache_storage")
      | `all => `String("all")
      | `other => `String("other");
    /* Enum of possible storage types. */
    [@deriving yojson]
    type t = _storagetype;
  }
  and UsageForType: {
    /* Usage for a storage type. */
    [@deriving yojson]
    type t = {
      [@key "storageType"]
      storageType: StorageType.t, /* Name of storage type. */
      [@key "usage"]
      usage: float /* Storage usage (bytes). */,
    };
  } = {
    /* Usage for a storage type. */
    [@deriving yojson]
    type t = {
      [@key "storageType"]
      storageType: StorageType.t, /* Name of storage type. */
      [@key "usage"]
      usage: float /* Storage usage (bytes). */,
    };
  }
  and TrustTokens: {
    /* Pair of issuer origin and number of available (signed, but not used) Trust
       Tokens from that issuer. */
    [@deriving yojson]
    type t = {
      [@key "issuerOrigin"]
      issuerOrigin: string, /* No description provided */
      [@key "count"]
      count: float /* No description provided */,
    };
  } = {
    /* Pair of issuer origin and number of available (signed, but not used) Trust
       Tokens from that issuer. */
    [@deriving yojson]
    type t = {
      [@key "issuerOrigin"]
      issuerOrigin: string, /* No description provided */
      [@key "count"]
      count: float /* No description provided */,
    };
  };
}
and SystemInfo: {
  module rec GPUDevice: {
    /* Describes a single graphics processor (GPU). */
    [@deriving yojson]
    type t = {
      [@key "vendorId"]
      vendorId: float, /* PCI ID of the GPU vendor, if available; 0 otherwise. */
      [@key "deviceId"]
      deviceId: float, /* PCI ID of the GPU device, if available; 0 otherwise. */
      [@yojson.option] [@key "subSysId"]
      subSysId: option(float), /* Sub sys ID of the GPU, only available on Windows. */
      [@yojson.option] [@key "revision"]
      revision: option(float), /* Revision of the GPU, only available on Windows. */
      [@key "vendorString"]
      vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
      [@key "deviceString"]
      deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
      [@key "driverVendor"]
      driverVendor: string, /* String description of the GPU driver vendor. */
      [@key "driverVersion"]
      driverVersion: string /* String description of the GPU driver version. */,
    };
  }
  and Size: {
    /* Describes the width and height dimensions of an entity. */
    [@deriving yojson]
    type t = {
      [@key "width"]
      width: float, /* Width in pixels. */
      [@key "height"]
      height: float /* Height in pixels. */,
    };
  }
  and VideoDecodeAcceleratorCapability: {
    /* Describes a supported video decoding profile with its associated minimum and
       maximum resolutions. */
    [@deriving yojson]
    type t = {
      [@key "profile"]
      profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
      [@key "maxResolution"]
      maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
      [@key "minResolution"]
      minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
    };
  }
  and VideoEncodeAcceleratorCapability: {
    /* Describes a supported video encoding profile with its associated maximum
       resolution and maximum framerate. */
    [@deriving yojson]
    type t = {
      [@key "profile"]
      profile: string, /* Video codec profile that is supported, e.g H264 Main. */
      [@key "maxResolution"]
      maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
      [@key "maxFramerateNumerator"]
      maxFramerateNumerator: float, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
      [@key "maxFramerateDenominator"]
      maxFramerateDenominator: float /* No description provided */,
    };
  }
  and SubsamplingFormat: {
    type _subsamplingformat = [ | `yuv420 | `yuv422 | `yuv444];
    let _subsamplingformat_of_yojson: Yojson.Basic.t => _subsamplingformat;
    let yojson_of__subsamplingformat: _subsamplingformat => Yojson.Basic.t;
    /* YUV subsampling type of the pixels of a given image. */
    [@deriving yojson]
    type t = _subsamplingformat;
  }
  and ImageType: {
    type _imagetype = [ | `jpeg | `webp | `unknown];
    let _imagetype_of_yojson: Yojson.Basic.t => _imagetype;
    let yojson_of__imagetype: _imagetype => Yojson.Basic.t;
    /* Image format of a given image. */
    [@deriving yojson]
    type t = _imagetype;
  }
  and ImageDecodeAcceleratorCapability: {
    /* Describes a supported image decoding profile with its associated minimum and
       maximum resolutions and subsampling. */
    [@deriving yojson]
    type t = {
      [@key "imageType"]
      imageType: ImageType.t, /* Image coded, e.g. Jpeg. */
      [@key "maxDimensions"]
      maxDimensions: Size.t, /* Maximum supported dimensions of the image in pixels. */
      [@key "minDimensions"]
      minDimensions: Size.t, /* Minimum supported dimensions of the image in pixels. */
      [@key "subsamplings"]
      subsamplings: list(SubsamplingFormat.t) /* Optional array of supported subsampling formats, e.g. 4:2:0, if known. */,
    };
  }
  and GPUInfo: {
    /* Provides information about the GPU(s) on the system. */
    [@deriving yojson]
    type t = {
      [@key "devices"]
      devices: list(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
      [@yojson.option] [@key "auxAttributes"]
      auxAttributes: option(assoc), /* An optional dictionary of additional GPU related attributes. */
      [@yojson.option] [@key "featureStatus"]
      featureStatus: option(assoc), /* An optional dictionary of graphics features and their status. */
      [@key "driverBugWorkarounds"]
      driverBugWorkarounds: list(string), /* An optional array of GPU driver bug workarounds. */
      [@key "videoDecoding"]
      videoDecoding: list(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
      [@key "videoEncoding"]
      videoEncoding: list(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
      [@key "imageDecoding"]
      imageDecoding: list(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
    };
  }
  and ProcessInfo: {
    /* Represents process info. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: string, /* Specifies process type. */
      [@key "id"]
      id: float, /* Specifies process id. */
      [@key "cpuTime"]
      cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
    };
  };
} = {
  module rec GPUDevice: {
    /* Describes a single graphics processor (GPU). */
    [@deriving yojson]
    type t = {
      [@key "vendorId"]
      vendorId: float, /* PCI ID of the GPU vendor, if available; 0 otherwise. */
      [@key "deviceId"]
      deviceId: float, /* PCI ID of the GPU device, if available; 0 otherwise. */
      [@yojson.option] [@key "subSysId"]
      subSysId: option(float), /* Sub sys ID of the GPU, only available on Windows. */
      [@yojson.option] [@key "revision"]
      revision: option(float), /* Revision of the GPU, only available on Windows. */
      [@key "vendorString"]
      vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
      [@key "deviceString"]
      deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
      [@key "driverVendor"]
      driverVendor: string, /* String description of the GPU driver vendor. */
      [@key "driverVersion"]
      driverVersion: string /* String description of the GPU driver version. */,
    };
  } = {
    /* Describes a single graphics processor (GPU). */
    [@deriving yojson]
    type t = {
      [@key "vendorId"]
      vendorId: float, /* PCI ID of the GPU vendor, if available; 0 otherwise. */
      [@key "deviceId"]
      deviceId: float, /* PCI ID of the GPU device, if available; 0 otherwise. */
      [@yojson.option] [@key "subSysId"]
      subSysId: option(float), /* Sub sys ID of the GPU, only available on Windows. */
      [@yojson.option] [@key "revision"]
      revision: option(float), /* Revision of the GPU, only available on Windows. */
      [@key "vendorString"]
      vendorString: string, /* String description of the GPU vendor, if the PCI ID is not available. */
      [@key "deviceString"]
      deviceString: string, /* String description of the GPU device, if the PCI ID is not available. */
      [@key "driverVendor"]
      driverVendor: string, /* String description of the GPU driver vendor. */
      [@key "driverVersion"]
      driverVersion: string /* String description of the GPU driver version. */,
    };
  }
  and Size: {
    /* Describes the width and height dimensions of an entity. */
    [@deriving yojson]
    type t = {
      [@key "width"]
      width: float, /* Width in pixels. */
      [@key "height"]
      height: float /* Height in pixels. */,
    };
  } = {
    /* Describes the width and height dimensions of an entity. */
    [@deriving yojson]
    type t = {
      [@key "width"]
      width: float, /* Width in pixels. */
      [@key "height"]
      height: float /* Height in pixels. */,
    };
  }
  and VideoDecodeAcceleratorCapability: {
    /* Describes a supported video decoding profile with its associated minimum and
       maximum resolutions. */
    [@deriving yojson]
    type t = {
      [@key "profile"]
      profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
      [@key "maxResolution"]
      maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
      [@key "minResolution"]
      minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
    };
  } = {
    /* Describes a supported video decoding profile with its associated minimum and
       maximum resolutions. */
    [@deriving yojson]
    type t = {
      [@key "profile"]
      profile: string, /* Video codec profile that is supported, e.g. VP9 Profile 2. */
      [@key "maxResolution"]
      maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
      [@key "minResolution"]
      minResolution: Size.t /* Minimum video dimensions in pixels supported for this |profile|. */,
    };
  }
  and VideoEncodeAcceleratorCapability: {
    /* Describes a supported video encoding profile with its associated maximum
       resolution and maximum framerate. */
    [@deriving yojson]
    type t = {
      [@key "profile"]
      profile: string, /* Video codec profile that is supported, e.g H264 Main. */
      [@key "maxResolution"]
      maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
      [@key "maxFramerateNumerator"]
      maxFramerateNumerator: float, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
      [@key "maxFramerateDenominator"]
      maxFramerateDenominator: float /* No description provided */,
    };
  } = {
    /* Describes a supported video encoding profile with its associated maximum
       resolution and maximum framerate. */
    [@deriving yojson]
    type t = {
      [@key "profile"]
      profile: string, /* Video codec profile that is supported, e.g H264 Main. */
      [@key "maxResolution"]
      maxResolution: Size.t, /* Maximum video dimensions in pixels supported for this |profile|. */
      [@key "maxFramerateNumerator"]
      maxFramerateNumerator: float, /* Maximum encoding framerate in frames per second supported for this
|profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
24000/1001 fps, etc. */
      [@key "maxFramerateDenominator"]
      maxFramerateDenominator: float /* No description provided */,
    };
  }
  and SubsamplingFormat: {
    type _subsamplingformat = [ | `yuv420 | `yuv422 | `yuv444];
    let _subsamplingformat_of_yojson: Yojson.Basic.t => _subsamplingformat;
    let yojson_of__subsamplingformat: _subsamplingformat => Yojson.Basic.t;
    /* YUV subsampling type of the pixels of a given image. */
    [@deriving yojson]
    type t = _subsamplingformat;
  } = {
    type _subsamplingformat = [ | `yuv420 | `yuv422 | `yuv444];
    let _subsamplingformat_of_yojson =
      fun
      | `String("yuv420") => `yuv420
      | `String("yuv422") => `yuv422
      | `String("yuv444") => `yuv444
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__subsamplingformat =
      fun
      | `yuv420 => `String("yuv420")
      | `yuv422 => `String("yuv422")
      | `yuv444 => `String("yuv444");
    /* YUV subsampling type of the pixels of a given image. */
    [@deriving yojson]
    type t = _subsamplingformat;
  }
  and ImageType: {
    type _imagetype = [ | `jpeg | `webp | `unknown];
    let _imagetype_of_yojson: Yojson.Basic.t => _imagetype;
    let yojson_of__imagetype: _imagetype => Yojson.Basic.t;
    /* Image format of a given image. */
    [@deriving yojson]
    type t = _imagetype;
  } = {
    type _imagetype = [ | `jpeg | `webp | `unknown];
    let _imagetype_of_yojson =
      fun
      | `String("jpeg") => `jpeg
      | `String("webp") => `webp
      | `String("unknown") => `unknown
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__imagetype =
      fun
      | `jpeg => `String("jpeg")
      | `webp => `String("webp")
      | `unknown => `String("unknown");
    /* Image format of a given image. */
    [@deriving yojson]
    type t = _imagetype;
  }
  and ImageDecodeAcceleratorCapability: {
    /* Describes a supported image decoding profile with its associated minimum and
       maximum resolutions and subsampling. */
    [@deriving yojson]
    type t = {
      [@key "imageType"]
      imageType: ImageType.t, /* Image coded, e.g. Jpeg. */
      [@key "maxDimensions"]
      maxDimensions: Size.t, /* Maximum supported dimensions of the image in pixels. */
      [@key "minDimensions"]
      minDimensions: Size.t, /* Minimum supported dimensions of the image in pixels. */
      [@key "subsamplings"]
      subsamplings: list(SubsamplingFormat.t) /* Optional array of supported subsampling formats, e.g. 4:2:0, if known. */,
    };
  } = {
    /* Describes a supported image decoding profile with its associated minimum and
       maximum resolutions and subsampling. */
    [@deriving yojson]
    type t = {
      [@key "imageType"]
      imageType: ImageType.t, /* Image coded, e.g. Jpeg. */
      [@key "maxDimensions"]
      maxDimensions: Size.t, /* Maximum supported dimensions of the image in pixels. */
      [@key "minDimensions"]
      minDimensions: Size.t, /* Minimum supported dimensions of the image in pixels. */
      [@key "subsamplings"]
      subsamplings: list(SubsamplingFormat.t) /* Optional array of supported subsampling formats, e.g. 4:2:0, if known. */,
    };
  }
  and GPUInfo: {
    /* Provides information about the GPU(s) on the system. */
    [@deriving yojson]
    type t = {
      [@key "devices"]
      devices: list(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
      [@yojson.option] [@key "auxAttributes"]
      auxAttributes: option(assoc), /* An optional dictionary of additional GPU related attributes. */
      [@yojson.option] [@key "featureStatus"]
      featureStatus: option(assoc), /* An optional dictionary of graphics features and their status. */
      [@key "driverBugWorkarounds"]
      driverBugWorkarounds: list(string), /* An optional array of GPU driver bug workarounds. */
      [@key "videoDecoding"]
      videoDecoding: list(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
      [@key "videoEncoding"]
      videoEncoding: list(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
      [@key "imageDecoding"]
      imageDecoding: list(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
    };
  } = {
    /* Provides information about the GPU(s) on the system. */
    [@deriving yojson]
    type t = {
      [@key "devices"]
      devices: list(GPUDevice.t), /* The graphics devices on the system. Element 0 is the primary GPU. */
      [@yojson.option] [@key "auxAttributes"]
      auxAttributes: option(assoc), /* An optional dictionary of additional GPU related attributes. */
      [@yojson.option] [@key "featureStatus"]
      featureStatus: option(assoc), /* An optional dictionary of graphics features and their status. */
      [@key "driverBugWorkarounds"]
      driverBugWorkarounds: list(string), /* An optional array of GPU driver bug workarounds. */
      [@key "videoDecoding"]
      videoDecoding: list(VideoDecodeAcceleratorCapability.t), /* Supported accelerated video decoding capabilities. */
      [@key "videoEncoding"]
      videoEncoding: list(VideoEncodeAcceleratorCapability.t), /* Supported accelerated video encoding capabilities. */
      [@key "imageDecoding"]
      imageDecoding: list(ImageDecodeAcceleratorCapability.t) /* Supported accelerated image decoding capabilities. */,
    };
  }
  and ProcessInfo: {
    /* Represents process info. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: string, /* Specifies process type. */
      [@key "id"]
      id: float, /* Specifies process id. */
      [@key "cpuTime"]
      cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
    };
  } = {
    /* Represents process info. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: string, /* Specifies process type. */
      [@key "id"]
      id: float, /* Specifies process id. */
      [@key "cpuTime"]
      cpuTime: float /* Specifies cumulative CPU usage in seconds across all threads of the
process since the process start. */,
    };
  };
}
and Target: {
  module rec TargetID: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and SessionID: {
    /* Unique identifier of attached debugging session. */
    [@deriving yojson]
    type t = string;
  }
  and TargetInfo: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "targetId"]
      targetId: TargetID.t, /* No description provided */
      [@key "type"]
      type_: string, /* No description provided */
      [@key "title"]
      title: string, /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "attached"]
      attached: bool, /* Whether the target has an attached client. */
      [@yojson.option] [@key "openerId"]
      openerId: option(TargetID.t), /* Opener target Id */
      [@key "canAccessOpener"]
      canAccessOpener: bool, /* Whether the target has access to the originating window. */
      [@yojson.option] [@key "openerFrameId"]
      openerFrameId: option(Page.FrameId.t), /* Frame id of originating window (is only set if target has an opener). */
      [@yojson.option] [@key "browserContextId"]
      browserContextId: option(Browser.BrowserContextID.t) /* No description provided */,
    };
  }
  and RemoteLocation: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "host"]
      host: string, /* No description provided */
      [@key "port"]
      port: float /* No description provided */,
    };
  };
} = {
  module rec TargetID: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and SessionID: {
    /* Unique identifier of attached debugging session. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique identifier of attached debugging session. */
    [@deriving yojson]
    type t = string;
  }
  and TargetInfo: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "targetId"]
      targetId: TargetID.t, /* No description provided */
      [@key "type"]
      type_: string, /* No description provided */
      [@key "title"]
      title: string, /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "attached"]
      attached: bool, /* Whether the target has an attached client. */
      [@yojson.option] [@key "openerId"]
      openerId: option(TargetID.t), /* Opener target Id */
      [@key "canAccessOpener"]
      canAccessOpener: bool, /* Whether the target has access to the originating window. */
      [@yojson.option] [@key "openerFrameId"]
      openerFrameId: option(Page.FrameId.t), /* Frame id of originating window (is only set if target has an opener). */
      [@yojson.option] [@key "browserContextId"]
      browserContextId: option(Browser.BrowserContextID.t) /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "targetId"]
      targetId: TargetID.t, /* No description provided */
      [@key "type"]
      type_: string, /* No description provided */
      [@key "title"]
      title: string, /* No description provided */
      [@key "url"]
      url: string, /* No description provided */
      [@key "attached"]
      attached: bool, /* Whether the target has an attached client. */
      [@yojson.option] [@key "openerId"]
      openerId: option(TargetID.t), /* Opener target Id */
      [@key "canAccessOpener"]
      canAccessOpener: bool, /* Whether the target has access to the originating window. */
      [@yojson.option] [@key "openerFrameId"]
      openerFrameId: option(Page.FrameId.t), /* Frame id of originating window (is only set if target has an opener). */
      [@yojson.option] [@key "browserContextId"]
      browserContextId: option(Browser.BrowserContextID.t) /* No description provided */,
    };
  }
  and RemoteLocation: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "host"]
      host: string, /* No description provided */
      [@key "port"]
      port: float /* No description provided */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "host"]
      host: string, /* No description provided */
      [@key "port"]
      port: float /* No description provided */,
    };
  };
}
and Tracing: {
  module rec MemoryDumpConfig: {
    /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
    [@deriving yojson]
    type t = assoc;
  }
  and TraceConfig: {
    type _traceconfig_recordmode = [
      | `recordUntilFull
      | `recordContinuously
      | `recordAsMuchAsPossible
      | `echoToConsole
    ];
    let _traceconfig_recordmode_of_yojson:
      Yojson.Basic.t => _traceconfig_recordmode;
    let yojson_of__traceconfig_recordmode:
      _traceconfig_recordmode => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "recordMode"]
      recordMode: option(_traceconfig_recordmode), /* Controls how the trace buffer stores data. */
      [@yojson.option] [@key "enableSampling"]
      enableSampling: option(bool), /* Turns on JavaScript stack sampling. */
      [@yojson.option] [@key "enableSystrace"]
      enableSystrace: option(bool), /* Turns on system tracing. */
      [@yojson.option] [@key "enableArgumentFilter"]
      enableArgumentFilter: option(bool), /* Turns on argument filter. */
      [@yojson.option] [@key "includedCategories"]
      includedCategories: option(list(string)), /* Included category filters. */
      [@yojson.option] [@key "excludedCategories"]
      excludedCategories: option(list(string)), /* Excluded category filters. */
      [@yojson.option] [@key "syntheticDelays"]
      syntheticDelays: option(list(string)), /* Configuration to synthesize the delays in tracing. */
      [@yojson.option] [@key "memoryDumpConfig"]
      memoryDumpConfig: option(MemoryDumpConfig.t) /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
    };
  }
  and StreamFormat: {
    type _streamformat = [ | `json | `proto];
    let _streamformat_of_yojson: Yojson.Basic.t => _streamformat;
    let yojson_of__streamformat: _streamformat => Yojson.Basic.t;
    /* Data format of a trace. Can be either the legacy JSON format or the
       protocol buffer format. Note that the JSON format will be deprecated soon. */
    [@deriving yojson]
    type t = _streamformat;
  }
  and StreamCompression: {
    type _streamcompression = [ | `none | `gzip];
    let _streamcompression_of_yojson: Yojson.Basic.t => _streamcompression;
    let yojson_of__streamcompression: _streamcompression => Yojson.Basic.t;
    /* Compression type to use for traces returned via streams. */
    [@deriving yojson]
    type t = _streamcompression;
  }
  and MemoryDumpLevelOfDetail: {
    type _memorydumplevelofdetail = [ | `background | `light | `detailed];
    let _memorydumplevelofdetail_of_yojson:
      Yojson.Basic.t => _memorydumplevelofdetail;
    let yojson_of__memorydumplevelofdetail:
      _memorydumplevelofdetail => Yojson.Basic.t;
    /* Details exposed when memory request explicitly declared.
       Keep consistent with memory_dump_request_args.h and
       memory_instrumentation.mojom */
    [@deriving yojson]
    type t = _memorydumplevelofdetail;
  }
  and TracingBackend: {
    type _tracingbackend = [ | `auto | `chrome | `system];
    let _tracingbackend_of_yojson: Yojson.Basic.t => _tracingbackend;
    let yojson_of__tracingbackend: _tracingbackend => Yojson.Basic.t;
    /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
       tracing service and is supported on all platforms. `system` is only
       supported on Chrome OS and uses the Perfetto system tracing service.
       `auto` chooses `system` when the perfettoConfig provided to Tracing.start
       specifies at least one non-Chrome data source; otherwise uses `chrome`. */
    [@deriving yojson]
    type t = _tracingbackend;
  };
} = {
  module rec MemoryDumpConfig: {
    /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
    [@deriving yojson]
    type t = assoc;
  } = {
    /* Configuration for memory dump. Used only when "memory-infra" category is enabled. */
    [@deriving yojson]
    type t = assoc;
  }
  and TraceConfig: {
    type _traceconfig_recordmode = [
      | `recordUntilFull
      | `recordContinuously
      | `recordAsMuchAsPossible
      | `echoToConsole
    ];
    let _traceconfig_recordmode_of_yojson:
      Yojson.Basic.t => _traceconfig_recordmode;
    let yojson_of__traceconfig_recordmode:
      _traceconfig_recordmode => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "recordMode"]
      recordMode: option(_traceconfig_recordmode), /* Controls how the trace buffer stores data. */
      [@yojson.option] [@key "enableSampling"]
      enableSampling: option(bool), /* Turns on JavaScript stack sampling. */
      [@yojson.option] [@key "enableSystrace"]
      enableSystrace: option(bool), /* Turns on system tracing. */
      [@yojson.option] [@key "enableArgumentFilter"]
      enableArgumentFilter: option(bool), /* Turns on argument filter. */
      [@yojson.option] [@key "includedCategories"]
      includedCategories: option(list(string)), /* Included category filters. */
      [@yojson.option] [@key "excludedCategories"]
      excludedCategories: option(list(string)), /* Excluded category filters. */
      [@yojson.option] [@key "syntheticDelays"]
      syntheticDelays: option(list(string)), /* Configuration to synthesize the delays in tracing. */
      [@yojson.option] [@key "memoryDumpConfig"]
      memoryDumpConfig: option(MemoryDumpConfig.t) /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
    };
  } = {
    type _traceconfig_recordmode = [
      | `recordUntilFull
      | `recordContinuously
      | `recordAsMuchAsPossible
      | `echoToConsole
    ];
    let _traceconfig_recordmode_of_yojson =
      fun
      | `String("recordUntilFull") => `recordUntilFull
      | `String("recordContinuously") => `recordContinuously
      | `String("recordAsMuchAsPossible") => `recordAsMuchAsPossible
      | `String("echoToConsole") => `echoToConsole
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__traceconfig_recordmode =
      fun
      | `recordUntilFull => `String("recordUntilFull")
      | `recordContinuously => `String("recordContinuously")
      | `recordAsMuchAsPossible => `String("recordAsMuchAsPossible")
      | `echoToConsole => `String("echoToConsole");
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "recordMode"]
      recordMode: option(_traceconfig_recordmode), /* Controls how the trace buffer stores data. */
      [@yojson.option] [@key "enableSampling"]
      enableSampling: option(bool), /* Turns on JavaScript stack sampling. */
      [@yojson.option] [@key "enableSystrace"]
      enableSystrace: option(bool), /* Turns on system tracing. */
      [@yojson.option] [@key "enableArgumentFilter"]
      enableArgumentFilter: option(bool), /* Turns on argument filter. */
      [@yojson.option] [@key "includedCategories"]
      includedCategories: option(list(string)), /* Included category filters. */
      [@yojson.option] [@key "excludedCategories"]
      excludedCategories: option(list(string)), /* Excluded category filters. */
      [@yojson.option] [@key "syntheticDelays"]
      syntheticDelays: option(list(string)), /* Configuration to synthesize the delays in tracing. */
      [@yojson.option] [@key "memoryDumpConfig"]
      memoryDumpConfig: option(MemoryDumpConfig.t) /* Configuration for memory dump triggers. Used only when "memory-infra" category is enabled. */,
    };
  }
  and StreamFormat: {
    type _streamformat = [ | `json | `proto];
    let _streamformat_of_yojson: Yojson.Basic.t => _streamformat;
    let yojson_of__streamformat: _streamformat => Yojson.Basic.t;
    /* Data format of a trace. Can be either the legacy JSON format or the
       protocol buffer format. Note that the JSON format will be deprecated soon. */
    [@deriving yojson]
    type t = _streamformat;
  } = {
    type _streamformat = [ | `json | `proto];
    let _streamformat_of_yojson =
      fun
      | `String("json") => `json
      | `String("proto") => `proto
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__streamformat =
      fun
      | `json => `String("json")
      | `proto => `String("proto");
    /* Data format of a trace. Can be either the legacy JSON format or the
       protocol buffer format. Note that the JSON format will be deprecated soon. */
    [@deriving yojson]
    type t = _streamformat;
  }
  and StreamCompression: {
    type _streamcompression = [ | `none | `gzip];
    let _streamcompression_of_yojson: Yojson.Basic.t => _streamcompression;
    let yojson_of__streamcompression: _streamcompression => Yojson.Basic.t;
    /* Compression type to use for traces returned via streams. */
    [@deriving yojson]
    type t = _streamcompression;
  } = {
    type _streamcompression = [ | `none | `gzip];
    let _streamcompression_of_yojson =
      fun
      | `String("none") => `none
      | `String("gzip") => `gzip
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__streamcompression =
      fun
      | `none => `String("none")
      | `gzip => `String("gzip");
    /* Compression type to use for traces returned via streams. */
    [@deriving yojson]
    type t = _streamcompression;
  }
  and MemoryDumpLevelOfDetail: {
    type _memorydumplevelofdetail = [ | `background | `light | `detailed];
    let _memorydumplevelofdetail_of_yojson:
      Yojson.Basic.t => _memorydumplevelofdetail;
    let yojson_of__memorydumplevelofdetail:
      _memorydumplevelofdetail => Yojson.Basic.t;
    /* Details exposed when memory request explicitly declared.
       Keep consistent with memory_dump_request_args.h and
       memory_instrumentation.mojom */
    [@deriving yojson]
    type t = _memorydumplevelofdetail;
  } = {
    type _memorydumplevelofdetail = [ | `background | `light | `detailed];
    let _memorydumplevelofdetail_of_yojson =
      fun
      | `String("background") => `background
      | `String("light") => `light
      | `String("detailed") => `detailed
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__memorydumplevelofdetail =
      fun
      | `background => `String("background")
      | `light => `String("light")
      | `detailed => `String("detailed");
    /* Details exposed when memory request explicitly declared.
       Keep consistent with memory_dump_request_args.h and
       memory_instrumentation.mojom */
    [@deriving yojson]
    type t = _memorydumplevelofdetail;
  }
  and TracingBackend: {
    type _tracingbackend = [ | `auto | `chrome | `system];
    let _tracingbackend_of_yojson: Yojson.Basic.t => _tracingbackend;
    let yojson_of__tracingbackend: _tracingbackend => Yojson.Basic.t;
    /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
       tracing service and is supported on all platforms. `system` is only
       supported on Chrome OS and uses the Perfetto system tracing service.
       `auto` chooses `system` when the perfettoConfig provided to Tracing.start
       specifies at least one non-Chrome data source; otherwise uses `chrome`. */
    [@deriving yojson]
    type t = _tracingbackend;
  } = {
    type _tracingbackend = [ | `auto | `chrome | `system];
    let _tracingbackend_of_yojson =
      fun
      | `String("auto") => `auto
      | `String("chrome") => `chrome
      | `String("system") => `system
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__tracingbackend =
      fun
      | `auto => `String("auto")
      | `chrome => `String("chrome")
      | `system => `String("system");
    /* Backend type to use for tracing. `chrome` uses the Chrome-integrated
       tracing service and is supported on all platforms. `system` is only
       supported on Chrome OS and uses the Perfetto system tracing service.
       `auto` chooses `system` when the perfettoConfig provided to Tracing.start
       specifies at least one non-Chrome data source; otherwise uses `chrome`. */
    [@deriving yojson]
    type t = _tracingbackend;
  };
}
and Fetch: {
  module rec RequestId: {
    /* Unique request identifier. */
    [@deriving yojson]
    type t = string;
  }
  and RequestStage: {
    type _requeststage = [ | `Request | `Response];
    let _requeststage_of_yojson: Yojson.Basic.t => _requeststage;
    let yojson_of__requeststage: _requeststage => Yojson.Basic.t;
    /* Stages of the request to handle. Request will intercept before the request is
       sent. Response will intercept after the response is received (but before response
       body is received). */
    [@deriving yojson]
    type t = _requeststage;
  }
  and RequestPattern: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "urlPattern"]
      urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
      [@yojson.option] [@key "resourceType"]
      resourceType: option(Network.ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
      [@yojson.option] [@key "requestStage"]
      requestStage: option(RequestStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
    };
  }
  and HeaderEntry: {
    /* Response HTTP header entry */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and AuthChallenge: {
    type _authchallenge_source = [ | `Server | `Proxy];
    let _authchallenge_source_of_yojson:
      Yojson.Basic.t => _authchallenge_source;
    let yojson_of__authchallenge_source:
      _authchallenge_source => Yojson.Basic.t;
    /* Authorization challenge for HTTP status code 401 or 407. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "source"]
      source: option(_authchallenge_source), /* Source of the authentication challenge. */
      [@key "origin"]
      origin: string, /* Origin of the challenger. */
      [@key "scheme"]
      scheme: string, /* The authentication scheme used, such as basic or digest */
      [@key "realm"]
      realm: string /* The realm of the challenge. May be empty. */,
    };
  }
  and AuthChallengeResponse: {
    type _authchallengeresponse_response = [
      | `Default
      | `CancelAuth
      | `ProvideCredentials
    ];
    let _authchallengeresponse_response_of_yojson:
      Yojson.Basic.t => _authchallengeresponse_response;
    let yojson_of__authchallengeresponse_response:
      _authchallengeresponse_response => Yojson.Basic.t;
    /* Response to an AuthChallenge. */
    [@deriving yojson]
    type t = {
      [@key "response"]
      response: _authchallengeresponse_response, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
      [@yojson.option] [@key "username"]
      username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
      [@yojson.option] [@key "password"]
      password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
    };
  };
} = {
  module rec RequestId: {
    /* Unique request identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique request identifier. */
    [@deriving yojson]
    type t = string;
  }
  and RequestStage: {
    type _requeststage = [ | `Request | `Response];
    let _requeststage_of_yojson: Yojson.Basic.t => _requeststage;
    let yojson_of__requeststage: _requeststage => Yojson.Basic.t;
    /* Stages of the request to handle. Request will intercept before the request is
       sent. Response will intercept after the response is received (but before response
       body is received). */
    [@deriving yojson]
    type t = _requeststage;
  } = {
    type _requeststage = [ | `Request | `Response];
    let _requeststage_of_yojson =
      fun
      | `String("Request") => `Request
      | `String("Response") => `Response
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__requeststage =
      fun
      | `Request => `String("Request")
      | `Response => `String("Response");
    /* Stages of the request to handle. Request will intercept before the request is
       sent. Response will intercept after the response is received (but before response
       body is received). */
    [@deriving yojson]
    type t = _requeststage;
  }
  and RequestPattern: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "urlPattern"]
      urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
      [@yojson.option] [@key "resourceType"]
      resourceType: option(Network.ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
      [@yojson.option] [@key "requestStage"]
      requestStage: option(RequestStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "urlPattern"]
      urlPattern: option(string), /* Wildcards (`'*'` -> zero or more, `'?'` -> exactly one) are allowed. Escape character is
backslash. Omitting is equivalent to `"*"`. */
      [@yojson.option] [@key "resourceType"]
      resourceType: option(Network.ResourceType.t), /* If set, only requests for matching resource types will be intercepted. */
      [@yojson.option] [@key "requestStage"]
      requestStage: option(RequestStage.t) /* Stage at which to begin intercepting requests. Default is Request. */,
    };
  }
  and HeaderEntry: {
    /* Response HTTP header entry */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  } = {
    /* Response HTTP header entry */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and AuthChallenge: {
    type _authchallenge_source = [ | `Server | `Proxy];
    let _authchallenge_source_of_yojson:
      Yojson.Basic.t => _authchallenge_source;
    let yojson_of__authchallenge_source:
      _authchallenge_source => Yojson.Basic.t;
    /* Authorization challenge for HTTP status code 401 or 407. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "source"]
      source: option(_authchallenge_source), /* Source of the authentication challenge. */
      [@key "origin"]
      origin: string, /* Origin of the challenger. */
      [@key "scheme"]
      scheme: string, /* The authentication scheme used, such as basic or digest */
      [@key "realm"]
      realm: string /* The realm of the challenge. May be empty. */,
    };
  } = {
    type _authchallenge_source = [ | `Server | `Proxy];
    let _authchallenge_source_of_yojson =
      fun
      | `String("Server") => `Server
      | `String("Proxy") => `Proxy
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__authchallenge_source =
      fun
      | `Server => `String("Server")
      | `Proxy => `String("Proxy");
    /* Authorization challenge for HTTP status code 401 or 407. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "source"]
      source: option(_authchallenge_source), /* Source of the authentication challenge. */
      [@key "origin"]
      origin: string, /* Origin of the challenger. */
      [@key "scheme"]
      scheme: string, /* The authentication scheme used, such as basic or digest */
      [@key "realm"]
      realm: string /* The realm of the challenge. May be empty. */,
    };
  }
  and AuthChallengeResponse: {
    type _authchallengeresponse_response = [
      | `Default
      | `CancelAuth
      | `ProvideCredentials
    ];
    let _authchallengeresponse_response_of_yojson:
      Yojson.Basic.t => _authchallengeresponse_response;
    let yojson_of__authchallengeresponse_response:
      _authchallengeresponse_response => Yojson.Basic.t;
    /* Response to an AuthChallenge. */
    [@deriving yojson]
    type t = {
      [@key "response"]
      response: _authchallengeresponse_response, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
      [@yojson.option] [@key "username"]
      username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
      [@yojson.option] [@key "password"]
      password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
    };
  } = {
    type _authchallengeresponse_response = [
      | `Default
      | `CancelAuth
      | `ProvideCredentials
    ];
    let _authchallengeresponse_response_of_yojson =
      fun
      | `String("Default") => `Default
      | `String("CancelAuth") => `CancelAuth
      | `String("ProvideCredentials") => `ProvideCredentials
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__authchallengeresponse_response =
      fun
      | `Default => `String("Default")
      | `CancelAuth => `String("CancelAuth")
      | `ProvideCredentials => `String("ProvideCredentials");
    /* Response to an AuthChallenge. */
    [@deriving yojson]
    type t = {
      [@key "response"]
      response: _authchallengeresponse_response, /* The decision on what to do in response to the authorization challenge.  Default means
deferring to the default behavior of the net stack, which will likely either the Cancel
authentication or display a popup dialog box. */
      [@yojson.option] [@key "username"]
      username: option(string), /* The username to provide, possibly empty. Should only be set if response is
ProvideCredentials. */
      [@yojson.option] [@key "password"]
      password: option(string) /* The password to provide, possibly empty. Should only be set if response is
ProvideCredentials. */,
    };
  };
}
and WebAudio: {
  module rec GraphObjectId: {
    /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
    [@deriving yojson]
    type t = string;
  }
  and ContextType: {
    type _contexttype = [ | `realtime | `offline];
    let _contexttype_of_yojson: Yojson.Basic.t => _contexttype;
    let yojson_of__contexttype: _contexttype => Yojson.Basic.t;
    /* Enum of BaseAudioContext types */
    [@deriving yojson]
    type t = _contexttype;
  }
  and ContextState: {
    type _contextstate = [ | `suspended | `running | `closed];
    let _contextstate_of_yojson: Yojson.Basic.t => _contextstate;
    let yojson_of__contextstate: _contextstate => Yojson.Basic.t;
    /* Enum of AudioContextState from the spec */
    [@deriving yojson]
    type t = _contextstate;
  }
  and NodeType: {
    /* Enum of AudioNode types */
    [@deriving yojson]
    type t = string;
  }
  and ChannelCountMode: {
    type _channelcountmode = [ | `clamped_max | `explicit | `max];
    let _channelcountmode_of_yojson: Yojson.Basic.t => _channelcountmode;
    let yojson_of__channelcountmode: _channelcountmode => Yojson.Basic.t;
    /* Enum of AudioNode::ChannelCountMode from the spec */
    [@deriving yojson]
    type t = _channelcountmode;
  }
  and ChannelInterpretation: {
    type _channelinterpretation = [ | `discrete | `speakers];
    let _channelinterpretation_of_yojson:
      Yojson.Basic.t => _channelinterpretation;
    let yojson_of__channelinterpretation:
      _channelinterpretation => Yojson.Basic.t;
    /* Enum of AudioNode::ChannelInterpretation from the spec */
    [@deriving yojson]
    type t = _channelinterpretation;
  }
  and ParamType: {
    /* Enum of AudioParam types */
    [@deriving yojson]
    type t = string;
  }
  and AutomationRate: {
    type _automationrate = [ | `a_rate | `k_rate];
    let _automationrate_of_yojson: Yojson.Basic.t => _automationrate;
    let yojson_of__automationrate: _automationrate => Yojson.Basic.t;
    /* Enum of AudioParam::AutomationRate from the spec */
    [@deriving yojson]
    type t = _automationrate;
  }
  and ContextRealtimeData: {
    /* Fields in AudioContext that change in real-time. */
    [@deriving yojson]
    type t = {
      [@key "currentTime"]
      currentTime: float, /* The current context time in second in BaseAudioContext. */
      [@key "renderCapacity"]
      renderCapacity: float, /* The time spent on rendering graph divided by render quantum duration,
and multiplied by 100. 100 means the audio renderer reached the full
capacity and glitch may occur. */
      [@key "callbackIntervalMean"]
      callbackIntervalMean: float, /* A running mean of callback interval. */
      [@key "callbackIntervalVariance"]
      callbackIntervalVariance: float /* A running variance of callback interval. */,
    };
  }
  and BaseAudioContext: {
    /* Protocol object for BaseAudioContext */
    [@deriving yojson]
    type t = {
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "contextType"]
      contextType: ContextType.t, /* No description provided */
      [@key "contextState"]
      contextState: ContextState.t, /* No description provided */
      [@yojson.option] [@key "realtimeData"]
      realtimeData: option(ContextRealtimeData.t), /* No description provided */
      [@key "callbackBufferSize"]
      callbackBufferSize: float, /* Platform-dependent callback buffer size. */
      [@key "maxOutputChannelCount"]
      maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
      [@key "sampleRate"]
      sampleRate: float /* Context sample rate. */,
    };
  }
  and AudioListener: {
    /* Protocol object for AudioListener */
    [@deriving yojson]
    type t = {
      [@key "listenerId"]
      listenerId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t /* No description provided */,
    };
  }
  and AudioNode: {
    /* Protocol object for AudioNode */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "nodeType"]
      nodeType: NodeType.t, /* No description provided */
      [@key "numberOfInputs"]
      numberOfInputs: float, /* No description provided */
      [@key "numberOfOutputs"]
      numberOfOutputs: float, /* No description provided */
      [@key "channelCount"]
      channelCount: float, /* No description provided */
      [@key "channelCountMode"]
      channelCountMode: ChannelCountMode.t, /* No description provided */
      [@key "channelInterpretation"]
      channelInterpretation: ChannelInterpretation.t /* No description provided */,
    };
  }
  and AudioParam: {
    /* Protocol object for AudioParam */
    [@deriving yojson]
    type t = {
      [@key "paramId"]
      paramId: GraphObjectId.t, /* No description provided */
      [@key "nodeId"]
      nodeId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "paramType"]
      paramType: ParamType.t, /* No description provided */
      [@key "rate"]
      rate: AutomationRate.t, /* No description provided */
      [@key "defaultValue"]
      defaultValue: float, /* No description provided */
      [@key "minValue"]
      minValue: float, /* No description provided */
      [@key "maxValue"]
      maxValue: float /* No description provided */,
    };
  };
} = {
  module rec GraphObjectId: {
    /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
    [@deriving yojson]
    type t = string;
  } = {
    /* An unique ID for a graph object (AudioContext, AudioNode, AudioParam) in Web Audio API */
    [@deriving yojson]
    type t = string;
  }
  and ContextType: {
    type _contexttype = [ | `realtime | `offline];
    let _contexttype_of_yojson: Yojson.Basic.t => _contexttype;
    let yojson_of__contexttype: _contexttype => Yojson.Basic.t;
    /* Enum of BaseAudioContext types */
    [@deriving yojson]
    type t = _contexttype;
  } = {
    type _contexttype = [ | `realtime | `offline];
    let _contexttype_of_yojson =
      fun
      | `String("realtime") => `realtime
      | `String("offline") => `offline
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__contexttype =
      fun
      | `realtime => `String("realtime")
      | `offline => `String("offline");
    /* Enum of BaseAudioContext types */
    [@deriving yojson]
    type t = _contexttype;
  }
  and ContextState: {
    type _contextstate = [ | `suspended | `running | `closed];
    let _contextstate_of_yojson: Yojson.Basic.t => _contextstate;
    let yojson_of__contextstate: _contextstate => Yojson.Basic.t;
    /* Enum of AudioContextState from the spec */
    [@deriving yojson]
    type t = _contextstate;
  } = {
    type _contextstate = [ | `suspended | `running | `closed];
    let _contextstate_of_yojson =
      fun
      | `String("suspended") => `suspended
      | `String("running") => `running
      | `String("closed") => `closed
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__contextstate =
      fun
      | `suspended => `String("suspended")
      | `running => `String("running")
      | `closed => `String("closed");
    /* Enum of AudioContextState from the spec */
    [@deriving yojson]
    type t = _contextstate;
  }
  and NodeType: {
    /* Enum of AudioNode types */
    [@deriving yojson]
    type t = string;
  } = {
    /* Enum of AudioNode types */
    [@deriving yojson]
    type t = string;
  }
  and ChannelCountMode: {
    type _channelcountmode = [ | `clamped_max | `explicit | `max];
    let _channelcountmode_of_yojson: Yojson.Basic.t => _channelcountmode;
    let yojson_of__channelcountmode: _channelcountmode => Yojson.Basic.t;
    /* Enum of AudioNode::ChannelCountMode from the spec */
    [@deriving yojson]
    type t = _channelcountmode;
  } = {
    type _channelcountmode = [ | `clamped_max | `explicit | `max];
    let _channelcountmode_of_yojson =
      fun
      | `String("clamped-max") => `clamped_max
      | `String("explicit") => `explicit
      | `String("max") => `max
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__channelcountmode =
      fun
      | `clamped_max => `String("clamped-max")
      | `explicit => `String("explicit")
      | `max => `String("max");
    /* Enum of AudioNode::ChannelCountMode from the spec */
    [@deriving yojson]
    type t = _channelcountmode;
  }
  and ChannelInterpretation: {
    type _channelinterpretation = [ | `discrete | `speakers];
    let _channelinterpretation_of_yojson:
      Yojson.Basic.t => _channelinterpretation;
    let yojson_of__channelinterpretation:
      _channelinterpretation => Yojson.Basic.t;
    /* Enum of AudioNode::ChannelInterpretation from the spec */
    [@deriving yojson]
    type t = _channelinterpretation;
  } = {
    type _channelinterpretation = [ | `discrete | `speakers];
    let _channelinterpretation_of_yojson =
      fun
      | `String("discrete") => `discrete
      | `String("speakers") => `speakers
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__channelinterpretation =
      fun
      | `discrete => `String("discrete")
      | `speakers => `String("speakers");
    /* Enum of AudioNode::ChannelInterpretation from the spec */
    [@deriving yojson]
    type t = _channelinterpretation;
  }
  and ParamType: {
    /* Enum of AudioParam types */
    [@deriving yojson]
    type t = string;
  } = {
    /* Enum of AudioParam types */
    [@deriving yojson]
    type t = string;
  }
  and AutomationRate: {
    type _automationrate = [ | `a_rate | `k_rate];
    let _automationrate_of_yojson: Yojson.Basic.t => _automationrate;
    let yojson_of__automationrate: _automationrate => Yojson.Basic.t;
    /* Enum of AudioParam::AutomationRate from the spec */
    [@deriving yojson]
    type t = _automationrate;
  } = {
    type _automationrate = [ | `a_rate | `k_rate];
    let _automationrate_of_yojson =
      fun
      | `String("a-rate") => `a_rate
      | `String("k-rate") => `k_rate
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__automationrate =
      fun
      | `a_rate => `String("a-rate")
      | `k_rate => `String("k-rate");
    /* Enum of AudioParam::AutomationRate from the spec */
    [@deriving yojson]
    type t = _automationrate;
  }
  and ContextRealtimeData: {
    /* Fields in AudioContext that change in real-time. */
    [@deriving yojson]
    type t = {
      [@key "currentTime"]
      currentTime: float, /* The current context time in second in BaseAudioContext. */
      [@key "renderCapacity"]
      renderCapacity: float, /* The time spent on rendering graph divided by render quantum duration,
and multiplied by 100. 100 means the audio renderer reached the full
capacity and glitch may occur. */
      [@key "callbackIntervalMean"]
      callbackIntervalMean: float, /* A running mean of callback interval. */
      [@key "callbackIntervalVariance"]
      callbackIntervalVariance: float /* A running variance of callback interval. */,
    };
  } = {
    /* Fields in AudioContext that change in real-time. */
    [@deriving yojson]
    type t = {
      [@key "currentTime"]
      currentTime: float, /* The current context time in second in BaseAudioContext. */
      [@key "renderCapacity"]
      renderCapacity: float, /* The time spent on rendering graph divided by render quantum duration,
and multiplied by 100. 100 means the audio renderer reached the full
capacity and glitch may occur. */
      [@key "callbackIntervalMean"]
      callbackIntervalMean: float, /* A running mean of callback interval. */
      [@key "callbackIntervalVariance"]
      callbackIntervalVariance: float /* A running variance of callback interval. */,
    };
  }
  and BaseAudioContext: {
    /* Protocol object for BaseAudioContext */
    [@deriving yojson]
    type t = {
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "contextType"]
      contextType: ContextType.t, /* No description provided */
      [@key "contextState"]
      contextState: ContextState.t, /* No description provided */
      [@yojson.option] [@key "realtimeData"]
      realtimeData: option(ContextRealtimeData.t), /* No description provided */
      [@key "callbackBufferSize"]
      callbackBufferSize: float, /* Platform-dependent callback buffer size. */
      [@key "maxOutputChannelCount"]
      maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
      [@key "sampleRate"]
      sampleRate: float /* Context sample rate. */,
    };
  } = {
    /* Protocol object for BaseAudioContext */
    [@deriving yojson]
    type t = {
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "contextType"]
      contextType: ContextType.t, /* No description provided */
      [@key "contextState"]
      contextState: ContextState.t, /* No description provided */
      [@yojson.option] [@key "realtimeData"]
      realtimeData: option(ContextRealtimeData.t), /* No description provided */
      [@key "callbackBufferSize"]
      callbackBufferSize: float, /* Platform-dependent callback buffer size. */
      [@key "maxOutputChannelCount"]
      maxOutputChannelCount: float, /* Number of output channels supported by audio hardware in use. */
      [@key "sampleRate"]
      sampleRate: float /* Context sample rate. */,
    };
  }
  and AudioListener: {
    /* Protocol object for AudioListener */
    [@deriving yojson]
    type t = {
      [@key "listenerId"]
      listenerId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t /* No description provided */,
    };
  } = {
    /* Protocol object for AudioListener */
    [@deriving yojson]
    type t = {
      [@key "listenerId"]
      listenerId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t /* No description provided */,
    };
  }
  and AudioNode: {
    /* Protocol object for AudioNode */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "nodeType"]
      nodeType: NodeType.t, /* No description provided */
      [@key "numberOfInputs"]
      numberOfInputs: float, /* No description provided */
      [@key "numberOfOutputs"]
      numberOfOutputs: float, /* No description provided */
      [@key "channelCount"]
      channelCount: float, /* No description provided */
      [@key "channelCountMode"]
      channelCountMode: ChannelCountMode.t, /* No description provided */
      [@key "channelInterpretation"]
      channelInterpretation: ChannelInterpretation.t /* No description provided */,
    };
  } = {
    /* Protocol object for AudioNode */
    [@deriving yojson]
    type t = {
      [@key "nodeId"]
      nodeId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "nodeType"]
      nodeType: NodeType.t, /* No description provided */
      [@key "numberOfInputs"]
      numberOfInputs: float, /* No description provided */
      [@key "numberOfOutputs"]
      numberOfOutputs: float, /* No description provided */
      [@key "channelCount"]
      channelCount: float, /* No description provided */
      [@key "channelCountMode"]
      channelCountMode: ChannelCountMode.t, /* No description provided */
      [@key "channelInterpretation"]
      channelInterpretation: ChannelInterpretation.t /* No description provided */,
    };
  }
  and AudioParam: {
    /* Protocol object for AudioParam */
    [@deriving yojson]
    type t = {
      [@key "paramId"]
      paramId: GraphObjectId.t, /* No description provided */
      [@key "nodeId"]
      nodeId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "paramType"]
      paramType: ParamType.t, /* No description provided */
      [@key "rate"]
      rate: AutomationRate.t, /* No description provided */
      [@key "defaultValue"]
      defaultValue: float, /* No description provided */
      [@key "minValue"]
      minValue: float, /* No description provided */
      [@key "maxValue"]
      maxValue: float /* No description provided */,
    };
  } = {
    /* Protocol object for AudioParam */
    [@deriving yojson]
    type t = {
      [@key "paramId"]
      paramId: GraphObjectId.t, /* No description provided */
      [@key "nodeId"]
      nodeId: GraphObjectId.t, /* No description provided */
      [@key "contextId"]
      contextId: GraphObjectId.t, /* No description provided */
      [@key "paramType"]
      paramType: ParamType.t, /* No description provided */
      [@key "rate"]
      rate: AutomationRate.t, /* No description provided */
      [@key "defaultValue"]
      defaultValue: float, /* No description provided */
      [@key "minValue"]
      minValue: float, /* No description provided */
      [@key "maxValue"]
      maxValue: float /* No description provided */,
    };
  };
}
and WebAuthn: {
  module rec AuthenticatorId: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and AuthenticatorProtocol: {
    type _authenticatorprotocol = [ | `u2f | `ctap2];
    let _authenticatorprotocol_of_yojson:
      Yojson.Basic.t => _authenticatorprotocol;
    let yojson_of__authenticatorprotocol:
      _authenticatorprotocol => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _authenticatorprotocol;
  }
  and Ctap2Version: {
    type _ctap2version = [ | `ctap2_0 | `ctap2_1];
    let _ctap2version_of_yojson: Yojson.Basic.t => _ctap2version;
    let yojson_of__ctap2version: _ctap2version => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _ctap2version;
  }
  and AuthenticatorTransport: {
    type _authenticatortransport = [
      | `usb
      | `nfc
      | `ble
      | `cable
      | `internal
    ];
    let _authenticatortransport_of_yojson:
      Yojson.Basic.t => _authenticatortransport;
    let yojson_of__authenticatortransport:
      _authenticatortransport => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _authenticatortransport;
  }
  and VirtualAuthenticatorOptions: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: AuthenticatorProtocol.t, /* No description provided */
      [@yojson.option] [@key "ctap2Version"]
      ctap2Version: option(Ctap2Version.t), /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
      [@key "transport"]
      transport: AuthenticatorTransport.t, /* No description provided */
      [@yojson.option] [@key "hasResidentKey"]
      hasResidentKey: option(bool), /* Defaults to false. */
      [@yojson.option] [@key "hasUserVerification"]
      hasUserVerification: option(bool), /* Defaults to false. */
      [@yojson.option] [@key "hasLargeBlob"]
      hasLargeBlob: option(bool), /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
      [@yojson.option] [@key "hasCredBlob"]
      hasCredBlob: option(bool), /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
      [@yojson.option] [@key "automaticPresenceSimulation"]
      automaticPresenceSimulation: option(bool), /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
      [@yojson.option] [@key "isUserVerified"]
      isUserVerified: option(bool) /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
    };
  }
  and Credential: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "credentialId"]
      credentialId: string, /* No description provided */
      [@key "isResidentCredential"]
      isResidentCredential: bool, /* No description provided */
      [@yojson.option] [@key "rpId"]
      rpId: option(string), /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
      [@key "privateKey"]
      privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option] [@key "userHandle"]
      userHandle: option(string), /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
      [@key "signCount"]
      signCount: float, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
      [@yojson.option] [@key "largeBlob"]
      largeBlob: option(string) /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
    };
  };
} = {
  module rec AuthenticatorId: {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = string;
  }
  and AuthenticatorProtocol: {
    type _authenticatorprotocol = [ | `u2f | `ctap2];
    let _authenticatorprotocol_of_yojson:
      Yojson.Basic.t => _authenticatorprotocol;
    let yojson_of__authenticatorprotocol:
      _authenticatorprotocol => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _authenticatorprotocol;
  } = {
    type _authenticatorprotocol = [ | `u2f | `ctap2];
    let _authenticatorprotocol_of_yojson =
      fun
      | `String("u2f") => `u2f
      | `String("ctap2") => `ctap2
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__authenticatorprotocol =
      fun
      | `u2f => `String("u2f")
      | `ctap2 => `String("ctap2");
    /* No description provided */
    [@deriving yojson]
    type t = _authenticatorprotocol;
  }
  and Ctap2Version: {
    type _ctap2version = [ | `ctap2_0 | `ctap2_1];
    let _ctap2version_of_yojson: Yojson.Basic.t => _ctap2version;
    let yojson_of__ctap2version: _ctap2version => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _ctap2version;
  } = {
    type _ctap2version = [ | `ctap2_0 | `ctap2_1];
    let _ctap2version_of_yojson =
      fun
      | `String("ctap2_0") => `ctap2_0
      | `String("ctap2_1") => `ctap2_1
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__ctap2version =
      fun
      | `ctap2_0 => `String("ctap2_0")
      | `ctap2_1 => `String("ctap2_1");
    /* No description provided */
    [@deriving yojson]
    type t = _ctap2version;
  }
  and AuthenticatorTransport: {
    type _authenticatortransport = [
      | `usb
      | `nfc
      | `ble
      | `cable
      | `internal
    ];
    let _authenticatortransport_of_yojson:
      Yojson.Basic.t => _authenticatortransport;
    let yojson_of__authenticatortransport:
      _authenticatortransport => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = _authenticatortransport;
  } = {
    type _authenticatortransport = [
      | `usb
      | `nfc
      | `ble
      | `cable
      | `internal
    ];
    let _authenticatortransport_of_yojson =
      fun
      | `String("usb") => `usb
      | `String("nfc") => `nfc
      | `String("ble") => `ble
      | `String("cable") => `cable
      | `String("internal") => `internal
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__authenticatortransport =
      fun
      | `usb => `String("usb")
      | `nfc => `String("nfc")
      | `ble => `String("ble")
      | `cable => `String("cable")
      | `internal => `String("internal");
    /* No description provided */
    [@deriving yojson]
    type t = _authenticatortransport;
  }
  and VirtualAuthenticatorOptions: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: AuthenticatorProtocol.t, /* No description provided */
      [@yojson.option] [@key "ctap2Version"]
      ctap2Version: option(Ctap2Version.t), /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
      [@key "transport"]
      transport: AuthenticatorTransport.t, /* No description provided */
      [@yojson.option] [@key "hasResidentKey"]
      hasResidentKey: option(bool), /* Defaults to false. */
      [@yojson.option] [@key "hasUserVerification"]
      hasUserVerification: option(bool), /* Defaults to false. */
      [@yojson.option] [@key "hasLargeBlob"]
      hasLargeBlob: option(bool), /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
      [@yojson.option] [@key "hasCredBlob"]
      hasCredBlob: option(bool), /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
      [@yojson.option] [@key "automaticPresenceSimulation"]
      automaticPresenceSimulation: option(bool), /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
      [@yojson.option] [@key "isUserVerified"]
      isUserVerified: option(bool) /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "protocol"]
      protocol: AuthenticatorProtocol.t, /* No description provided */
      [@yojson.option] [@key "ctap2Version"]
      ctap2Version: option(Ctap2Version.t), /* Defaults to ctap2_0. Ignored if |protocol| == u2f. */
      [@key "transport"]
      transport: AuthenticatorTransport.t, /* No description provided */
      [@yojson.option] [@key "hasResidentKey"]
      hasResidentKey: option(bool), /* Defaults to false. */
      [@yojson.option] [@key "hasUserVerification"]
      hasUserVerification: option(bool), /* Defaults to false. */
      [@yojson.option] [@key "hasLargeBlob"]
      hasLargeBlob: option(bool), /* If set to true, the authenticator will support the largeBlob extension.
https://w3c.github.io/webauthn#largeBlob
Defaults to false. */
      [@yojson.option] [@key "hasCredBlob"]
      hasCredBlob: option(bool), /* If set to true, the authenticator will support the credBlob extension.
https://fidoalliance.org/specs/fido-v2.1-rd-20201208/fido-client-to-authenticator-protocol-v2.1-rd-20201208.html#sctn-credBlob-extension
Defaults to false. */
      [@yojson.option] [@key "automaticPresenceSimulation"]
      automaticPresenceSimulation: option(bool), /* If set to true, tests of user presence will succeed immediately.
Otherwise, they will not be resolved. Defaults to true. */
      [@yojson.option] [@key "isUserVerified"]
      isUserVerified: option(bool) /* Sets whether User Verification succeeds or fails for an authenticator.
Defaults to false. */,
    };
  }
  and Credential: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "credentialId"]
      credentialId: string, /* No description provided */
      [@key "isResidentCredential"]
      isResidentCredential: bool, /* No description provided */
      [@yojson.option] [@key "rpId"]
      rpId: option(string), /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
      [@key "privateKey"]
      privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option] [@key "userHandle"]
      userHandle: option(string), /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
      [@key "signCount"]
      signCount: float, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
      [@yojson.option] [@key "largeBlob"]
      largeBlob: option(string) /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "credentialId"]
      credentialId: string, /* No description provided */
      [@key "isResidentCredential"]
      isResidentCredential: bool, /* No description provided */
      [@yojson.option] [@key "rpId"]
      rpId: option(string), /* Relying Party ID the credential is scoped to. Must be set when adding a
credential. */
      [@key "privateKey"]
      privateKey: string, /* The ECDSA P-256 private key in PKCS#8 format. (Encoded as a base64 string when passed over JSON) */
      [@yojson.option] [@key "userHandle"]
      userHandle: option(string), /* An opaque byte sequence with a maximum size of 64 bytes mapping the
credential to a specific user. (Encoded as a base64 string when passed over JSON) */
      [@key "signCount"]
      signCount: float, /* Signature counter. This is incremented by one for each successful
assertion.
See https://w3c.github.io/webauthn/#signature-counter */
      [@yojson.option] [@key "largeBlob"]
      largeBlob: option(string) /* The large blob associated with the credential.
See https://w3c.github.io/webauthn/#sctn-large-blob-extension (Encoded as a base64 string when passed over JSON) */,
    };
  };
}
and Media: {
  module rec PlayerId: {
    /* Players will get an ID that is unique within the agent context. */
    [@deriving yojson]
    type t = string;
  }
  and Timestamp: {
    /* No description provided */
    [@deriving yojson]
    type t = float;
  }
  and PlayerMessage: {
    type _playermessage_level = [ | `error | `warning | `info | `debug];
    let _playermessage_level_of_yojson: Yojson.Basic.t => _playermessage_level;
    let yojson_of__playermessage_level: _playermessage_level => Yojson.Basic.t;
    /* Have one type per entry in MediaLogRecord::Type
       Corresponds to kMessage */
    [@deriving yojson]
    type t = {
      [@key "level"]
      level: _playermessage_level, /* Keep in sync with MediaLogMessageLevel
We are currently keeping the message level 'error' separate from the
PlayerError type because right now they represent different things,
this one being a DVLOG(ERROR) style log message that gets printed
based on what log level is selected in the UI, and the other is a
representation of a media::PipelineStatus object. Soon however we're
going to be moving away from using PipelineStatus for errors and
introducing a new error type which should hopefully let us integrate
the error log level into the PlayerError type. */
      [@key "message"]
      message: string /* No description provided */,
    };
  }
  and PlayerProperty: {
    /* Corresponds to kMediaPropertyChange */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and PlayerEvent: {
    /* Corresponds to kMediaEventTriggered */
    [@deriving yojson]
    type t = {
      [@key "timestamp"]
      timestamp: Timestamp.t, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and PlayerError: {
    type _playererror_type = [ | `pipeline_error | `media_error];
    let _playererror_type_of_yojson: Yojson.Basic.t => _playererror_type;
    let yojson_of__playererror_type: _playererror_type => Yojson.Basic.t;
    /* Corresponds to kMediaError */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _playererror_type, /* No description provided */
      [@key "errorCode"]
      errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
    };
  };
} = {
  module rec PlayerId: {
    /* Players will get an ID that is unique within the agent context. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Players will get an ID that is unique within the agent context. */
    [@deriving yojson]
    type t = string;
  }
  and Timestamp: {
    /* No description provided */
    [@deriving yojson]
    type t = float;
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = float;
  }
  and PlayerMessage: {
    type _playermessage_level = [ | `error | `warning | `info | `debug];
    let _playermessage_level_of_yojson: Yojson.Basic.t => _playermessage_level;
    let yojson_of__playermessage_level: _playermessage_level => Yojson.Basic.t;
    /* Have one type per entry in MediaLogRecord::Type
       Corresponds to kMessage */
    [@deriving yojson]
    type t = {
      [@key "level"]
      level: _playermessage_level, /* Keep in sync with MediaLogMessageLevel
We are currently keeping the message level 'error' separate from the
PlayerError type because right now they represent different things,
this one being a DVLOG(ERROR) style log message that gets printed
based on what log level is selected in the UI, and the other is a
representation of a media::PipelineStatus object. Soon however we're
going to be moving away from using PipelineStatus for errors and
introducing a new error type which should hopefully let us integrate
the error log level into the PlayerError type. */
      [@key "message"]
      message: string /* No description provided */,
    };
  } = {
    type _playermessage_level = [ | `error | `warning | `info | `debug];
    let _playermessage_level_of_yojson =
      fun
      | `String("error") => `error
      | `String("warning") => `warning
      | `String("info") => `info
      | `String("debug") => `debug
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__playermessage_level =
      fun
      | `error => `String("error")
      | `warning => `String("warning")
      | `info => `String("info")
      | `debug => `String("debug");
    /* Have one type per entry in MediaLogRecord::Type
       Corresponds to kMessage */
    [@deriving yojson]
    type t = {
      [@key "level"]
      level: _playermessage_level, /* Keep in sync with MediaLogMessageLevel
We are currently keeping the message level 'error' separate from the
PlayerError type because right now they represent different things,
this one being a DVLOG(ERROR) style log message that gets printed
based on what log level is selected in the UI, and the other is a
representation of a media::PipelineStatus object. Soon however we're
going to be moving away from using PipelineStatus for errors and
introducing a new error type which should hopefully let us integrate
the error log level into the PlayerError type. */
      [@key "message"]
      message: string /* No description provided */,
    };
  }
  and PlayerProperty: {
    /* Corresponds to kMediaPropertyChange */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  } = {
    /* Corresponds to kMediaPropertyChange */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and PlayerEvent: {
    /* Corresponds to kMediaEventTriggered */
    [@deriving yojson]
    type t = {
      [@key "timestamp"]
      timestamp: Timestamp.t, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  } = {
    /* Corresponds to kMediaEventTriggered */
    [@deriving yojson]
    type t = {
      [@key "timestamp"]
      timestamp: Timestamp.t, /* No description provided */
      [@key "value"]
      value: string /* No description provided */,
    };
  }
  and PlayerError: {
    type _playererror_type = [ | `pipeline_error | `media_error];
    let _playererror_type_of_yojson: Yojson.Basic.t => _playererror_type;
    let yojson_of__playererror_type: _playererror_type => Yojson.Basic.t;
    /* Corresponds to kMediaError */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _playererror_type, /* No description provided */
      [@key "errorCode"]
      errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
    };
  } = {
    type _playererror_type = [ | `pipeline_error | `media_error];
    let _playererror_type_of_yojson =
      fun
      | `String("pipeline_error") => `pipeline_error
      | `String("media_error") => `media_error
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__playererror_type =
      fun
      | `pipeline_error => `String("pipeline_error")
      | `media_error => `String("media_error");
    /* Corresponds to kMediaError */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _playererror_type, /* No description provided */
      [@key "errorCode"]
      errorCode: string /* When this switches to using media::Status instead of PipelineStatus
we can remove "errorCode" and replace it with the fields from
a Status instance. This also seems like a duplicate of the error
level enum - there is a todo bug to have that level removed and
use this instead. (crbug.com/1068454) */,
    };
  };
}
and Console: {
  module rec ConsoleMessage: {
    type _consolemessage_source = [
      | `xml
      | `javascript
      | `network
      | `console_api
      | `storage
      | `appcache
      | `rendering
      | `security
      | `other
      | `deprecation
      | `worker
    ];
    let _consolemessage_source_of_yojson:
      Yojson.Basic.t => _consolemessage_source;
    let yojson_of__consolemessage_source:
      _consolemessage_source => Yojson.Basic.t;
    type _consolemessage_level = [
      | `log
      | `warning
      | `error
      | `debug
      | `info
    ];
    let _consolemessage_level_of_yojson:
      Yojson.Basic.t => _consolemessage_level;
    let yojson_of__consolemessage_level:
      _consolemessage_level => Yojson.Basic.t;
    /* Console message. */
    [@deriving yojson]
    type t = {
      [@key "source"]
      source: _consolemessage_source, /* Message source. */
      [@key "level"]
      level: _consolemessage_level, /* Message severity. */
      [@key "text"]
      text: string, /* Message text. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the message origin. */
      [@yojson.option] [@key "line"]
      line: option(float), /* Line number in the resource that generated this message (1-based). */
      [@yojson.option] [@key "column"]
      column: option(float) /* Column number in the resource that generated this message (1-based). */,
    };
  };
} = {
  module rec ConsoleMessage: {
    type _consolemessage_source = [
      | `xml
      | `javascript
      | `network
      | `console_api
      | `storage
      | `appcache
      | `rendering
      | `security
      | `other
      | `deprecation
      | `worker
    ];
    let _consolemessage_source_of_yojson:
      Yojson.Basic.t => _consolemessage_source;
    let yojson_of__consolemessage_source:
      _consolemessage_source => Yojson.Basic.t;
    type _consolemessage_level = [
      | `log
      | `warning
      | `error
      | `debug
      | `info
    ];
    let _consolemessage_level_of_yojson:
      Yojson.Basic.t => _consolemessage_level;
    let yojson_of__consolemessage_level:
      _consolemessage_level => Yojson.Basic.t;
    /* Console message. */
    [@deriving yojson]
    type t = {
      [@key "source"]
      source: _consolemessage_source, /* Message source. */
      [@key "level"]
      level: _consolemessage_level, /* Message severity. */
      [@key "text"]
      text: string, /* Message text. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the message origin. */
      [@yojson.option] [@key "line"]
      line: option(float), /* Line number in the resource that generated this message (1-based). */
      [@yojson.option] [@key "column"]
      column: option(float) /* Column number in the resource that generated this message (1-based). */,
    };
  } = {
    type _consolemessage_source = [
      | `xml
      | `javascript
      | `network
      | `console_api
      | `storage
      | `appcache
      | `rendering
      | `security
      | `other
      | `deprecation
      | `worker
    ];
    let _consolemessage_source_of_yojson =
      fun
      | `String("xml") => `xml
      | `String("javascript") => `javascript
      | `String("network") => `network
      | `String("console-api") => `console_api
      | `String("storage") => `storage
      | `String("appcache") => `appcache
      | `String("rendering") => `rendering
      | `String("security") => `security
      | `String("other") => `other
      | `String("deprecation") => `deprecation
      | `String("worker") => `worker
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__consolemessage_source =
      fun
      | `xml => `String("xml")
      | `javascript => `String("javascript")
      | `network => `String("network")
      | `console_api => `String("console-api")
      | `storage => `String("storage")
      | `appcache => `String("appcache")
      | `rendering => `String("rendering")
      | `security => `String("security")
      | `other => `String("other")
      | `deprecation => `String("deprecation")
      | `worker => `String("worker");
    type _consolemessage_level = [
      | `log
      | `warning
      | `error
      | `debug
      | `info
    ];
    let _consolemessage_level_of_yojson =
      fun
      | `String("log") => `log
      | `String("warning") => `warning
      | `String("error") => `error
      | `String("debug") => `debug
      | `String("info") => `info
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__consolemessage_level =
      fun
      | `log => `String("log")
      | `warning => `String("warning")
      | `error => `String("error")
      | `debug => `String("debug")
      | `info => `String("info");
    /* Console message. */
    [@deriving yojson]
    type t = {
      [@key "source"]
      source: _consolemessage_source, /* Message source. */
      [@key "level"]
      level: _consolemessage_level, /* Message severity. */
      [@key "text"]
      text: string, /* Message text. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the message origin. */
      [@yojson.option] [@key "line"]
      line: option(float), /* Line number in the resource that generated this message (1-based). */
      [@yojson.option] [@key "column"]
      column: option(float) /* Column number in the resource that generated this message (1-based). */,
    };
  };
}
and Debugger: {
  module rec BreakpointId: {
    /* Breakpoint identifier. */
    [@deriving yojson]
    type t = string;
  }
  and CallFrameId: {
    /* Call frame identifier. */
    [@deriving yojson]
    type t = string;
  }
  and Location: {
    /* Location in the source code. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float) /* Column number in the script (0-based). */,
    };
  }
  and ScriptPosition: {
    /* Location in the source code. */
    [@deriving yojson]
    type t = {
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  }
  and LocationRange: {
    /* Location range within one script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* No description provided */
      [@key "start"]
      start: ScriptPosition.t, /* No description provided */
      [@key "end"]
      end_: ScriptPosition.t /* No description provided */,
    };
  }
  and CallFrame: {
    /* JavaScript call frame. Array of call frames form the call stack. */
    [@deriving yojson]
    type t = {
      [@key "callFrameId"]
      callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
      [@key "functionName"]
      functionName: string, /* Name of the JavaScript function called on this call frame. */
      [@yojson.option] [@key "functionLocation"]
      functionLocation: option(Location.t), /* Location in the source code. */
      [@key "location"]
      location: Location.t, /* Location in the source code. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "scopeChain"]
      scopeChain: list(Scope.t), /* Scope chain for this call frame. */
      [@key "this"]
      this: Runtime.RemoteObject.t, /* `this` object for this call frame. */
      [@yojson.option] [@key "returnValue"]
      returnValue: option(Runtime.RemoteObject.t) /* The value being returned, if the function is at return point. */,
    };
  }
  and Scope: {
    type _scope_type = [
      | `global
      | `local
      | `with_
      | `closure
      | `catch
      | `block
      | `script
      | `eval
      | `module_
      | `wasm_expression_stack
    ];
    let _scope_type_of_yojson: Yojson.Basic.t => _scope_type;
    let yojson_of__scope_type: _scope_type => Yojson.Basic.t;
    /* Scope description. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _scope_type, /* Scope type. */
      [@key "object"]
      object_: Runtime.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
      [@yojson.option] [@key "name"]
      name: option(string), /* No description provided */
      [@yojson.option] [@key "startLocation"]
      startLocation: option(Location.t), /* Location in the source code where scope starts */
      [@yojson.option] [@key "endLocation"]
      endLocation: option(Location.t) /* Location in the source code where scope ends */,
    };
  }
  and SearchMatch: {
    /* Search match for resource. */
    [@deriving yojson]
    type t = {
      [@key "lineNumber"]
      lineNumber: float, /* Line number in resource content. */
      [@key "lineContent"]
      lineContent: string /* Line with match content. */,
    };
  }
  and BreakLocation: {
    type _breaklocation_type = [ | `debuggerStatement | `call | `return];
    let _breaklocation_type_of_yojson: Yojson.Basic.t => _breaklocation_type;
    let yojson_of__breaklocation_type: _breaklocation_type => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float), /* Column number in the script (0-based). */
      [@yojson.option] [@key "type"]
      type_: option(_breaklocation_type) /* No description provided */,
    };
  }
  and ScriptLanguage: {
    type _scriptlanguage = [ | `JavaScript | `WebAssembly];
    let _scriptlanguage_of_yojson: Yojson.Basic.t => _scriptlanguage;
    let yojson_of__scriptlanguage: _scriptlanguage => Yojson.Basic.t;
    /* Enum of possible script languages. */
    [@deriving yojson]
    type t = _scriptlanguage;
  }
  and DebugSymbols: {
    type _debugsymbols_type = [
      | `None
      | `SourceMap
      | `EmbeddedDWARF
      | `ExternalDWARF
    ];
    let _debugsymbols_type_of_yojson: Yojson.Basic.t => _debugsymbols_type;
    let yojson_of__debugsymbols_type: _debugsymbols_type => Yojson.Basic.t;
    /* Debug symbols available for a wasm script. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _debugsymbols_type, /* Type of the debug symbols. */
      [@yojson.option] [@key "externalURL"]
      externalURL: option(string) /* URL of the external symbol source. */,
    };
  };
} = {
  module rec BreakpointId: {
    /* Breakpoint identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Breakpoint identifier. */
    [@deriving yojson]
    type t = string;
  }
  and CallFrameId: {
    /* Call frame identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Call frame identifier. */
    [@deriving yojson]
    type t = string;
  }
  and Location: {
    /* Location in the source code. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float) /* Column number in the script (0-based). */,
    };
  } = {
    /* Location in the source code. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float) /* Column number in the script (0-based). */,
    };
  }
  and ScriptPosition: {
    /* Location in the source code. */
    [@deriving yojson]
    type t = {
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  } = {
    /* Location in the source code. */
    [@deriving yojson]
    type t = {
      [@key "lineNumber"]
      lineNumber: float, /* No description provided */
      [@key "columnNumber"]
      columnNumber: float /* No description provided */,
    };
  }
  and LocationRange: {
    /* Location range within one script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* No description provided */
      [@key "start"]
      start: ScriptPosition.t, /* No description provided */
      [@key "end"]
      end_: ScriptPosition.t /* No description provided */,
    };
  } = {
    /* Location range within one script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* No description provided */
      [@key "start"]
      start: ScriptPosition.t, /* No description provided */
      [@key "end"]
      end_: ScriptPosition.t /* No description provided */,
    };
  }
  and CallFrame: {
    /* JavaScript call frame. Array of call frames form the call stack. */
    [@deriving yojson]
    type t = {
      [@key "callFrameId"]
      callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
      [@key "functionName"]
      functionName: string, /* Name of the JavaScript function called on this call frame. */
      [@yojson.option] [@key "functionLocation"]
      functionLocation: option(Location.t), /* Location in the source code. */
      [@key "location"]
      location: Location.t, /* Location in the source code. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "scopeChain"]
      scopeChain: list(Scope.t), /* Scope chain for this call frame. */
      [@key "this"]
      this: Runtime.RemoteObject.t, /* `this` object for this call frame. */
      [@yojson.option] [@key "returnValue"]
      returnValue: option(Runtime.RemoteObject.t) /* The value being returned, if the function is at return point. */,
    };
  } = {
    /* JavaScript call frame. Array of call frames form the call stack. */
    [@deriving yojson]
    type t = {
      [@key "callFrameId"]
      callFrameId: CallFrameId.t, /* Call frame identifier. This identifier is only valid while the virtual machine is paused. */
      [@key "functionName"]
      functionName: string, /* Name of the JavaScript function called on this call frame. */
      [@yojson.option] [@key "functionLocation"]
      functionLocation: option(Location.t), /* Location in the source code. */
      [@key "location"]
      location: Location.t, /* Location in the source code. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "scopeChain"]
      scopeChain: list(Scope.t), /* Scope chain for this call frame. */
      [@key "this"]
      this: Runtime.RemoteObject.t, /* `this` object for this call frame. */
      [@yojson.option] [@key "returnValue"]
      returnValue: option(Runtime.RemoteObject.t) /* The value being returned, if the function is at return point. */,
    };
  }
  and Scope: {
    type _scope_type = [
      | `global
      | `local
      | `with_
      | `closure
      | `catch
      | `block
      | `script
      | `eval
      | `module_
      | `wasm_expression_stack
    ];
    let _scope_type_of_yojson: Yojson.Basic.t => _scope_type;
    let yojson_of__scope_type: _scope_type => Yojson.Basic.t;
    /* Scope description. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _scope_type, /* Scope type. */
      [@key "object"]
      object_: Runtime.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
      [@yojson.option] [@key "name"]
      name: option(string), /* No description provided */
      [@yojson.option] [@key "startLocation"]
      startLocation: option(Location.t), /* Location in the source code where scope starts */
      [@yojson.option] [@key "endLocation"]
      endLocation: option(Location.t) /* Location in the source code where scope ends */,
    };
  } = {
    type _scope_type = [
      | `global
      | `local
      | `with_
      | `closure
      | `catch
      | `block
      | `script
      | `eval
      | `module_
      | `wasm_expression_stack
    ];
    let _scope_type_of_yojson =
      fun
      | `String("global") => `global
      | `String("local") => `local
      | `String("with") => `with_
      | `String("closure") => `closure
      | `String("catch") => `catch
      | `String("block") => `block
      | `String("script") => `script
      | `String("eval") => `eval
      | `String("module") => `module_
      | `String("wasm-expression-stack") => `wasm_expression_stack
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__scope_type =
      fun
      | `global => `String("global")
      | `local => `String("local")
      | `with_ => `String("with")
      | `closure => `String("closure")
      | `catch => `String("catch")
      | `block => `String("block")
      | `script => `String("script")
      | `eval => `String("eval")
      | `module_ => `String("module")
      | `wasm_expression_stack => `String("wasm-expression-stack");
    /* Scope description. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _scope_type, /* Scope type. */
      [@key "object"]
      object_: Runtime.RemoteObject.t, /* Object representing the scope. For `global` and `with` scopes it represents the actual
object; for the rest of the scopes, it is artificial transient object enumerating scope
variables as its properties. */
      [@yojson.option] [@key "name"]
      name: option(string), /* No description provided */
      [@yojson.option] [@key "startLocation"]
      startLocation: option(Location.t), /* Location in the source code where scope starts */
      [@yojson.option] [@key "endLocation"]
      endLocation: option(Location.t) /* Location in the source code where scope ends */,
    };
  }
  and SearchMatch: {
    /* Search match for resource. */
    [@deriving yojson]
    type t = {
      [@key "lineNumber"]
      lineNumber: float, /* Line number in resource content. */
      [@key "lineContent"]
      lineContent: string /* Line with match content. */,
    };
  } = {
    /* Search match for resource. */
    [@deriving yojson]
    type t = {
      [@key "lineNumber"]
      lineNumber: float, /* Line number in resource content. */
      [@key "lineContent"]
      lineContent: string /* Line with match content. */,
    };
  }
  and BreakLocation: {
    type _breaklocation_type = [ | `debuggerStatement | `call | `return];
    let _breaklocation_type_of_yojson: Yojson.Basic.t => _breaklocation_type;
    let yojson_of__breaklocation_type: _breaklocation_type => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float), /* Column number in the script (0-based). */
      [@yojson.option] [@key "type"]
      type_: option(_breaklocation_type) /* No description provided */,
    };
  } = {
    type _breaklocation_type = [ | `debuggerStatement | `call | `return];
    let _breaklocation_type_of_yojson =
      fun
      | `String("debuggerStatement") => `debuggerStatement
      | `String("call") => `call
      | `String("return") => `return
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__breaklocation_type =
      fun
      | `debuggerStatement => `String("debuggerStatement")
      | `call => `String("call")
      | `return => `String("return");
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* Script identifier as reported in the `Debugger.scriptParsed`. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number in the script (0-based). */
      [@yojson.option] [@key "columnNumber"]
      columnNumber: option(float), /* Column number in the script (0-based). */
      [@yojson.option] [@key "type"]
      type_: option(_breaklocation_type) /* No description provided */,
    };
  }
  and ScriptLanguage: {
    type _scriptlanguage = [ | `JavaScript | `WebAssembly];
    let _scriptlanguage_of_yojson: Yojson.Basic.t => _scriptlanguage;
    let yojson_of__scriptlanguage: _scriptlanguage => Yojson.Basic.t;
    /* Enum of possible script languages. */
    [@deriving yojson]
    type t = _scriptlanguage;
  } = {
    type _scriptlanguage = [ | `JavaScript | `WebAssembly];
    let _scriptlanguage_of_yojson =
      fun
      | `String("JavaScript") => `JavaScript
      | `String("WebAssembly") => `WebAssembly
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__scriptlanguage =
      fun
      | `JavaScript => `String("JavaScript")
      | `WebAssembly => `String("WebAssembly");
    /* Enum of possible script languages. */
    [@deriving yojson]
    type t = _scriptlanguage;
  }
  and DebugSymbols: {
    type _debugsymbols_type = [
      | `None
      | `SourceMap
      | `EmbeddedDWARF
      | `ExternalDWARF
    ];
    let _debugsymbols_type_of_yojson: Yojson.Basic.t => _debugsymbols_type;
    let yojson_of__debugsymbols_type: _debugsymbols_type => Yojson.Basic.t;
    /* Debug symbols available for a wasm script. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _debugsymbols_type, /* Type of the debug symbols. */
      [@yojson.option] [@key "externalURL"]
      externalURL: option(string) /* URL of the external symbol source. */,
    };
  } = {
    type _debugsymbols_type = [
      | `None
      | `SourceMap
      | `EmbeddedDWARF
      | `ExternalDWARF
    ];
    let _debugsymbols_type_of_yojson =
      fun
      | `String("None") => `None
      | `String("SourceMap") => `SourceMap
      | `String("EmbeddedDWARF") => `EmbeddedDWARF
      | `String("ExternalDWARF") => `ExternalDWARF
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__debugsymbols_type =
      fun
      | `None => `String("None")
      | `SourceMap => `String("SourceMap")
      | `EmbeddedDWARF => `String("EmbeddedDWARF")
      | `ExternalDWARF => `String("ExternalDWARF");
    /* Debug symbols available for a wasm script. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _debugsymbols_type, /* Type of the debug symbols. */
      [@yojson.option] [@key "externalURL"]
      externalURL: option(string) /* URL of the external symbol source. */,
    };
  };
}
and HeapProfiler: {
  module rec HeapSnapshotObjectId: {
    /* Heap snapshot object id. */
    [@deriving yojson]
    type t = string;
  }
  and SamplingHeapProfileNode: {
    /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
    [@deriving yojson]
    type t = {
      [@key "callFrame"]
      callFrame: Runtime.CallFrame.t, /* Function location. */
      [@key "selfSize"]
      selfSize: float, /* Allocations size in bytes for the node excluding children. */
      [@key "id"]
      id: float, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
      [@key "children"]
      children: list(SamplingHeapProfileNode.t) /* Child nodes. */,
    };
  }
  and SamplingHeapProfileSample: {
    /* A single sample from a sampling profile. */
    [@deriving yojson]
    type t = {
      [@key "size"]
      size: float, /* Allocation size in bytes attributed to the sample. */
      [@key "nodeId"]
      nodeId: float, /* Id of the corresponding profile tree node. */
      [@key "ordinal"]
      ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
    };
  }
  and SamplingHeapProfile: {
    /* Sampling profile. */
    [@deriving yojson]
    type t = {
      [@key "head"]
      head: SamplingHeapProfileNode.t, /* No description provided */
      [@key "samples"]
      samples: list(SamplingHeapProfileSample.t) /* No description provided */,
    };
  };
} = {
  module rec HeapSnapshotObjectId: {
    /* Heap snapshot object id. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Heap snapshot object id. */
    [@deriving yojson]
    type t = string;
  }
  and SamplingHeapProfileNode: {
    /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
    [@deriving yojson]
    type t = {
      [@key "callFrame"]
      callFrame: Runtime.CallFrame.t, /* Function location. */
      [@key "selfSize"]
      selfSize: float, /* Allocations size in bytes for the node excluding children. */
      [@key "id"]
      id: float, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
      [@key "children"]
      children: list(SamplingHeapProfileNode.t) /* Child nodes. */,
    };
  } = {
    /* Sampling Heap Profile node. Holds callsite information, allocation statistics and child nodes. */
    [@deriving yojson]
    type t = {
      [@key "callFrame"]
      callFrame: Runtime.CallFrame.t, /* Function location. */
      [@key "selfSize"]
      selfSize: float, /* Allocations size in bytes for the node excluding children. */
      [@key "id"]
      id: float, /* Node id. Ids are unique across all profiles collected between startSampling and stopSampling. */
      [@key "children"]
      children: list(SamplingHeapProfileNode.t) /* Child nodes. */,
    };
  }
  and SamplingHeapProfileSample: {
    /* A single sample from a sampling profile. */
    [@deriving yojson]
    type t = {
      [@key "size"]
      size: float, /* Allocation size in bytes attributed to the sample. */
      [@key "nodeId"]
      nodeId: float, /* Id of the corresponding profile tree node. */
      [@key "ordinal"]
      ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
    };
  } = {
    /* A single sample from a sampling profile. */
    [@deriving yojson]
    type t = {
      [@key "size"]
      size: float, /* Allocation size in bytes attributed to the sample. */
      [@key "nodeId"]
      nodeId: float, /* Id of the corresponding profile tree node. */
      [@key "ordinal"]
      ordinal: float /* Time-ordered sample ordinal number. It is unique across all profiles retrieved
between startSampling and stopSampling. */,
    };
  }
  and SamplingHeapProfile: {
    /* Sampling profile. */
    [@deriving yojson]
    type t = {
      [@key "head"]
      head: SamplingHeapProfileNode.t, /* No description provided */
      [@key "samples"]
      samples: list(SamplingHeapProfileSample.t) /* No description provided */,
    };
  } = {
    /* Sampling profile. */
    [@deriving yojson]
    type t = {
      [@key "head"]
      head: SamplingHeapProfileNode.t, /* No description provided */
      [@key "samples"]
      samples: list(SamplingHeapProfileSample.t) /* No description provided */,
    };
  };
}
and Profiler: {
  module rec ProfileNode: {
    /* Profile node. Holds callsite information, execution statistics and child nodes. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: float, /* Unique id of the node. */
      [@key "callFrame"]
      callFrame: Runtime.CallFrame.t, /* Function location. */
      [@yojson.option] [@key "hitCount"]
      hitCount: option(float), /* Number of samples where this node was on top of the call stack. */
      [@yojson.option] [@key "children"]
      children: option(list(float)), /* Child node ids. */
      [@yojson.option] [@key "deoptReason"]
      deoptReason: option(string), /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
      [@yojson.option] [@key "positionTicks"]
      positionTicks: option(list(PositionTickInfo.t)) /* An array of source position ticks. */,
    };
  }
  and Profile: {
    /* Profile. */
    [@deriving yojson]
    type t = {
      [@key "nodes"]
      nodes: list(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
      [@key "startTime"]
      startTime: float, /* Profiling start timestamp in microseconds. */
      [@key "endTime"]
      endTime: float, /* Profiling end timestamp in microseconds. */
      [@yojson.option] [@key "samples"]
      samples: option(list(float)), /* Ids of samples top nodes. */
      [@yojson.option] [@key "timeDeltas"]
      timeDeltas: option(list(float)) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
    };
  }
  and PositionTickInfo: {
    /* Specifies a number of samples attributed to a certain source position. */
    [@deriving yojson]
    type t = {
      [@key "line"]
      line: float, /* Source line number (1-based). */
      [@key "ticks"]
      ticks: float /* Number of samples attributed to the source line. */,
    };
  }
  and CoverageRange: {
    /* Coverage data for a source range. */
    [@deriving yojson]
    type t = {
      [@key "startOffset"]
      startOffset: float, /* JavaScript script source offset for the range start. */
      [@key "endOffset"]
      endOffset: float, /* JavaScript script source offset for the range end. */
      [@key "count"]
      count: float /* Collected execution count of the source range. */,
    };
  }
  and FunctionCoverage: {
    /* Coverage data for a JavaScript function. */
    [@deriving yojson]
    type t = {
      [@key "functionName"]
      functionName: string, /* JavaScript function name. */
      [@key "ranges"]
      ranges: list(CoverageRange.t), /* Source ranges inside the function with coverage data. */
      [@key "isBlockCoverage"]
      isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
    };
  }
  and ScriptCoverage: {
    /* Coverage data for a JavaScript script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "functions"]
      functions: list(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
    };
  }
  and TypeObject: {
    /* Describes a type collected during runtime. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string /* Name of a type collected with type profiling. */,
    };
  }
  and TypeProfileEntry: {
    /* Source offset and types for a parameter or return value. */
    [@deriving yojson]
    type t = {
      [@key "offset"]
      offset: float, /* Source offset of the parameter or end of function for return values. */
      [@key "types"]
      types: list(TypeObject.t) /* The types for this parameter or return value. */,
    };
  }
  and ScriptTypeProfile: {
    /* Type profile data collected during runtime for a JavaScript script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "entries"]
      entries: list(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
    };
  };
} = {
  module rec ProfileNode: {
    /* Profile node. Holds callsite information, execution statistics and child nodes. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: float, /* Unique id of the node. */
      [@key "callFrame"]
      callFrame: Runtime.CallFrame.t, /* Function location. */
      [@yojson.option] [@key "hitCount"]
      hitCount: option(float), /* Number of samples where this node was on top of the call stack. */
      [@yojson.option] [@key "children"]
      children: option(list(float)), /* Child node ids. */
      [@yojson.option] [@key "deoptReason"]
      deoptReason: option(string), /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
      [@yojson.option] [@key "positionTicks"]
      positionTicks: option(list(PositionTickInfo.t)) /* An array of source position ticks. */,
    };
  } = {
    /* Profile node. Holds callsite information, execution statistics and child nodes. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: float, /* Unique id of the node. */
      [@key "callFrame"]
      callFrame: Runtime.CallFrame.t, /* Function location. */
      [@yojson.option] [@key "hitCount"]
      hitCount: option(float), /* Number of samples where this node was on top of the call stack. */
      [@yojson.option] [@key "children"]
      children: option(list(float)), /* Child node ids. */
      [@yojson.option] [@key "deoptReason"]
      deoptReason: option(string), /* The reason of being not optimized. The function may be deoptimized or marked as don't
optimize. */
      [@yojson.option] [@key "positionTicks"]
      positionTicks: option(list(PositionTickInfo.t)) /* An array of source position ticks. */,
    };
  }
  and Profile: {
    /* Profile. */
    [@deriving yojson]
    type t = {
      [@key "nodes"]
      nodes: list(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
      [@key "startTime"]
      startTime: float, /* Profiling start timestamp in microseconds. */
      [@key "endTime"]
      endTime: float, /* Profiling end timestamp in microseconds. */
      [@yojson.option] [@key "samples"]
      samples: option(list(float)), /* Ids of samples top nodes. */
      [@yojson.option] [@key "timeDeltas"]
      timeDeltas: option(list(float)) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
    };
  } = {
    /* Profile. */
    [@deriving yojson]
    type t = {
      [@key "nodes"]
      nodes: list(ProfileNode.t), /* The list of profile nodes. First item is the root node. */
      [@key "startTime"]
      startTime: float, /* Profiling start timestamp in microseconds. */
      [@key "endTime"]
      endTime: float, /* Profiling end timestamp in microseconds. */
      [@yojson.option] [@key "samples"]
      samples: option(list(float)), /* Ids of samples top nodes. */
      [@yojson.option] [@key "timeDeltas"]
      timeDeltas: option(list(float)) /* Time intervals between adjacent samples in microseconds. The first delta is relative to the
profile startTime. */,
    };
  }
  and PositionTickInfo: {
    /* Specifies a number of samples attributed to a certain source position. */
    [@deriving yojson]
    type t = {
      [@key "line"]
      line: float, /* Source line number (1-based). */
      [@key "ticks"]
      ticks: float /* Number of samples attributed to the source line. */,
    };
  } = {
    /* Specifies a number of samples attributed to a certain source position. */
    [@deriving yojson]
    type t = {
      [@key "line"]
      line: float, /* Source line number (1-based). */
      [@key "ticks"]
      ticks: float /* Number of samples attributed to the source line. */,
    };
  }
  and CoverageRange: {
    /* Coverage data for a source range. */
    [@deriving yojson]
    type t = {
      [@key "startOffset"]
      startOffset: float, /* JavaScript script source offset for the range start. */
      [@key "endOffset"]
      endOffset: float, /* JavaScript script source offset for the range end. */
      [@key "count"]
      count: float /* Collected execution count of the source range. */,
    };
  } = {
    /* Coverage data for a source range. */
    [@deriving yojson]
    type t = {
      [@key "startOffset"]
      startOffset: float, /* JavaScript script source offset for the range start. */
      [@key "endOffset"]
      endOffset: float, /* JavaScript script source offset for the range end. */
      [@key "count"]
      count: float /* Collected execution count of the source range. */,
    };
  }
  and FunctionCoverage: {
    /* Coverage data for a JavaScript function. */
    [@deriving yojson]
    type t = {
      [@key "functionName"]
      functionName: string, /* JavaScript function name. */
      [@key "ranges"]
      ranges: list(CoverageRange.t), /* Source ranges inside the function with coverage data. */
      [@key "isBlockCoverage"]
      isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
    };
  } = {
    /* Coverage data for a JavaScript function. */
    [@deriving yojson]
    type t = {
      [@key "functionName"]
      functionName: string, /* JavaScript function name. */
      [@key "ranges"]
      ranges: list(CoverageRange.t), /* Source ranges inside the function with coverage data. */
      [@key "isBlockCoverage"]
      isBlockCoverage: bool /* Whether coverage data for this function has block granularity. */,
    };
  }
  and ScriptCoverage: {
    /* Coverage data for a JavaScript script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "functions"]
      functions: list(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
    };
  } = {
    /* Coverage data for a JavaScript script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "functions"]
      functions: list(FunctionCoverage.t) /* Functions contained in the script that has coverage data. */,
    };
  }
  and TypeObject: {
    /* Describes a type collected during runtime. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string /* Name of a type collected with type profiling. */,
    };
  } = {
    /* Describes a type collected during runtime. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string /* Name of a type collected with type profiling. */,
    };
  }
  and TypeProfileEntry: {
    /* Source offset and types for a parameter or return value. */
    [@deriving yojson]
    type t = {
      [@key "offset"]
      offset: float, /* Source offset of the parameter or end of function for return values. */
      [@key "types"]
      types: list(TypeObject.t) /* The types for this parameter or return value. */,
    };
  } = {
    /* Source offset and types for a parameter or return value. */
    [@deriving yojson]
    type t = {
      [@key "offset"]
      offset: float, /* Source offset of the parameter or end of function for return values. */
      [@key "types"]
      types: list(TypeObject.t) /* The types for this parameter or return value. */,
    };
  }
  and ScriptTypeProfile: {
    /* Type profile data collected during runtime for a JavaScript script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "entries"]
      entries: list(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
    };
  } = {
    /* Type profile data collected during runtime for a JavaScript script. */
    [@deriving yojson]
    type t = {
      [@key "scriptId"]
      scriptId: Runtime.ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "entries"]
      entries: list(TypeProfileEntry.t) /* Type profile entries for parameters and return values of the functions in the script. */,
    };
  };
}
and Runtime: {
  module rec ScriptId: {
    /* Unique script identifier. */
    [@deriving yojson]
    type t = string;
  }
  and RemoteObjectId: {
    /* Unique object identifier. */
    [@deriving yojson]
    type t = string;
  }
  and UnserializableValue: {
    /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
       `-Infinity`, and bigint literals. */
    [@deriving yojson]
    type t = string;
  }
  and RemoteObject: {
    type _remoteobject_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `bigint
    ];
    let _remoteobject_type_of_yojson: Yojson.Basic.t => _remoteobject_type;
    let yojson_of__remoteobject_type: _remoteobject_type => Yojson.Basic.t;
    type _remoteobject_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _remoteobject_subtype_of_yojson:
      Yojson.Basic.t => _remoteobject_subtype;
    let yojson_of__remoteobject_subtype:
      _remoteobject_subtype => Yojson.Basic.t;
    /* Mirror object referencing original JavaScript object. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _remoteobject_type, /* Object type. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_remoteobject_subtype), /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
      [@yojson.option] [@key "className"]
      className: option(string), /* Object class (constructor) name. Specified for `object` type values only. */
      [@yojson.option] [@key "value"]
      value: option(string), /* Remote object value in case of primitive values or JSON values (if it was requested). */
      [@yojson.option] [@key "unserializableValue"]
      unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
      [@yojson.option] [@key "description"]
      description: option(string), /* String representation of the object. */
      [@yojson.option] [@key "objectId"]
      objectId: option(RemoteObjectId.t), /* Unique object identifier (for non-primitive values). */
      [@yojson.option] [@key "preview"]
      preview: option(ObjectPreview.t), /* Preview containing abbreviated property values. Specified for `object` type values only. */
      [@yojson.option] [@key "customPreview"]
      customPreview: option(CustomPreview.t) /* No description provided */,
    };
  }
  and CustomPreview: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "header"]
      header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
      [@yojson.option] [@key "bodyGetterId"]
      bodyGetterId: option(RemoteObjectId.t) /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
    };
  }
  and ObjectPreview: {
    type _objectpreview_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `bigint
    ];
    let _objectpreview_type_of_yojson: Yojson.Basic.t => _objectpreview_type;
    let yojson_of__objectpreview_type: _objectpreview_type => Yojson.Basic.t;
    type _objectpreview_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _objectpreview_subtype_of_yojson:
      Yojson.Basic.t => _objectpreview_subtype;
    let yojson_of__objectpreview_subtype:
      _objectpreview_subtype => Yojson.Basic.t;
    /* Object containing abbreviated remote object value. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _objectpreview_type, /* Object type. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_objectpreview_subtype), /* Object subtype hint. Specified for `object` type values only. */
      [@yojson.option] [@key "description"]
      description: option(string), /* String representation of the object. */
      [@key "overflow"]
      overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
      [@key "properties"]
      properties: list(PropertyPreview.t), /* List of the properties. */
      [@yojson.option] [@key "entries"]
      entries: option(list(EntryPreview.t)) /* List of the entries. Specified for `map` and `set` subtype values only. */,
    };
  }
  and PropertyPreview: {
    type _propertypreview_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `accessor
      | `bigint
    ];
    let _propertypreview_type_of_yojson:
      Yojson.Basic.t => _propertypreview_type;
    let yojson_of__propertypreview_type:
      _propertypreview_type => Yojson.Basic.t;
    type _propertypreview_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _propertypreview_subtype_of_yojson:
      Yojson.Basic.t => _propertypreview_subtype;
    let yojson_of__propertypreview_subtype:
      _propertypreview_subtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Property name. */
      [@key "type"]
      type_: _propertypreview_type, /* Object type. Accessor means that the property itself is an accessor property. */
      [@yojson.option] [@key "value"]
      value: option(string), /* User-friendly property value string. */
      [@yojson.option] [@key "valuePreview"]
      valuePreview: option(ObjectPreview.t), /* Nested value preview. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_propertypreview_subtype) /* Object subtype hint. Specified for `object` type values only. */,
    };
  }
  and EntryPreview: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "key"]
      key: option(ObjectPreview.t), /* Preview of the key. Specified for map-like collection entries. */
      [@key "value"]
      value: ObjectPreview.t /* Preview of the value. */,
    };
  }
  and PropertyDescriptor: {
    /* Object property descriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Property name or symbol description. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t), /* The value associated with the property. */
      [@yojson.option] [@key "writable"]
      writable: option(bool), /* True if the value associated with the property may be changed (data descriptors only). */
      [@yojson.option] [@key "get"]
      get: option(RemoteObject.t), /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
      [@yojson.option] [@key "set"]
      set: option(RemoteObject.t), /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
      [@key "configurable"]
      configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
      [@key "enumerable"]
      enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
      [@yojson.option] [@key "wasThrown"]
      wasThrown: option(bool), /* True if the result was thrown during the evaluation. */
      [@yojson.option] [@key "isOwn"]
      isOwn: option(bool), /* True if the property is owned for the object. */
      [@yojson.option] [@key "symbol"]
      symbol: option(RemoteObject.t) /* Property symbol object, if the property is of the `symbol` type. */,
    };
  }
  and InternalPropertyDescriptor: {
    /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Conventional property name. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t) /* The value associated with the property. */,
    };
  }
  and PrivatePropertyDescriptor: {
    /* Object private field descriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Private property name. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t), /* The value associated with the private property. */
      [@yojson.option] [@key "get"]
      get: option(RemoteObject.t), /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
      [@yojson.option] [@key "set"]
      set: option(RemoteObject.t) /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
    };
  }
  and CallArgument: {
    /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
       unserializable primitive value or neither of (for undefined) them should be specified. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "value"]
      value: option(string), /* Primitive value or serializable javascript object. */
      [@yojson.option] [@key "unserializableValue"]
      unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified. */
      [@yojson.option] [@key "objectId"]
      objectId: option(RemoteObjectId.t) /* Remote object handle. */,
    };
  }
  and ExecutionContextId: {
    /* Id of an execution context. */
    [@deriving yojson]
    type t = float;
  }
  and ExecutionContextDescription: {
    /* Description of an isolated world. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: ExecutionContextId.t, /* Unique id of the execution context. It can be used to specify in which execution context
script evaluation should be performed. */
      [@key "origin"]
      origin: string, /* Execution context origin. */
      [@key "name"]
      name: string, /* Human readable name describing given context. */
      [@key "uniqueId"]
      uniqueId: string, /* A system-unique execution context identifier. Unlike the id, this is unique across
multiple processes, so can be reliably used to identify specific context while backend
performs a cross-process navigation. */
      [@yojson.option] [@key "auxData"]
      auxData: option(assoc) /* Embedder-specific auxiliary data. */,
    };
  }
  and ExceptionDetails: {
    /* Detailed information about exception (or error) that was thrown during script compilation or
       execution. */
    [@deriving yojson]
    type t = {
      [@key "exceptionId"]
      exceptionId: float, /* Exception id. */
      [@key "text"]
      text: string, /* Exception text, which should be used together with exception object when available. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number of the exception location (0-based). */
      [@key "columnNumber"]
      columnNumber: float, /* Column number of the exception location (0-based). */
      [@yojson.option] [@key "scriptId"]
      scriptId: option(ScriptId.t), /* Script ID of the exception location. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the exception location, to be used when the script was not reported. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(StackTrace.t), /* JavaScript stack trace if available. */
      [@yojson.option] [@key "exception"]
      exception_: option(RemoteObject.t), /* Exception object if available. */
      [@yojson.option] [@key "executionContextId"]
      executionContextId: option(ExecutionContextId.t), /* Identifier of the context where exception happened. */
      [@yojson.option] [@key "exceptionMetaData"]
      exceptionMetaData: option(assoc) /* Dictionary with entries of meta data that the client associated
with this exception, such as information about associated network
requests, etc. */,
    };
  }
  and Timestamp: {
    /* Number of milliseconds since epoch. */
    [@deriving yojson]
    type t = float;
  }
  and TimeDelta: {
    /* Number of milliseconds. */
    [@deriving yojson]
    type t = float;
  }
  and CallFrame: {
    /* Stack entry for runtime errors and assertions. */
    [@deriving yojson]
    type t = {
      [@key "functionName"]
      functionName: string, /* JavaScript function name. */
      [@key "scriptId"]
      scriptId: ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "lineNumber"]
      lineNumber: float, /* JavaScript script line number (0-based). */
      [@key "columnNumber"]
      columnNumber: float /* JavaScript script column number (0-based). */,
    };
  }
  and StackTrace: {
    /* Call frames for assertions or error messages. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "description"]
      description: option(string), /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
      [@key "callFrames"]
      callFrames: list(CallFrame.t), /* JavaScript function name. */
      [@yojson.option] [@key "parent"]
      parent: option(StackTrace.t), /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
      [@yojson.option] [@key "parentId"]
      parentId: option(StackTraceId.t) /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
    };
  }
  and UniqueDebuggerId: {
    /* Unique identifier of current debugger. */
    [@deriving yojson]
    type t = string;
  }
  and StackTraceId: {
    /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
       allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: string, /* No description provided */
      [@yojson.option] [@key "debuggerId"]
      debuggerId: option(UniqueDebuggerId.t) /* No description provided */,
    };
  };
} = {
  module rec ScriptId: {
    /* Unique script identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique script identifier. */
    [@deriving yojson]
    type t = string;
  }
  and RemoteObjectId: {
    /* Unique object identifier. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique object identifier. */
    [@deriving yojson]
    type t = string;
  }
  and UnserializableValue: {
    /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
       `-Infinity`, and bigint literals. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Primitive value which cannot be JSON-stringified. Includes values `-0`, `NaN`, `Infinity`,
       `-Infinity`, and bigint literals. */
    [@deriving yojson]
    type t = string;
  }
  and RemoteObject: {
    type _remoteobject_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `bigint
    ];
    let _remoteobject_type_of_yojson: Yojson.Basic.t => _remoteobject_type;
    let yojson_of__remoteobject_type: _remoteobject_type => Yojson.Basic.t;
    type _remoteobject_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _remoteobject_subtype_of_yojson:
      Yojson.Basic.t => _remoteobject_subtype;
    let yojson_of__remoteobject_subtype:
      _remoteobject_subtype => Yojson.Basic.t;
    /* Mirror object referencing original JavaScript object. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _remoteobject_type, /* Object type. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_remoteobject_subtype), /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
      [@yojson.option] [@key "className"]
      className: option(string), /* Object class (constructor) name. Specified for `object` type values only. */
      [@yojson.option] [@key "value"]
      value: option(string), /* Remote object value in case of primitive values or JSON values (if it was requested). */
      [@yojson.option] [@key "unserializableValue"]
      unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
      [@yojson.option] [@key "description"]
      description: option(string), /* String representation of the object. */
      [@yojson.option] [@key "objectId"]
      objectId: option(RemoteObjectId.t), /* Unique object identifier (for non-primitive values). */
      [@yojson.option] [@key "preview"]
      preview: option(ObjectPreview.t), /* Preview containing abbreviated property values. Specified for `object` type values only. */
      [@yojson.option] [@key "customPreview"]
      customPreview: option(CustomPreview.t) /* No description provided */,
    };
  } = {
    type _remoteobject_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `bigint
    ];
    let _remoteobject_type_of_yojson =
      fun
      | `String("object") => `object_
      | `String("function") => `function_
      | `String("undefined") => `undefined
      | `String("string") => `string
      | `String("number") => `number
      | `String("boolean") => `boolean
      | `String("symbol") => `symbol
      | `String("bigint") => `bigint
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__remoteobject_type =
      fun
      | `object_ => `String("object")
      | `function_ => `String("function")
      | `undefined => `String("undefined")
      | `string => `String("string")
      | `number => `String("number")
      | `boolean => `String("boolean")
      | `symbol => `String("symbol")
      | `bigint => `String("bigint");
    type _remoteobject_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _remoteobject_subtype_of_yojson =
      fun
      | `String("array") => `array
      | `String("null") => `null
      | `String("node") => `node
      | `String("regexp") => `regexp
      | `String("date") => `date
      | `String("map") => `map
      | `String("set") => `set
      | `String("weakmap") => `weakmap
      | `String("weakset") => `weakset
      | `String("iterator") => `iterator
      | `String("generator") => `generator
      | `String("error") => `error
      | `String("proxy") => `proxy
      | `String("promise") => `promise
      | `String("typedarray") => `typedarray
      | `String("arraybuffer") => `arraybuffer
      | `String("dataview") => `dataview
      | `String("webassemblymemory") => `webassemblymemory
      | `String("wasmvalue") => `wasmvalue
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__remoteobject_subtype =
      fun
      | `array => `String("array")
      | `null => `String("null")
      | `node => `String("node")
      | `regexp => `String("regexp")
      | `date => `String("date")
      | `map => `String("map")
      | `set => `String("set")
      | `weakmap => `String("weakmap")
      | `weakset => `String("weakset")
      | `iterator => `String("iterator")
      | `generator => `String("generator")
      | `error => `String("error")
      | `proxy => `String("proxy")
      | `promise => `String("promise")
      | `typedarray => `String("typedarray")
      | `arraybuffer => `String("arraybuffer")
      | `dataview => `String("dataview")
      | `webassemblymemory => `String("webassemblymemory")
      | `wasmvalue => `String("wasmvalue");
    /* Mirror object referencing original JavaScript object. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _remoteobject_type, /* Object type. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_remoteobject_subtype), /* Object subtype hint. Specified for `object` type values only.
NOTE: If you change anything here, make sure to also update
`subtype` in `ObjectPreview` and `PropertyPreview` below. */
      [@yojson.option] [@key "className"]
      className: option(string), /* Object class (constructor) name. Specified for `object` type values only. */
      [@yojson.option] [@key "value"]
      value: option(string), /* Remote object value in case of primitive values or JSON values (if it was requested). */
      [@yojson.option] [@key "unserializableValue"]
      unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified does not have `value`, but gets this
property. */
      [@yojson.option] [@key "description"]
      description: option(string), /* String representation of the object. */
      [@yojson.option] [@key "objectId"]
      objectId: option(RemoteObjectId.t), /* Unique object identifier (for non-primitive values). */
      [@yojson.option] [@key "preview"]
      preview: option(ObjectPreview.t), /* Preview containing abbreviated property values. Specified for `object` type values only. */
      [@yojson.option] [@key "customPreview"]
      customPreview: option(CustomPreview.t) /* No description provided */,
    };
  }
  and CustomPreview: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "header"]
      header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
      [@yojson.option] [@key "bodyGetterId"]
      bodyGetterId: option(RemoteObjectId.t) /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "header"]
      header: string, /* The JSON-stringified result of formatter.header(object, config) call.
It contains json ML array that represents RemoteObject. */
      [@yojson.option] [@key "bodyGetterId"]
      bodyGetterId: option(RemoteObjectId.t) /* If formatter returns true as a result of formatter.hasBody call then bodyGetterId will
contain RemoteObjectId for the function that returns result of formatter.body(object, config) call.
The result value is json ML array. */,
    };
  }
  and ObjectPreview: {
    type _objectpreview_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `bigint
    ];
    let _objectpreview_type_of_yojson: Yojson.Basic.t => _objectpreview_type;
    let yojson_of__objectpreview_type: _objectpreview_type => Yojson.Basic.t;
    type _objectpreview_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _objectpreview_subtype_of_yojson:
      Yojson.Basic.t => _objectpreview_subtype;
    let yojson_of__objectpreview_subtype:
      _objectpreview_subtype => Yojson.Basic.t;
    /* Object containing abbreviated remote object value. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _objectpreview_type, /* Object type. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_objectpreview_subtype), /* Object subtype hint. Specified for `object` type values only. */
      [@yojson.option] [@key "description"]
      description: option(string), /* String representation of the object. */
      [@key "overflow"]
      overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
      [@key "properties"]
      properties: list(PropertyPreview.t), /* List of the properties. */
      [@yojson.option] [@key "entries"]
      entries: option(list(EntryPreview.t)) /* List of the entries. Specified for `map` and `set` subtype values only. */,
    };
  } = {
    type _objectpreview_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `bigint
    ];
    let _objectpreview_type_of_yojson =
      fun
      | `String("object") => `object_
      | `String("function") => `function_
      | `String("undefined") => `undefined
      | `String("string") => `string
      | `String("number") => `number
      | `String("boolean") => `boolean
      | `String("symbol") => `symbol
      | `String("bigint") => `bigint
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__objectpreview_type =
      fun
      | `object_ => `String("object")
      | `function_ => `String("function")
      | `undefined => `String("undefined")
      | `string => `String("string")
      | `number => `String("number")
      | `boolean => `String("boolean")
      | `symbol => `String("symbol")
      | `bigint => `String("bigint");
    type _objectpreview_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _objectpreview_subtype_of_yojson =
      fun
      | `String("array") => `array
      | `String("null") => `null
      | `String("node") => `node
      | `String("regexp") => `regexp
      | `String("date") => `date
      | `String("map") => `map
      | `String("set") => `set
      | `String("weakmap") => `weakmap
      | `String("weakset") => `weakset
      | `String("iterator") => `iterator
      | `String("generator") => `generator
      | `String("error") => `error
      | `String("proxy") => `proxy
      | `String("promise") => `promise
      | `String("typedarray") => `typedarray
      | `String("arraybuffer") => `arraybuffer
      | `String("dataview") => `dataview
      | `String("webassemblymemory") => `webassemblymemory
      | `String("wasmvalue") => `wasmvalue
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__objectpreview_subtype =
      fun
      | `array => `String("array")
      | `null => `String("null")
      | `node => `String("node")
      | `regexp => `String("regexp")
      | `date => `String("date")
      | `map => `String("map")
      | `set => `String("set")
      | `weakmap => `String("weakmap")
      | `weakset => `String("weakset")
      | `iterator => `String("iterator")
      | `generator => `String("generator")
      | `error => `String("error")
      | `proxy => `String("proxy")
      | `promise => `String("promise")
      | `typedarray => `String("typedarray")
      | `arraybuffer => `String("arraybuffer")
      | `dataview => `String("dataview")
      | `webassemblymemory => `String("webassemblymemory")
      | `wasmvalue => `String("wasmvalue");
    /* Object containing abbreviated remote object value. */
    [@deriving yojson]
    type t = {
      [@key "type"]
      type_: _objectpreview_type, /* Object type. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_objectpreview_subtype), /* Object subtype hint. Specified for `object` type values only. */
      [@yojson.option] [@key "description"]
      description: option(string), /* String representation of the object. */
      [@key "overflow"]
      overflow: bool, /* True iff some of the properties or entries of the original object did not fit. */
      [@key "properties"]
      properties: list(PropertyPreview.t), /* List of the properties. */
      [@yojson.option] [@key "entries"]
      entries: option(list(EntryPreview.t)) /* List of the entries. Specified for `map` and `set` subtype values only. */,
    };
  }
  and PropertyPreview: {
    type _propertypreview_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `accessor
      | `bigint
    ];
    let _propertypreview_type_of_yojson:
      Yojson.Basic.t => _propertypreview_type;
    let yojson_of__propertypreview_type:
      _propertypreview_type => Yojson.Basic.t;
    type _propertypreview_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _propertypreview_subtype_of_yojson:
      Yojson.Basic.t => _propertypreview_subtype;
    let yojson_of__propertypreview_subtype:
      _propertypreview_subtype => Yojson.Basic.t;
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Property name. */
      [@key "type"]
      type_: _propertypreview_type, /* Object type. Accessor means that the property itself is an accessor property. */
      [@yojson.option] [@key "value"]
      value: option(string), /* User-friendly property value string. */
      [@yojson.option] [@key "valuePreview"]
      valuePreview: option(ObjectPreview.t), /* Nested value preview. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_propertypreview_subtype) /* Object subtype hint. Specified for `object` type values only. */,
    };
  } = {
    type _propertypreview_type = [
      | `object_
      | `function_
      | `undefined
      | `string
      | `number
      | `boolean
      | `symbol
      | `accessor
      | `bigint
    ];
    let _propertypreview_type_of_yojson =
      fun
      | `String("object") => `object_
      | `String("function") => `function_
      | `String("undefined") => `undefined
      | `String("string") => `string
      | `String("number") => `number
      | `String("boolean") => `boolean
      | `String("symbol") => `symbol
      | `String("accessor") => `accessor
      | `String("bigint") => `bigint
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__propertypreview_type =
      fun
      | `object_ => `String("object")
      | `function_ => `String("function")
      | `undefined => `String("undefined")
      | `string => `String("string")
      | `number => `String("number")
      | `boolean => `String("boolean")
      | `symbol => `String("symbol")
      | `accessor => `String("accessor")
      | `bigint => `String("bigint");
    type _propertypreview_subtype = [
      | `array
      | `null
      | `node
      | `regexp
      | `date
      | `map
      | `set
      | `weakmap
      | `weakset
      | `iterator
      | `generator
      | `error
      | `proxy
      | `promise
      | `typedarray
      | `arraybuffer
      | `dataview
      | `webassemblymemory
      | `wasmvalue
    ];
    let _propertypreview_subtype_of_yojson =
      fun
      | `String("array") => `array
      | `String("null") => `null
      | `String("node") => `node
      | `String("regexp") => `regexp
      | `String("date") => `date
      | `String("map") => `map
      | `String("set") => `set
      | `String("weakmap") => `weakmap
      | `String("weakset") => `weakset
      | `String("iterator") => `iterator
      | `String("generator") => `generator
      | `String("error") => `error
      | `String("proxy") => `proxy
      | `String("promise") => `promise
      | `String("typedarray") => `typedarray
      | `String("arraybuffer") => `arraybuffer
      | `String("dataview") => `dataview
      | `String("webassemblymemory") => `webassemblymemory
      | `String("wasmvalue") => `wasmvalue
      | `String(s) => failwith("unknown enum: " ++ s)
      | _ => failwith("unknown enum type");
    let yojson_of__propertypreview_subtype =
      fun
      | `array => `String("array")
      | `null => `String("null")
      | `node => `String("node")
      | `regexp => `String("regexp")
      | `date => `String("date")
      | `map => `String("map")
      | `set => `String("set")
      | `weakmap => `String("weakmap")
      | `weakset => `String("weakset")
      | `iterator => `String("iterator")
      | `generator => `String("generator")
      | `error => `String("error")
      | `proxy => `String("proxy")
      | `promise => `String("promise")
      | `typedarray => `String("typedarray")
      | `arraybuffer => `String("arraybuffer")
      | `dataview => `String("dataview")
      | `webassemblymemory => `String("webassemblymemory")
      | `wasmvalue => `String("wasmvalue");
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Property name. */
      [@key "type"]
      type_: _propertypreview_type, /* Object type. Accessor means that the property itself is an accessor property. */
      [@yojson.option] [@key "value"]
      value: option(string), /* User-friendly property value string. */
      [@yojson.option] [@key "valuePreview"]
      valuePreview: option(ObjectPreview.t), /* Nested value preview. */
      [@yojson.option] [@key "subtype"]
      subtype: option(_propertypreview_subtype) /* Object subtype hint. Specified for `object` type values only. */,
    };
  }
  and EntryPreview: {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "key"]
      key: option(ObjectPreview.t), /* Preview of the key. Specified for map-like collection entries. */
      [@key "value"]
      value: ObjectPreview.t /* Preview of the value. */,
    };
  } = {
    /* No description provided */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "key"]
      key: option(ObjectPreview.t), /* Preview of the key. Specified for map-like collection entries. */
      [@key "value"]
      value: ObjectPreview.t /* Preview of the value. */,
    };
  }
  and PropertyDescriptor: {
    /* Object property descriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Property name or symbol description. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t), /* The value associated with the property. */
      [@yojson.option] [@key "writable"]
      writable: option(bool), /* True if the value associated with the property may be changed (data descriptors only). */
      [@yojson.option] [@key "get"]
      get: option(RemoteObject.t), /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
      [@yojson.option] [@key "set"]
      set: option(RemoteObject.t), /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
      [@key "configurable"]
      configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
      [@key "enumerable"]
      enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
      [@yojson.option] [@key "wasThrown"]
      wasThrown: option(bool), /* True if the result was thrown during the evaluation. */
      [@yojson.option] [@key "isOwn"]
      isOwn: option(bool), /* True if the property is owned for the object. */
      [@yojson.option] [@key "symbol"]
      symbol: option(RemoteObject.t) /* Property symbol object, if the property is of the `symbol` type. */,
    };
  } = {
    /* Object property descriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Property name or symbol description. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t), /* The value associated with the property. */
      [@yojson.option] [@key "writable"]
      writable: option(bool), /* True if the value associated with the property may be changed (data descriptors only). */
      [@yojson.option] [@key "get"]
      get: option(RemoteObject.t), /* A function which serves as a getter for the property, or `undefined` if there is no getter
(accessor descriptors only). */
      [@yojson.option] [@key "set"]
      set: option(RemoteObject.t), /* A function which serves as a setter for the property, or `undefined` if there is no setter
(accessor descriptors only). */
      [@key "configurable"]
      configurable: bool, /* True if the type of this property descriptor may be changed and if the property may be
deleted from the corresponding object. */
      [@key "enumerable"]
      enumerable: bool, /* True if this property shows up during enumeration of the properties on the corresponding
object. */
      [@yojson.option] [@key "wasThrown"]
      wasThrown: option(bool), /* True if the result was thrown during the evaluation. */
      [@yojson.option] [@key "isOwn"]
      isOwn: option(bool), /* True if the property is owned for the object. */
      [@yojson.option] [@key "symbol"]
      symbol: option(RemoteObject.t) /* Property symbol object, if the property is of the `symbol` type. */,
    };
  }
  and InternalPropertyDescriptor: {
    /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Conventional property name. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t) /* The value associated with the property. */,
    };
  } = {
    /* Object internal property descriptor. This property isn't normally visible in JavaScript code. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Conventional property name. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t) /* The value associated with the property. */,
    };
  }
  and PrivatePropertyDescriptor: {
    /* Object private field descriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Private property name. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t), /* The value associated with the private property. */
      [@yojson.option] [@key "get"]
      get: option(RemoteObject.t), /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
      [@yojson.option] [@key "set"]
      set: option(RemoteObject.t) /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
    };
  } = {
    /* Object private field descriptor. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Private property name. */
      [@yojson.option] [@key "value"]
      value: option(RemoteObject.t), /* The value associated with the private property. */
      [@yojson.option] [@key "get"]
      get: option(RemoteObject.t), /* A function which serves as a getter for the private property,
or `undefined` if there is no getter (accessor descriptors only). */
      [@yojson.option] [@key "set"]
      set: option(RemoteObject.t) /* A function which serves as a setter for the private property,
or `undefined` if there is no setter (accessor descriptors only). */,
    };
  }
  and CallArgument: {
    /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
       unserializable primitive value or neither of (for undefined) them should be specified. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "value"]
      value: option(string), /* Primitive value or serializable javascript object. */
      [@yojson.option] [@key "unserializableValue"]
      unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified. */
      [@yojson.option] [@key "objectId"]
      objectId: option(RemoteObjectId.t) /* Remote object handle. */,
    };
  } = {
    /* Represents function call argument. Either remote object id `objectId`, primitive `value`,
       unserializable primitive value or neither of (for undefined) them should be specified. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "value"]
      value: option(string), /* Primitive value or serializable javascript object. */
      [@yojson.option] [@key "unserializableValue"]
      unserializableValue: option(UnserializableValue.t), /* Primitive value which can not be JSON-stringified. */
      [@yojson.option] [@key "objectId"]
      objectId: option(RemoteObjectId.t) /* Remote object handle. */,
    };
  }
  and ExecutionContextId: {
    /* Id of an execution context. */
    [@deriving yojson]
    type t = float;
  } = {
    /* Id of an execution context. */
    [@deriving yojson]
    type t = float;
  }
  and ExecutionContextDescription: {
    /* Description of an isolated world. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: ExecutionContextId.t, /* Unique id of the execution context. It can be used to specify in which execution context
script evaluation should be performed. */
      [@key "origin"]
      origin: string, /* Execution context origin. */
      [@key "name"]
      name: string, /* Human readable name describing given context. */
      [@key "uniqueId"]
      uniqueId: string, /* A system-unique execution context identifier. Unlike the id, this is unique across
multiple processes, so can be reliably used to identify specific context while backend
performs a cross-process navigation. */
      [@yojson.option] [@key "auxData"]
      auxData: option(assoc) /* Embedder-specific auxiliary data. */,
    };
  } = {
    /* Description of an isolated world. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: ExecutionContextId.t, /* Unique id of the execution context. It can be used to specify in which execution context
script evaluation should be performed. */
      [@key "origin"]
      origin: string, /* Execution context origin. */
      [@key "name"]
      name: string, /* Human readable name describing given context. */
      [@key "uniqueId"]
      uniqueId: string, /* A system-unique execution context identifier. Unlike the id, this is unique across
multiple processes, so can be reliably used to identify specific context while backend
performs a cross-process navigation. */
      [@yojson.option] [@key "auxData"]
      auxData: option(assoc) /* Embedder-specific auxiliary data. */,
    };
  }
  and ExceptionDetails: {
    /* Detailed information about exception (or error) that was thrown during script compilation or
       execution. */
    [@deriving yojson]
    type t = {
      [@key "exceptionId"]
      exceptionId: float, /* Exception id. */
      [@key "text"]
      text: string, /* Exception text, which should be used together with exception object when available. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number of the exception location (0-based). */
      [@key "columnNumber"]
      columnNumber: float, /* Column number of the exception location (0-based). */
      [@yojson.option] [@key "scriptId"]
      scriptId: option(ScriptId.t), /* Script ID of the exception location. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the exception location, to be used when the script was not reported. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(StackTrace.t), /* JavaScript stack trace if available. */
      [@yojson.option] [@key "exception"]
      exception_: option(RemoteObject.t), /* Exception object if available. */
      [@yojson.option] [@key "executionContextId"]
      executionContextId: option(ExecutionContextId.t), /* Identifier of the context where exception happened. */
      [@yojson.option] [@key "exceptionMetaData"]
      exceptionMetaData: option(assoc) /* Dictionary with entries of meta data that the client associated
with this exception, such as information about associated network
requests, etc. */,
    };
  } = {
    /* Detailed information about exception (or error) that was thrown during script compilation or
       execution. */
    [@deriving yojson]
    type t = {
      [@key "exceptionId"]
      exceptionId: float, /* Exception id. */
      [@key "text"]
      text: string, /* Exception text, which should be used together with exception object when available. */
      [@key "lineNumber"]
      lineNumber: float, /* Line number of the exception location (0-based). */
      [@key "columnNumber"]
      columnNumber: float, /* Column number of the exception location (0-based). */
      [@yojson.option] [@key "scriptId"]
      scriptId: option(ScriptId.t), /* Script ID of the exception location. */
      [@yojson.option] [@key "url"]
      url: option(string), /* URL of the exception location, to be used when the script was not reported. */
      [@yojson.option] [@key "stackTrace"]
      stackTrace: option(StackTrace.t), /* JavaScript stack trace if available. */
      [@yojson.option] [@key "exception"]
      exception_: option(RemoteObject.t), /* Exception object if available. */
      [@yojson.option] [@key "executionContextId"]
      executionContextId: option(ExecutionContextId.t), /* Identifier of the context where exception happened. */
      [@yojson.option] [@key "exceptionMetaData"]
      exceptionMetaData: option(assoc) /* Dictionary with entries of meta data that the client associated
with this exception, such as information about associated network
requests, etc. */,
    };
  }
  and Timestamp: {
    /* Number of milliseconds since epoch. */
    [@deriving yojson]
    type t = float;
  } = {
    /* Number of milliseconds since epoch. */
    [@deriving yojson]
    type t = float;
  }
  and TimeDelta: {
    /* Number of milliseconds. */
    [@deriving yojson]
    type t = float;
  } = {
    /* Number of milliseconds. */
    [@deriving yojson]
    type t = float;
  }
  and CallFrame: {
    /* Stack entry for runtime errors and assertions. */
    [@deriving yojson]
    type t = {
      [@key "functionName"]
      functionName: string, /* JavaScript function name. */
      [@key "scriptId"]
      scriptId: ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "lineNumber"]
      lineNumber: float, /* JavaScript script line number (0-based). */
      [@key "columnNumber"]
      columnNumber: float /* JavaScript script column number (0-based). */,
    };
  } = {
    /* Stack entry for runtime errors and assertions. */
    [@deriving yojson]
    type t = {
      [@key "functionName"]
      functionName: string, /* JavaScript function name. */
      [@key "scriptId"]
      scriptId: ScriptId.t, /* JavaScript script id. */
      [@key "url"]
      url: string, /* JavaScript script name or url. */
      [@key "lineNumber"]
      lineNumber: float, /* JavaScript script line number (0-based). */
      [@key "columnNumber"]
      columnNumber: float /* JavaScript script column number (0-based). */,
    };
  }
  and StackTrace: {
    /* Call frames for assertions or error messages. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "description"]
      description: option(string), /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
      [@key "callFrames"]
      callFrames: list(CallFrame.t), /* JavaScript function name. */
      [@yojson.option] [@key "parent"]
      parent: option(StackTrace.t), /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
      [@yojson.option] [@key "parentId"]
      parentId: option(StackTraceId.t) /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
    };
  } = {
    /* Call frames for assertions or error messages. */
    [@deriving yojson]
    type t = {
      [@yojson.option] [@key "description"]
      description: option(string), /* String label of this stack trace. For async traces this may be a name of the function that
initiated the async call. */
      [@key "callFrames"]
      callFrames: list(CallFrame.t), /* JavaScript function name. */
      [@yojson.option] [@key "parent"]
      parent: option(StackTrace.t), /* Asynchronous JavaScript stack trace that preceded this stack, if available. */
      [@yojson.option] [@key "parentId"]
      parentId: option(StackTraceId.t) /* Asynchronous JavaScript stack trace that preceded this stack, if available. */,
    };
  }
  and UniqueDebuggerId: {
    /* Unique identifier of current debugger. */
    [@deriving yojson]
    type t = string;
  } = {
    /* Unique identifier of current debugger. */
    [@deriving yojson]
    type t = string;
  }
  and StackTraceId: {
    /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
       allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: string, /* No description provided */
      [@yojson.option] [@key "debuggerId"]
      debuggerId: option(UniqueDebuggerId.t) /* No description provided */,
    };
  } = {
    /* If `debuggerId` is set stack trace comes from another debugger and can be resolved there. This
       allows to track cross-debugger calls. See `Runtime.StackTrace` and `Debugger.paused` for usages. */
    [@deriving yojson]
    type t = {
      [@key "id"]
      id: string, /* No description provided */
      [@yojson.option] [@key "debuggerId"]
      debuggerId: option(UniqueDebuggerId.t) /* No description provided */,
    };
  };
}
and Schema: {
  module rec Domain: {
    /* Description of the protocol domain. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Domain name. */
      [@key "version"]
      version: string /* Domain version. */,
    };
  };
} = {
  module rec Domain: {
    /* Description of the protocol domain. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Domain name. */
      [@key "version"]
      version: string /* Domain version. */,
    };
  } = {
    /* Description of the protocol domain. */
    [@deriving yojson]
    type t = {
      [@key "name"]
      name: string, /* Domain name. */
      [@key "version"]
      version: string /* Domain version. */,
    };
  };
};
