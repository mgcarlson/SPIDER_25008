# generated from rosidl_generator_py/resource/_idl.py.em
# with input from spider_interfaces:srv/LocService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LocService_Request(type):
    """Metaclass of message 'LocService_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('spider_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'spider_interfaces.srv.LocService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__loc_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__loc_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__loc_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__loc_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__loc_service__request

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LocService_Request(metaclass=Metaclass_LocService_Request):
    """Message class 'LocService_Request'."""

    __slots__ = [
        '_move_type',
        '_move_amount',
        '_delta_angle',
    ]

    _fields_and_field_types = {
        'move_type': 'std_msgs/String',
        'move_amount': 'int64',
        'delta_angle': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import String
        self.move_type = kwargs.get('move_type', String())
        self.move_amount = kwargs.get('move_amount', int())
        self.delta_angle = kwargs.get('delta_angle', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.move_type != other.move_type:
            return False
        if self.move_amount != other.move_amount:
            return False
        if self.delta_angle != other.delta_angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def move_type(self):
        """Message field 'move_type'."""
        return self._move_type

    @move_type.setter
    def move_type(self, value):
        if __debug__:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'move_type' field must be a sub message of type 'String'"
        self._move_type = value

    @property
    def move_amount(self):
        """Message field 'move_amount'."""
        return self._move_amount

    @move_amount.setter
    def move_amount(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'move_amount' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'move_amount' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._move_amount = value

    @property
    def delta_angle(self):
        """Message field 'delta_angle'."""
        return self._delta_angle

    @delta_angle.setter
    def delta_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'delta_angle' field must be of type 'float'"
        self._delta_angle = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_LocService_Response(type):
    """Metaclass of message 'LocService_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('spider_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'spider_interfaces.srv.LocService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__loc_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__loc_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__loc_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__loc_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__loc_service__response

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LocService_Response(metaclass=Metaclass_LocService_Response):
    """Message class 'LocService_Response'."""

    __slots__ = [
        '_status',
    ]

    _fields_and_field_types = {
        'status': 'std_msgs/String',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import String
        self.status = kwargs.get('status', String())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'status' field must be a sub message of type 'String'"
        self._status = value


class Metaclass_LocService(type):
    """Metaclass of service 'LocService'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('spider_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'spider_interfaces.srv.LocService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__loc_service

            from spider_interfaces.srv import _loc_service
            if _loc_service.Metaclass_LocService_Request._TYPE_SUPPORT is None:
                _loc_service.Metaclass_LocService_Request.__import_type_support__()
            if _loc_service.Metaclass_LocService_Response._TYPE_SUPPORT is None:
                _loc_service.Metaclass_LocService_Response.__import_type_support__()


class LocService(metaclass=Metaclass_LocService):
    from spider_interfaces.srv._loc_service import LocService_Request as Request
    from spider_interfaces.srv._loc_service import LocService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
